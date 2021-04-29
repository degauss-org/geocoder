#!/usr/bin/Rscript

clean_address <- function(address) {
  cli::cli_alert_info('removing non-alphanumeric characters...\n')
  address <- stringr::str_replace_all(address, stringr::fixed('\\'), '')
  address <- stringr::str_replace_all(address, stringr::fixed('"'), '')
  address <- stringr::str_replace_all(address, "[^a-zA-Z0-9-]"," ")

  cli::cli_alert_info('removing excess whitespace...\n')
  address <- stringr::str_squish(address)
  return(address)
}

address_is_po_box <- function(address) {
  cli::cli_alert_info('flagging PO boxes...\n')
  po_regex_string <- c('\\bP(OST)*\\.*\\s*[O|0](FFICE)*\\.*\\sB[O|0]X')
  po_box <- purrr::map(address, ~ stringr::str_detect(.x, stringr::regex(po_regex_string, ignore_case=TRUE)))
  missing_address <- c(which(is.na(address)), which(d$address == ''))
  po_box[missing_address] <- FALSE
  return(purrr::map_lgl(po_box, any))
}

address_is_institutional <- function(address) {
  cli::cli_alert_info('flagging known Cincinnati foster & institutional addresses...\n')
  institutional_strings <- c('Ronald McDonald House',
                           '350 Erkenbrecher Ave',
                           '350 Erkenbrecher Avenue',
                           '350 Erkenbrecher Av',
                           '222 East Central Parkway',
                           '222 East Central Pkwy',
                           '222 East Central Pky',
                           '222 Central Parkway',
                           '222 Central Pkwy',
                           '222 Central Pky',
                           '3333 Burnet Ave',
                           '3333 Burnet Avenue',
                           '3333 Burnet Av')
  inst_foster_addr <- purrr::map(address, ~ stringr::str_detect(.x, stringr::coll(institutional_strings, ignore_case=TRUE)))
  missing_address <- c(which(is.na(address)), which(d$address == ''))
  inst_foster_addr[missing_address] <- FALSE
  return(purrr::map_lgl(inst_foster_addr, any))
}

address_is_nonaddress <- function(address) {
  cli::cli_alert_info('flagging non-address text and missing addresses...\n')
  non_address_strings <- c('verify',
                           'foreign',
                           'foreign country',
                           'unknown')
  non_address_text <- purrr::map(address, ~ stringr::str_detect(.x, stringr::coll(non_address_strings, ignore_case=TRUE)))
  non_address_text <- purrr::map_lgl(non_address_text, any)
  missing_address <- c(which(is.na(address)), which(d$address == ''))
  non_address_text[missing_address] <- TRUE # might remove second part after removing blank spaces?
  return(non_address_text)
}

setwd('/tmp')

dht::qlibrary(argparser)
dht::qlibrary(dplyr)
p <- argparser::arg_parser('offline geocoding, returns the input file with geocodes appended')
p <- argparser::add_argument(p,'file_name',help='name of input csv file')
p <- argparser::add_argument(p, '--score_threshold', default = 0.5, help = 'optional; defaults to 0.5')

args <- argparser::parse_args(p)

d <- readr::read_csv(args$file_name)
# d <- readr::read_csv('test/my_address_file.csv')
# d <- readr::read_csv('my_address_file.csv')
# d <- d[1:5,]

# must contain character column called address
if (! 'address' %in% names(d)) stop('no column called address found in the input file', call. = FALSE)
d$address <- clean_address(d$address)
d$po_box <- address_is_po_box(d$address)
d$cincy_inst_foster_addr <- address_is_institutional(d$address)
d$non_address_text <- address_is_nonaddress(d$address)

d_excluded_for_address <- dplyr::filter(d, cincy_inst_foster_addr | po_box | non_address_text)
d_for_geocoding <- dplyr::filter(d, !cincy_inst_foster_addr & !po_box & !non_address_text)

cli::cli_alert_info('now geocoding ... \n')
geocode <- function(addr_string) {
  stopifnot(class(addr_string)=='character')
  out <- system2('ruby',
                 args = c('/root/geocoder/geocode.rb', shQuote(addr_string)),
                 stderr=FALSE,stdout=TRUE) %>%
    jsonlite::fromJSON()
  # if geocoder returns nothing then system will return empty list
  if (length(out) == 0) out <- tibble(street = NA, zip = NA, city = NA, state = NA,
                                      lat = NA, lon = NA, score = NA, precision = NA)
  out
}

d_for_geocoding$geocodes <- mappp::mappp(d_for_geocoding$address,
                                      geocode,
                                      parallel = TRUE,
                                      cache = TRUE,
                                      cache.name = 'geocoding_cache')

# message('geocoding complete; now filtering to precise geocodes', '...\n')
# !!!!!! extract results, if a tie then take first returned result
d_for_geocoding <- d_for_geocoding %>%
  dplyr::mutate(geocodes = purrr::map(geocodes, ~ .x %>% purrr::map(unlist) %>% as_tibble())) %>%
  tidyr::unnest(cols = c(geocodes)) %>%
  dplyr::rename(matched_street = street,
                matched_city = city,
                matched_state = state,
                matched_zip = zip) %>%
  dplyr::select(-fips_county, -prenum, -number) %>%
  dplyr::mutate(precision = factor(precision,
                            levels = c('range', 'street', 'intersection', 'zip', 'city'),
                            ordered = TRUE)) %>%
  dplyr::arrange(desc(precision), score)

out_file <- dplyr::bind_rows(d_excluded_for_address, d_for_geocoding)

# out_file <- readr::read_csv('test/my_address_file_geocoded.csv')
# args <- list()
# args$score_threshold <- 0.5

out_file <- out_file %>%
  dplyr::mutate(geocode_result = dplyr::case_when(
    po_box ~ "po_box",
    cincy_inst_foster_addr ~ "cincy_inst_foster_addr",
    non_address_text ~ "non_address_text",
    !precision %in% c('street', 'range') | score < args$score_threshold ~ "imprecise_geocode",
    TRUE ~ "geocoded"),
    lat = ifelse(geocode_result == 'imprecise_geocode', NA, lat),
    lon = ifelse(geocode_result == 'imprecise_geocode', NA, lon)
  ) %>%
  select(-po_box, -cincy_inst_foster_addr, -non_address_text)
# note, just "PO" not "PO BOX" is not flagged as "po_box"

geocode_summary <- out_file %>%
  mutate(geocode_result = factor(geocode_result,
                                 levels = c('po_box', 'cincy_inst_foster_addr', 'non_address_text',
                                            'imprecise_geocode', 'geocoded'),
                                 ordered = TRUE)) %>%
  group_by(geocode_result) %>%
  tally() %>%
  rename(n_address = n) %>%
  mutate(`%` = round(n_address/sum(n_address)*100,1))

out.file.name <- paste0(gsub('.csv', '', args$file_name, fixed=TRUE),'_geocoded_v3.0.csv')
# out.file.name <- paste0(gsub('.csv','',"tmp/my_address_file.csv",fixed=TRUE),'_geocoded.csv')
readr::write_csv(out_file, out.file.name)

cli::cli_alert_success('FINISHED! output written to {out.file.name}')
n_geocoded <- geocode_summary$n_address[geocode_summary$geocode_result == 'geocoded']
n_total <- sum(geocode_summary$n_address)
pct_geocoded <- geocode_summary$`%`[geocode_summary$geocode_result == 'geocoded']
cli::cli_alert_info('{n_geocoded} of {n_total} ({pct_geocoded}%) addresses were successfully geocoded. See detailed summary below.')
print(geocode_summary)
