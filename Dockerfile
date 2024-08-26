FROM rocker/r-ver:4.4.1

# DeGAUSS container metadata
ENV degauss_name="geocoder"
ENV degauss_version="3.3.0"
ENV degauss_description="geocodes"
ENV degauss_argument="valid_geocode_score_threshold [default: 0.5]"

# add OCI labels based on environment variables too
LABEL "org.degauss.name"="${degauss_name}"
LABEL "org.degauss.version"="${degauss_version}"
LABEL "org.degauss.description"="${degauss_description}"
LABEL "org.degauss.argument"="${degauss_argument}"

ADD https://geomarker.s3.amazonaws.com/geocoder_2021.db /opt/geocoder.db
# COPY geocoder.db /opt/geocoder.db

RUN apt-get update && apt-get install -y \
    libssl-dev \
    libssh2-1-dev \
    libcurl4-openssl-dev \
    libxml2-dev \
    make \
    sqlite3 \
    libsqlite3-dev \
    flex \
    ruby-full \
    bison \
    gnupg \
    software-properties-common \
    pkg-config\
    && apt-get clean

RUN gem install sqlite3 json Text

RUN mkdir /app
WORKDIR /app

COPY Makefile.ruby .
COPY /src ./src
COPY /lib ./lib
COPY /gemspec ./gemspec

RUN make -f Makefile.ruby install \
    && gem install Geocoder-US-2.0.4.gem

WORKDIR /app

# install required version of renv
RUN R --quiet -e "install.packages('remotes', repos = c(CRAN = 'https://packagemanager.posit.co/cran/latest'))"
RUN R --quiet -e "remotes::install_github('rstudio/renv@v1.0.7')"

COPY renv.lock .
RUN R --quiet -e "renv::restore(repos = c(CRAN = 'https://packagemanager.posit.co/cran/latest'))"

COPY geocode.rb .
COPY entrypoint.R .

WORKDIR /tmp

ENTRYPOINT ["/app/entrypoint.R"]
