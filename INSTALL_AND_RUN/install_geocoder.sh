#!/bin/bash

# install SQLite 3 and development tools if not already present
sudo apt-get install sqlite3 libsqlite3-dev

# install ruby if not already present
sudo apt-get install ruby-full

# install rubyforge
sudo apt-get install ruby-rubyforge

# install the ruby gem package for SQLite3/Ruby
sudo gem install sqlite3

# install 'json' gem
sudo gem install json

# install the 'Text' gem
sudo gem install Text

# install the 'fastercsv' gem for tests
sudo gem install fastercsv

git clone https://github.com/cole-brokamp/geocoder.git
cd geocoder
sudo make install

# install geocoder gem
sudo gem install Geocoder-US-2.0.4.gem

# download the full TIGER/Line files (must be 2009 files!)
    # rerun with -c option if fails to continue download
cd ..
wget -r ftp://ftp2.census.gov/geo/tiger/TIGER2009

# move individual files into /opt/tiger
sudo mkdir /opt/tiger
find ftp2.census.gov/geo/tiger/TIGER2009/ -name "*" -type f | xargs -I files sudo mv files /opt/tiger
rm -r ftp2.census.gov

# import shapefile data into an SQLite database
# WARNING this takes like what seems forever!!!
cd geocoder
# beforehand I had to fix the script by changing
    # "SHP2SQLITE=../src/shp2sqlite/shp2sqlite" to "SHP2SQLITE=/src/shp2sqlite/shp2sqlite"
    # should be good now with my fork of the repo
sudo build/tiger_import /opt/tiger/geocoder.db /opt/tiger

# create ruby metaphones
sudo bin/rebuild_metaphones /opt/tiger/geocoder.db

# construct database indexes
    # need to chmod build_indexes first
chmod +x build/build_indexes
sudo build/build_indexes /opt/tiger/geocoder.db

# optionally cluster the database accorindg to indexes, making lookups faster
chmod +x build/rebuild_cluster
sudo build/rebuild_cluster /opt/tiger/geocoder.db

# test it
sudo ruby test/run.rb /opt/tiger/geocoder.db

# example to run within ruby
#   irb
# >> require 'geocoder/us'
# >> db = Geocoder::US::Database.new("/opt/tiger/geocoder.db")
# >> p db.geocode("1600 Pennsylvania Av, Washington DC")

# symmlink R script that relies on ruby script to home directory for usage
ln -s ~/geocoder/INSTALL_AND_RUN/geocode.R ~/geocode.R
