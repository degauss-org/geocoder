FROM ubuntu:14.04

MAINTAINER Cole Brokamp cole.brokamp@gmail.com

RUN useradd docker \
  && mkdir /home/docker \
  && chown docker:docker /home/docker \
  && addgroup docker staff

RUN apt-get update && apt-get install -y \
    libssl-dev \
    libssh2-1-dev \
    libcurl4-openssl-dev \
    libxml2-dev \
    git \
    make \
    wget \
    nano \
    sqlite3 \
    libsqlite3-dev \
    flex \
    ruby-full ruby-rubyforge \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

RUN wget https://colebrokamp-dropbox.s3.amazonaws.com/geocoder.db -P /opt

RUN echo "deb http://cran.rstudio.com/bin/linux/ubuntu trusty/" >> /etc/apt/sources.list \
  && apt-get update \
  && apt-get install r-base-core -y --force-yes \
  && apt-get clean \
  && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

RUN echo 'options(repos=c(CRAN = "https://cran.rstudio.com/"), download.file.method="wget")' >> /etc/R/Rprofile.site

RUN sudo su - -c "R -e \"install.packages(c('devtools','argparser'))\"" 
RUN sudo su - -c "R -e \"devtools::install_github('cole-brokamp/CB')\""

# need Ruby 3 for the gems
RUN apt-get update && apt-get install -y apt-file \
  && apt-file update \
  && apt-get install software-properties-common -y \
  && apt-add-repository ppa:brightbox/ruby-ng \
  && apt-get update \
  && apt-get install ruby2.2 ruby2.2-dev -y \
  && apt-get clean \
  && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

RUN gem install sqlite3 json Text

RUN mkdir /root/geocoder
COPY . /root/geocoder

RUN cd /root/geocoder \
    && make install \
    && gem install Geocoder-US-2.0.4.gem

ENTRYPOINT ["/root/geocoder/bin/geocode.R"]
