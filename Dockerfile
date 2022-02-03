FROM ubuntu:20.04

# DeGAUSS container metadata
ENV degauss_name="geocoder"
ENV degauss_version="3.1.0"
ENV degauss_description="geocode"
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
    nano \
    sqlite3 \
    libsqlite3-dev \
    flex \
    ruby-full \
    bison \
    gnupg \
    software-properties-common \
    && apt-get clean

RUN gem install sqlite3 json Text

RUN mkdir /root/geocoder
WORKDIR /root/geocoder

COPY Makefile.ruby .
COPY /src ./src
COPY /lib ./lib
COPY /gemspec ./gemspec

RUN cd /root/geocoder \
    && make -f Makefile.ruby install \
    && gem install Geocoder-US-2.0.4.gem

RUN apt-key adv --keyserver keyserver.ubuntu.com --recv-keys E298A3A825C0D65DFD57CBB651716619E084DAB9 \
    && add-apt-repository 'deb https://cloud.r-project.org/bin/linux/ubuntu focal-cran40/' \
    && apt update \
    && apt install -y r-base r-base-dev

# install required version of renv
RUN R --quiet -e "install.packages('remotes', repos = 'https://packagemanager.rstudio.com/all/__linux__/focal/latest')"
# make sure version matches what is used in the project: packageVersion('renv')
ENV RENV_VERSION 0.13.2
RUN R --quiet -e "remotes::install_github('rstudio/renv@${RENV_VERSION}')"

COPY renv.lock .
RUN R --quiet -e "renv::restore(repos = c(CRAN = 'https://packagemanager.rstudio.com/all/__linux__/focal/latest'))"

COPY geocode.R .
COPY geocode.rb .

ENTRYPOINT ["./geocode.R"]
