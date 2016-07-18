# CCHMC Geocoding Service

*Author*: Cole Brokamp  
*Questions*: cole.brokamp@cchmc.org  
*Last Update:* 14 July 2016  


### Background

This service estimates latitude and longitude coordinates from address strings.  For more information on how the program works and how you can implement it yourself, see https://github.com/cole-brokamp/geocoder

The program implements a Ruby interface to parse US street addresses and perform fuzzy lookup against an SQLite3 database. It will return the best matches found, with geographic coordinates using [address interpolation](https://en.wikipedia.org/wiki/Geocoding#Address_interpolation) based on 2015 [TIGER/Line files](https://en.wikipedia.org/wiki/Topologically_Integrated_Geographic_Encoding_and_Referencing).  It will attempt to fill in missing information, and it knows about standard and common non-standard postal abbreviations, ordinal versus cardinal numbers, and more. 

Perhaps the most useful feature to users at CCHMC is that the process is [HIPPA](http://www.hhs.gov/hipaa/for-professionals/privacy/laws-regulations/) compliant.  Geocoding is completed on a server inside the CCHMC network without using internet access. 


### Submission

#### File Format

Submissions must be a CSV file with a column named `address` that contains the complete address string. Other columns may be present and will be returned in the output file, but should be kept to a minimum to reduce file size.

An example input CSV file might look like:

	id,address
    001,"3333 Burnet Ave Cincinnati OH 45229"
    002,"660 Lincoln Avenue Cincinnati OH 45229"
    003,"2800 Winslow Avenue Cincinnati OH 45206

#### Tips for Getting the Best Results  
- omit apartment numbers or "second address line"
- plus4 zip codes are ignored
- capitalization does not affect results
- separate the different address components with a space
- abbreviations may be used (i.e. `St.` instead of `Street` or `OH` instead of `Ohio`)
- use arabic numerals instead of written numbers (i.e. `13` instead of `thirteen`)
- spelling should be as accurate as possible, but the program does complete "fuzzy matching" so an exact match is not necessary
- address strings with out of order items will likely return NA (i.e. `3333 Burnet Ave Cincinnati 45229 OH`)

### Output Format

A CSV file will be returned with the following fields. Any field that was not returned for the address will be filled with `NA`.

- `address`: address string input to the geocoder

- `lat`: estimated latitude coordinate

- `lon`: estimated longitude coordinate

- `number`:  The building number of the address. When a building number is not included in a range stored in the address database, the nearest known building number will be returned in its place.

- `street`: The name of the street found in the database that matches the address, given in a normalized form. 

- `street1`,`street2`: When an address is parsed as an intersection, the intersecting streets are returned as `street1` and `street2` in place of the `number` and `street` fields.

- `city`: The city matching the given address. In the US, this is typically determined from the matching ZIP code, so, for ZIP codes that cover more than one named place, the results may be different from what you expect, but will still be suitable for postal addressing.

- `state`: The two letter postal abbreviation of the state containing the matching address.

- `zip`: The five digit ZIP code of the matching address.

- `plus4`: The ZIP+4 extension parsed from the address, if any. This extension is not actually used in the geocoding process, but is returned for convenience.

- `fips_county`: The FIPS 6-4 code of the county containing the address.

- `prenum / sufnum`: If the building number has a non-numeric prefix or suffix, it will be returned here.

- `precision`: The qualitative precision of the geocode. The value will be one of `range`, `street`, `intersection`, `zip`, or `city`. See the next section for more details.

- `score`: The percentage of text match between the given address and the geocoded result, expressed as a number between 0 and 1. A higher score indicates a closer match. Note that each score is relative within a precision method (i.e. a `score` of `0.8` with a `precision` of `range` is *not* the same as a `score` of `0.8` with a `precision` of `street`).
    
#### Results Usable for Further Analysis

*We strongly recommend that only addresses that are geocoded with the precision method of `range` are used for further analysis or mapping.*  

Other method results are included in the output if `range` is not available, but should likely not be used as they may be widely inaccurate or imprecise. In order of decreasing accuracy, the following are the possible values for `precision` in the output file:

- `range`: interpolated based on address ranges from street segments
- `street`: center of the matched street
- `intersection`: intersection of two streets
- `zip`: centroid of the matched zip code
- `city`: centroid of the matched city

If results geocoded with methods other than `range` must be used, also consider using the `score` field in the output file to filter quality results.

### Citation

If you use any geocoding results in a scientific publication, please cite the use of this software.

**Example Citations:**

*Chicago:*  

Schuyler Erle, Cole Brokamp, Kate Chapman, Wank Sinatra, Tim Waters, mb16, Andrew Turner, Wade Simmons, Pete Warden, Michael Lippold, and Matt Kirk. 2016. geocoder: v2.1. Zenodo. doi: 10.5281/zenodo.56484. 

*BibTeX:*
```
@misc{schuyler_erle_2016_56484,
  author       = {Schuyler Erle and
                  Cole Brokamp and
                  Kate Chapman and
                  Wank Sinatra and
                  Tim Waters and
                  mb16 and
                  Andrew Turner and
                  Wade Simmons and
                  Pete Warden and
                  Michael Lippold and
                  Matt Kirk},
  title        = {geocoder: v2.1},
  month        = jun,
  year         = 2016,
  doi          = {10.5281/zenodo.56484},
  url          = {http://dx.doi.org/10.5281/zenodo.56484}
}
```
