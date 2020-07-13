//! @todo this could be initialised using a json property file

// register the element numbers, names and symbols
const std::map< ReactionNumber::Number, ReactionNumber::Entry >
ReactionNumber::mt_dictionary{

  { 1, ReactionNumber::Entry{ 1, "total", { "n,total" } } },
  { 2, ReactionNumber::Entry{ 2, "elastic", { "z,z0" } } },
  { 16, ReactionNumber::Entry{ 16, "z,2n", { "n,2n" },
                               { ParticleID( "n" ), ParticleID( "n" ) },
                               0 } },
  { 17, ReactionNumber::Entry{ 17, "z,3n", { "n,3n" },
                               { ParticleID( "n" ), ParticleID( "n" ),
                                 ParticleID( "n" ) },
                               0 } },
  { 37, ReactionNumber::Entry{ 37, "z,4n", { "n,4n" },
                               { ParticleID( "n" ), ParticleID( "n" ),
                                 ParticleID( "n" ), ParticleID( "n" ) },
                               0 } }
};

// register the alternatives (stored in lower case)
const std::map< std::string, ReactionNumber::Number >
ReactionNumber::conversion_dictionary = [] ( const auto& dictionary ) {

  std::map< std::string, ReactionNumber::Number > conversion;
  for ( const auto& [ number, entry ] : dictionary ) {

    conversion[ tolower( entry.name() ) ] = number;
    for ( const auto& alternative : entry.alternatives() ) {

      conversion[ tolower( alternative ) ] = number;
    }
  }
  return conversion;
}( ReactionNumber::mt_dictionary );
