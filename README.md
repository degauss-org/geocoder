# geocoder <a href='https://degauss.org'><img src='https://github.com/degauss-org/degauss_hex_logo/raw/main/PNG/degauss_hex.png' align='right' height='138.5' /></a>

[![](https://img.shields.io/github/v/release/degauss-org/geocoder?color=469FC2&label=version&sort=semver)](https://github.com/degauss-org/geocoder/releases)
[![container build status](https://github.com/degauss-org/geocoder/workflows/build-deploy-release/badge.svg)](https://github.com/degauss-org/geocoder/actions/workflows/build-deploy-release.yaml)

## Using

If `my_address_file.csv` is a file in the current working directory with an address column named `address`, then the [DeGAUSS command](https://degauss.org/using_degauss.html#DeGAUSS_Commands):

```sh
docker run --rm -v $PWD:/tmp ghcr.io/degauss-org/geocoder:3.3.0 my_address_file.csv
```

will produce `my_address_file_geocoder_3.3.0_score_threshold_0.5.csv` with added columns:

- **`matched_street`**, **`matched_city`**, **`matched_state`**, **`matched_zip`**: matched address componets (e.g., `matched_street` is the street the geocoder matched with the input address); can be used to investigate input address misspellings, typos, etc.
- **`precision`**: The method/precision of the geocode. The value will be one of:
  - `range`: interpolated based on address ranges from street segments
  - `street`:  center of the matched street
  - `intersection`: intersection of two streets
  - `zip`: centroid of the matched zip code
  - `city`: centroid of the matched city
- **`score`**: The percentage of text match between the given address and the geocoded result, expressed as a number between 0 and 1. A higher score indicates a closer match. Note that each score is relative within a precision method (i.e. a `score` of `0.8` with a `precision` of `range `is not the same as a `score` of `0.8` with a `precision` of `street`). 
- **`lat`** and **`lon`**: geocoded coordinates for matched address
- **`geocode_result`**: A character string summarizing the geocoding result. The value will be one of
  - `geocoded`: the address was geocoded with a `precision` of either `range` or `street` and a `score` of `0.5` or greater.
  - `imprecise_geocode`: the address was geocoded, but results were suppressed because the `precision` was `intersection`, `zip`, or `city` and/or the `score` was less than `0.5`.
  - `po_box`: the address was not geocoded because it is a PO Box
  - `cincy_inst_foster_addr`: the address was not geocoded because it is a known institutional address, not a residential address
  - `non_address_text`: the address was not geocoded because it was blank or listed as "foreign", "verify", or "unknown" 
	
### Optional Argument

- Geocodes with a resulting precision of `intersection`, `zip`, or `city` are returned with a missing `lat` and `lon` because they are likely too inaccurate and/or too imprecise to be used for further analysis.
- By default, `lat` and `lon` are also returned as missing if the `score` is less than `0.5` (regardless of the precision). 
- This threshold can be changed by including an optional argument in the docker call (e.g., `docker run --rm -v $PWD:/tmp degauss/geocoder:3.2.0 my_address_file.csv 0.6`).
- Supplying `all` instead of a numeric `score_threshold` returns all geocodes regardless of `score`, `precision`, or `po_box`, `cincy_inst_foster_addr`, and `non_address_text` filters. 

## Geomarker Methods

### Input address data formatting

- Other columns may be present, but it is recommended to only include `address` and an optional identifier column (e.g., `id`). Fewer columns will increase geocoding speed.
- Address data must be in one column called `address`. 
- Separate the different address components with a space
- Do not include apartment numbers or "second address line" (but its okay if you can't remove them)
- ZIP codes must be five digits (i.e. `32709`) and not "plus four" (i.e. `32709-0000`)
- Do not try to geocode addresses without a valid 5 digit zip code; this is used by the geocoder to complete its initial searches and if attempted, it will likely return incorrect matches
- Spelling should be as accurate as possible, but the program does complete "fuzzy matching" so an exact match is not necessary
- Capitalization does not affect results
- Abbreviations may be used (i.e. `St.` instead of `Street` or `OH` instead of `Ohio`)
- Use Arabic numerals instead of written numbers (i.e. `13` instead of `thirteen`)
- Address strings with out of order items could return NA (i.e. `3333 Burnet Ave Cincinnati 45229 OH`)

## Geomarker Data

- `geocoder.db` is a SQL database prepared following the instructions [here](https://degauss.org/manual_install.html) using 2021 TIGER/Line Street Range Address files from the Census
- For this container, it is hosted at `s3://geomarker/geocoder_2021.db`

## DeGAUSS Details

For detailed documentation on DeGAUSS, including general usage and installation, please see the [DeGAUSS homepage](https://degauss.org).
