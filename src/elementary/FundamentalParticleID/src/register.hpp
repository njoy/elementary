//! @todo this could be initialised using a json property file

// register the element numbers, names and symbols
static inline const std::map< Hash, Entry > particle_dictionary{

  { 0, Entry{ 0, "photon", "photon", { "g", "gamma", "x-ray" } } },
  { 1, Entry{ 1, "n", "neutron", {} } },
  { 1001, Entry{ 1001, "p", "proton", {} } }
};

// register the alternatives (stored in lower case)
static inline const std::map< std::string, Hash >
conversion_dictionary = [] ( const auto& dictionary ) {

  std::map< std::string, Hash > conversion;
  for ( const auto& [ hash, entry ] : dictionary ) {

    conversion[ tolower( entry.symbol() ) ] = hash;
    conversion[ tolower( entry.name() ) ] = hash;
    for ( const auto& alternative : entry.alternatives() ) {

      conversion[ tolower( alternative ) ] = hash;
    }
  }
  return conversion;
}( particle_dictionary );
