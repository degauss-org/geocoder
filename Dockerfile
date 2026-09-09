FROM rocker/r-ver:4.4

# DeGAUSS container metadata
ENV degauss_name="geocoder"
ENV degauss_version="3.4.2"
ENV degauss_description="geocodes"
ENV degauss_argument="valid_geocode_score_threshold [default: 0.5]"

# add OCI labels based on environment variables too
LABEL "org.degauss.name"="${degauss_name}"
LABEL "org.degauss.version"="${degauss_version}"
LABEL "org.degauss.description"="${degauss_description}"
LABEL "org.degauss.argument"="${degauss_argument}"

RUN apt-get update && apt-get install -y \
    curl \
    xz-utils \
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

RUN mkdir -p /opt && \
    curl -L https://dataverse.harvard.edu/api/access/datafile/13574277 \
      -o /tmp/geocoder.db.xz && \
    xz -dc /tmp/geocoder.db.xz > /opt/geocoder.db && \
    rm -f /tmp/geocoder.db.xz

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

RUN R --quiet -e "install.packages('renv')"

COPY renv.lock .
RUN R --quiet -e "renv::restore(repos = c(CRAN = sprintf('https://p3m.dev/cran/latest/bin/linux/manylinux_2_28-%s/%s', R.version['arch'], substr(getRversion(), 1, 3))))"

COPY geocode.rb .
COPY entrypoint.R .

WORKDIR /tmp

ENTRYPOINT ["/app/entrypoint.R"]
