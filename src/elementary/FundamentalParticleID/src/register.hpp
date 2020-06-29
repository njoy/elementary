//! @todo this could be initialised using a json property file

// register the element numbers, names and symbols
const std::map< FundamentalParticleID::Hash, FundamentalParticleID::Entry >
FundamentalParticleID::particle_dictionary{

  { 0, FundamentalParticleID::Entry{ 0, "photon", "photon",
                                     { "g", "gamma", "x-ray" } } },
  { 10, FundamentalParticleID::Entry{ 10, "n", "neutron" } },
  { 10010, FundamentalParticleID::Entry{ 10010, "p", "proton" } }
};

// register the alternatives (stored in lower case)
const std::map< std::string, FundamentalParticleID::Hash >
FundamentalParticleID::conversion_dictionary = [] ( const auto& dictionary ) {

  std::map< std::string, FundamentalParticleID::Hash > conversion;
  for ( const auto& [ hash, entry ] : dictionary ) {

    conversion[ tolower( entry.symbol() ) ] = hash;
    conversion[ tolower( entry.name() ) ] = hash;
    for ( const auto& alternative : entry.alternatives() ) {

      conversion[ tolower( alternative ) ] = hash;
    }
  }
  return conversion;
}( FundamentalParticleID::particle_dictionary );
