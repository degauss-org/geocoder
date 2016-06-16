FROM ubuntu:14.04

MAINTAINER Cole Brokamp cole.brokamp@gmail.com

WORKDIR "/root"

## Set a default user. Available via runtime flag `--user docker` 
## Add user to 'staff' group, granting them write privileges to /usr/local/lib/R/site.library
## User should also have & own a home directory (for rstudio or linked volumes to work properly). 
RUN useradd docker \
  && mkdir /home/docker \
  && chown docker:docker /home/docker \
  && addgroup docker staff

RUN apt-get update && apt-get upgrade -y

RUN apt-get update && apt-get install -y \
    libssl-dev libssh2-1-dev libcurl4-openssl-dev curl libxml2-dev git make wget

## Configure default locale, see https://github.com/rocker-org/rocker/issues/19
#RUN echo "en_US.UTF-8 UTF-8" >> /etc/locale.gen \
#  && locale-gen en_US.utf8 \
#  && /usr/sbin/update-locale LANG=en_US.UTF-8


RUN echo "deb http://cran.rstudio.com/bin/linux/ubuntu trusty/" >> /etc/apt/sources.list \
  && apt-get update \
  && apt-get install r-base-core -y --force-yes \
  && rm -rf /tmp/downloaded_packages/ /tmp/*.rds \
  && rm -rf /var/lib/apt/lists/*

RUN sudo su - -c "R -e \"install.packages('devtools', repos='https://cran.rstudio.com/')\"" \
  && sudo su - -c "R -e \"devtools::install_github('cole-brokamp/CB')\"" \
  && sudo su - -c "R -e \"install.packages('argparser', repos='https://cran.rstudio.com/')\""


RUN apt-get update && apt-get install -y \
    sqlite3 libsqlite3-dev \
    flex \
    ruby-full ruby-rubyforge

RUN gem install sqlite3 json Text
    
RUN git clone https://github.com/cole-brokamp/geocoder \
    && cd geocoder \
    && make install \
    && gem install Geocoder-US-2.0.4.gem
    
RUN ln -s ~/geocoder/bin/geocode.R ~/geocode.R

RUN git clone https://github.com/cole-brokamp/shell_scripts

RUN git clone https://github.com/cole-brokamp/bash_setup \
  && chmod +x ./bash_setup/install.sh \
  && ./bash_setup/install.sh
    
RUN wget https://colebrokamp-dropbox.s3.amazonaws.com/geocoder.db -P /opt

RUN apt-get install screen nano -y

CMD /bin/bash
