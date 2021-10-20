# geocoder <a href='https://degauss-org.github.io/DeGAUSS/'><img src='DeGAUSS_hex.png' align='right' height='138.5' /></a>

> A geocoder that relies on offline TIGER/Line data useful for geocoding private health information.

[![Docker Build Status](https://img.shields.io/docker/automated/degauss/geocoder)](https://hub.docker.com/repository/docker/degauss/geocoder/tags)
[![GitHub Latest Tag](https://img.shields.io/github/v/tag/degauss-org/geocoder)](https://github.com/degauss-org/geocoder/releases)

## News

Note that you can call an older version of the geocoder by specifying its version number in the docker ![tag](https://hub.docker.com/repository/docker/degauss/geocoder/tags?page=1&ordering=last_updated)

### Version 3.0

- the geocoder now uses **2019** TIGER/Line address range files
- performs some cleaning of address text (i.e., removes excess whitespace and non-alphanumerics)
- returns matched address components
- returns geocoding diagnostics and a summary printed to the console
- imprecise geocodes are filtered out of the output file
- output files names now include the version number

### Version 2.3

- suppress all startup messages from R
- import all columns as characters to prevent incidental changing of data through R

### Version 2.2

- initial release of DeGAUSS geocoder

## Geocoding

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
- Use arabic numerals instead of written numbers (i.e. `13` instead of `thirteen`)
- Address strings with out of order items could return NA (i.e. `3333 Burnet Ave Cincinnati 45229 OH`)

### DeGAUSS example call

If `my_address_file.csv` is a file in the current working directory with an address column named `address`, then

```sh
docker run --rm -v $PWD:/tmp degauss/geocoder:3.0.2 my_address_file.csv
```

will produce `my_address_file_geocoded_v3.0.2.csv` with added columns including `lat`, `lon`, and geocoding diagnostic information.

*Note: If you are using a Windows machine to run Docker, please review [this page](https://github.com/degauss-org/degauss-org.github.io/wiki/Microsoft-Windows-Troubleshooting-and-Workarounds) for Windows-specific changes that likely need to be made to successfully use DeGAUSS.  You can ignore this if you are using macOS or linux.*


### Interpreting geocoding results

The geocoder's output file includes the following columns: 

- `matched_street`, `matched_city`, `matched_state`, `matched_zip`: matched address componets (e.g., `matched_street` is the street the geocoder matched with the input address); can be used to investigate input address misspellings, typos, etc.


- `precision`: The qualitative precision of the geocode. The value will be one of:

    * `range`: interpolated based on address ranges from street segments

    * `street`:  center of the matched street

    * `intersection`: intersection of two streets

    * `zip`: centroid of the matched zip code

    * `city`: centroid of the matched city
      
    
- `score`: The percentage of text match between the given address and the geocoded result, expressed as a number between 0 and 1. A higher score indicates a closer match. Note that each score is relative within a precision method (i.e. a `score` of `0.8` with a `precision` of `range `is not the same as a `score` of `0.8` with a `precision` of `street`). 

- `lat` and `lon`: geocoded coordinates for matched address


- `geocode_result`: A qualitative summary of the geocoding result. The value will be one of

    * `po_box`: the address was not geocoded because it is a PO Box
    * `cincy_inst_foster_addr`: the address was not geocoded because it is a known institutional address, not a residential address
      
    * `non_address_text`: the address was not geocoded because it was blank or listed as "foreign", "verify", or "unknown" 
      
    * `imprecise_geocode`: the address was geocoded, but results were suppressed because the `precision` was `intersection`, `zip`, or `city` and/or the `score` was less than `0.5`.
      
    * `geocoded`: the address was geocoded with a `precision` of either `range` or `street` and a `score` of `0.5` or greater.
	
### Missing geocoding results

- Geocodes with a resulting precision of `intersection`, `zip`, or `city` are returned with a missing `lat` and `lon` because they are likely too inaccurate and/or too imprecise to be used for further analysis.
- By default, `lat` and `lon` are also returned as missing if the `score` is less than `0.5` (regardless of the precision). This threshold can be changed by including an optional argument in the docker call (`docker run --rm -v $PWD:/tmp degauss/geocoder:3.0 my_address_file.csv 0.4`).


## DeGAUSS details

For detailed documentation on DeGAUSS, including general usage and installation, please see the [DeGAUSS homepage](https://degauss.org). 

- [Docker installation instructions](https://github.com/degauss-org/degauss-org.github.io/wiki/Installing-Docker)
- [Manual geocoder installation instructions](https://github.com/degauss-org/degauss-org.github.io/wiki/Manual-Geocoder-Installation)
