# offline_geocoder

A geocoder that relies on offline TIGER/Line data useful for geocoding private health information.  Designed and tested only on Linux Ubuntu.

## Installation

### Requirements

Install required software:

	sudo apt-get install sqlite3 libsqlite3-dev
	sudo apt-get install flex
	sudo apt-get install ruby-full
	sudo apt-get install ruby-rubyforge
        
Install ruby gems:

	sudo gem install sqlite3
	sudo gem install json
	sudo gem install Text
        
Install R:

	sudo sh -c 'echo "deb http://cran.rstudio.com/bin/linux/ubuntu trusty/" >> /etc/apt/sources.list'
	sudo apt-get update
	sudo apt-get install r-base-core
        
    sudo sh -c 'echo "deb http://mirrors.ocf.berkeley.edu/ubuntu/ trusty-backports main restricted universe" >> /etc/apt/sources.list'
	sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys E084DAB9
	sudo apt-get update
	sudo apt-get install r-base-dev

Install R packages:

	sudo su - -c "R -e \"install.packages('devtools', repos='http://cran.rstudio.com/')\""
	sudo su - -c "R -e \"devtools::install_github('cole-brokamp/CB')\""
	sudo su - -c "R -e \"install.packages('argparser', repos='http://cran.rstudio.com/')\""

### Download and Install

Download the git repo to the home directory and then compile the SQLite3 extension and the Geocoder-US Ruby gem:
	
    cd ~
	git clone https://github.com/cole-brokamp/geocoder
    cd geocoder
    sudo make install
    sudo gem install Geocoder-US-2.0.4.gem

### TIGER/Line Database

The program relies on a sqlite3 database created from TIGER/Line files. Download the compiled database based on 2015 TIGER/Line files into the `geocoder` directory. If you wish to store the database elsewhere, make sure to update `geocode.rb` accordingly:

	wget https://colebrokamp-dropbox.s3.amazonaws.com/geocoder.db


Alternatively, build your own database (see the section below for details).


## Usage

For batch geocoding, run `geocoder/bin/geocode.R`, which relies on `Rscript`.  Don't forget to `chmod` this file and optionally, symmlink it somewhere or add it to your path.  Run the program without any arguments for help:

	  > ./geocode.R 
	usage: ./geocode.R [--] [--help] [--CAGIS] [--opts OPTS] file_name column_name

	offline geocoding, returns the input file with geocodes appended

	positional arguments:
	  file_name			name of input csv file
	  column_name			the name of the column in the csv file that contains the address strings

	flags:
	  -h, --help			show this help message and exit
	  -C, --CAGIS			try to geocode based on CAGIS files? [default: FALSE]


Test the the program out on some sample addresses:

	bin/geocode.R test_addresses.csv address

----------

## Building TIGER/Line Database

Although a compiled database created from 2015 TIGER/Line files is available for download, it is possible to create your own database using alternative years for example.

#### Download TIGER/Line files

	mkdir TIGER2015 && cd TIGER2015
	wget -nd -r -A.zip ftp://ftp2.census.gov/geo/tiger/TIGER2015/ADDR/
	wget -nd -r -A.zip ftp://ftp2.census.gov/geo/tiger/TIGER2015/FEATNAMES/
	wget -nd -r -A.zip ftp://ftp2.census.gov/geo/tiger/TIGER2015/EDGES/

If the download fails, rerun with `-c` option to continue where it left off.
    
#### Unpack each TIGER/Line ZIP into a temp directory and extract/transform/load to build database
	sudo build/tiger_import geocoder/geocoder.db TIGER2015

After making the database, it is safe to remove all of the TIGER files

	rm -r TIGER2015

#### Update database

Create ruby metaphones

	bin/rebuild_metaphones ~/geocoder/geocoder.db

Construct database indexes

	chmod +x build/build_indexes
	build/build_indexes ~/geocoder/geocoder.db

Cluster the database accorindg to indexes, making lookups faster

	chmod +x build/rebuild_cluster
	build/rebuild_cluster ~/geocoder/geocoder.db

