Gem::Specification.new do |s|
    s.name          = 'Geocoder-US'
    s.version       = "2.0.4"
    s.author        = "Schuyler Erle"
    s.email         = 'geocoder@entropyfree.com'
    s.description   = "US address geocoding based on TIGER/Line."
    s.summary       = "geocoder tool"
    s.homepage      = "http://geocoder.us/"
    s.files         = ["lib/geocoder/us.rb"] + Dir["lib/geocoder/us/*"]
    s.require_path  = "lib"
    s.add_dependency 'sqlite3-ruby', '~>1.3.1'
end
