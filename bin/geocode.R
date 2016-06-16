#!/usr/bin/Rscript

# requires the geocoder sql/ruby package 
# requires Rscript and R
# requires CB package

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
    tryCatch({
	    system(paste0('ruby ~/geocoder/bin/geocode.rb "',x,'"'))
	    out <- jsonlite::fromJSON('temp.json')
	    out <- as.data.frame(out)[1, ]
	    return(out)
	    },error=function(e)NULL)
	},fill=TRUE,pb=TRUE)
	
system('rm temp.json')
save(geocoded,'geocoded.RData')

geocoded$address_call <- addresses.unique

out.file <- merge(addresses,geocoded,by.x=address.col.name,by.y='address_call',all=TRUE)

out.file.name <- paste0(gsub('.csv','',in.file,fixed=TRUE),'_geocoded.csv')
write.csv(out.file,out.file.name,row.names=F)

print(paste0('FINISHED! output written to ',out.file.name))

# system(paste0('csv_to_shp ',out.file.name))

# print(paste0('FINISHED! output written to ',out.file.name,'and to folder ',paste0(gsub('.csv','',out.file.name,fixed=TRUE)),' as a shapefile'))


