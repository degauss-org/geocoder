#!/usr/bin/Rscript

dht::greeting(geomarker_name = 'geocoder', version = '3.1.0',
              description = 'returns geocoded coordinates based on input address strings')

setwd('/tmp')

dht::qlibrary(argparser)
dht::qlibrary(dplyr)
dht::qlibrary(digest)
dht::qlibrary(knitr)
# library(digest)
p <- argparser::arg_parser('offline geocoding, returns the input file with geocodes appended')
p <- argparser::add_argument(p,'file_name',help='name of input csv file')
p <- argparser::add_argument(p, '--score_threshold', default = 0.5, help = 'optional; defaults to 0.5')

args <- argparser::parse_args(p)

d <- readr::read_csv(args$file_name)
# d <- readr::read_csv('test/my_address_file.csv')
# d <- readr::read_csv('test/my_address_file_missing.csv')

## must contain character column called address
if (! 'address' %in% names(d)) stop('no column called address found in the input file', call. = FALSE)

## clean up addresses / classify 'bad' addresses
d$address <- dht::clean_address(d$address)
d$po_box <- dht::address_is_po_box(d$address)
d$cincy_inst_foster_addr <- dht::address_is_institutional(d$address)
d$non_address_text <- dht::address_is_nonaddress(d$address)

## exclude 'bad' addresses from geocoding
d_excluded_for_address <- dplyr::filter(d, cincy_inst_foster_addr | po_box | non_address_text)
d_for_geocoding <- dplyr::filter(d, !cincy_inst_foster_addr & !po_box & !non_address_text)

out_template <- tibble(street = NA, zip = NA, city = NA, state = NA,
                       lat = NA, lon = NA, score = NA, precision = NA,
                       fips_county = NA, number = NA, prenum = NA)

## geocode
cli::cli_alert_info('now geocoding ...', wrap = TRUE)
geocode <- function(addr_string) {
  stopifnot(class(addr_string)=='character')

  out <- system2('ruby',
                 args = c('/root/geocoder/geocode.rb', shQuote(addr_string)),
                 stderr=FALSE, stdout=TRUE)

  if (length(out) > 0) {
    out <- out %>%
      jsonlite::fromJSON()

    out <-
      bind_rows(out_template, out) %>%
      .[2,]
  } else {
    out <- out_template
  }

  out
}

if (nrow(d_for_geocoding) > 0) {
  d_for_geocoding$geocodes <- mappp::mappp(d_for_geocoding$address,
                                           geocode,
                                           parallel = TRUE,
                                           cache = TRUE,
                                           cache.name = 'geocoding_cache')

  ## extract results, if a tie then take first returned result
  d_for_geocoding <- d_for_geocoding %>%
    dplyr::mutate(row_index = 1:nrow(d_for_geocoding),
                  geocodes = purrr::map(geocodes, ~ .x %>% purrr::map(unlist) %>% as_tibble())) %>%
    tidyr::unnest(cols = c(geocodes)) %>%
    dplyr::group_by(row_index) %>%
    dplyr::slice(1) %>%
    dplyr::ungroup() %>%
    dplyr::rename(matched_street = street,
                  matched_city = city,
                  matched_state = state,
                  matched_zip = zip) %>%
    dplyr::select(-fips_county, -prenum, -number, -row_index) %>%
    dplyr::mutate(precision = factor(precision,
                                     levels = c('range', 'street', 'intersection', 'zip', 'city'),
                                     ordered = TRUE)) %>%
    dplyr::arrange(desc(precision), score)
} else {
  d_excluded_for_address <-
    bind_rows(d_excluded_for_address, out_template) %>%
    .[1:nrow(.)-1,]
}

## clean up 'bad' address columns / filter to precise geocodes
cli::cli_alert_info('geocoding complete; now filtering to precise geocodes...', wrap = TRUE)
out_file <- dplyr::bind_rows(d_excluded_for_address, d_for_geocoding) %>%
  dplyr::mutate(geocode_result = dplyr::case_when(
    po_box ~ "po_box",
    cincy_inst_foster_addr ~ "cincy_inst_foster_addr",
    non_address_text ~ "non_address_text",
    !precision %in% c('street', 'range') | score < args$score_threshold ~ "imprecise_geocode",
    TRUE ~ "geocoded"),
    lat = ifelse(geocode_result == 'imprecise_geocode', NA, lat),
    lon = ifelse(geocode_result == 'imprecise_geocode', NA, lon)
  ) %>%
  select(-po_box, -cincy_inst_foster_addr, -non_address_text) # note, just "PO" not "PO BOX" is not flagged as "po_box"

## summarize geocoding results
geocode_summary <- out_file %>%
  mutate(geocode_result = factor(geocode_result,
                                 levels = c('po_box', 'cincy_inst_foster_addr', 'non_address_text',
                                            'imprecise_geocode', 'geocoded'),
                                 ordered = TRUE)) %>%
  group_by(geocode_result) %>%
  tally() %>%
  mutate(`%` = round(n/sum(n)*100,1),
         `n (%)` = glue::glue('{n} ({`%`})'))

## write out file
out.file.name <- paste0(gsub('.csv', '', args$file_name, fixed=TRUE),'_geocoded_v3.1.0.csv')
readr::write_csv(out_file, out.file.name)
cli::cli_alert_success('FINISHED! output written to {out.file.name}', wrap = TRUE)

## print geocoding results summary to console
n_geocoded <- geocode_summary$n[geocode_summary$geocode_result == 'geocoded']
n_total <- sum(geocode_summary$n)
pct_geocoded <- geocode_summary$`%`[geocode_summary$geocode_result == 'geocoded']
cli::cli_alert_info('{n_geocoded} of {n_total} ({pct_geocoded}%) addresses were successfully geocoded. See detailed summary below.',
                    wrap = TRUE)
knitr::kable(geocode_summary %>% dplyr::select(geocode_result, `n (%)`))
