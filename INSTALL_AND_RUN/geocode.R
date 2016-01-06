#!/usr/bin/Rscript

# requires the geocoder sql/ruby package 
# requires Rscript and R
# requires CB package

args <- commandArgs(TRUE)

if(length(args) == 0) {
    cat("geocodes a CSV file of addresses; returns same file but with geocode information appended\n")
    cat("usage: ./geocode.R \"name_of_input_file.csv\" \"name_of_address_column\"\n")
    q()
    }

in.file <- args[1]
address.col.name <- args[2]
addresses <- read.csv(in.file,stringsAsFactors=FALSE)

geocoded <- CB::CBapply(addresses[ ,address.col.name],function(x) {
	print(paste0('geocoding ',tail(which(addresses[ ,address.col.name]==x),1),' of ',nrow(addresses)))
	system(paste0('ruby ~/geocoder/INSTALL_AND_RUN/geocode.rb "',x,'"'))
	out <- jsonlite::fromJSON('temp.json')
	return(as.data.frame(out)[1, ])	
	},fill=TRUE)

save(geocoded,file='geocoded.RData')

system('rm temp.json')
out.file <- cbind(addresses,geocoded)
out.file.name <- paste0(gsub('.csv','',in.file,fixed=TRUE),'_geocoded.csv')
write.csv(out.file,out.file.name)
print(paste0('FINISHED! output written to ',out.file.name))


