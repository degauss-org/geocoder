#!/usr/bin/Rscript

setwd('/tmp')

library(argparser)
p <- arg_parser('offline geocoding, returns the input file with geocodes appended')
p <- add_argument(p,'file_name',help='name of input csv file')
p <- add_argument(p,'column_name',help='the name of the column in the csv file that contains the address strings')
# p <- add_argument(p,'--CAGIS',help='try to geocode based on CAGIS files?',default=FALSE,flag=TRUE)
args <- parse_args(p)

in.file <- args$file_name
address.col.name <- args$column_name

addresses <- read.csv(in.file,stringsAsFactors=FALSE)

addresses.unique <- unique(addresses[ ,address.col.name])

geocoded <- CB::cb_apply(addresses.unique,function(x) {
        tf <- tempfile()
	    system(paste0('ruby /root/geocoder/bin/geocode.rb "',x,'"',' "',tf,'"'))
	    out <- jsonlite::fromJSON(tf)
	    out <- as.data.frame(out)[1, ]},
	fill=TRUE,pb=TRUE,parallel=TRUE,cache=TRUE,error.na=TRUE,.id=NULL)

geocoded$address_call <- addresses.unique

out.file <- merge(addresses,geocoded,by.x=address.col.name,by.y='address_call',all=TRUE)

# delete the error-prone FIPS county column
out.file$fips_county <- NULL

out.file.name <- paste0(gsub('.csv','',in.file,fixed=TRUE),'_geocoded.csv')
write.csv(out.file,out.file.name,row.names=F)

message('FINISHED! output written to ',out.file.name)