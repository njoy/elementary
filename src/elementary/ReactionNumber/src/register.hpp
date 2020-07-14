//! @todo this could be initialised using a json property file

// register the mt numbers, names, etc.
const std::map< ReactionNumber::Number, ReactionNumber::Entry >
ReactionNumber::mt_dictionary{

  { 1, ReactionNumber::Entry{ 1, "total", { "n,total" } } },
  { 2, ReactionNumber::Entry{ 2, "elastic", { "z,z0" } } },
  //{ 4, ReactionNumber::Entry{ 4, "inelastic", { "z,n", "n,n'", "z,n'" },
  //                            { ParticleID( "n" ) } } },
  { 11, ReactionNumber::Entry{ 11, "z,2nd", { "n,2nd" },
                               { ParticleID( "n" ), ParticleID( "n" ),
                                 ParticleID( "h2" ) } } },
  { 16, ReactionNumber::Entry{ 16, "z,2n", { "n,2n" },
                               { ParticleID( "n" ), ParticleID( "n" ) } } },
  { 17, ReactionNumber::Entry{ 17, "z,3n", { "n,3n" },
                               { ParticleID( "n" ), ParticleID( "n" ),
                                 ParticleID( "n" ) } } },
  //{ 18, ReactionNumber::Entry{ 18, "fission", { "n,fission", "z,fission" } } },
  { 37, ReactionNumber::Entry{ 37, "z,4n", { "n,4n" },
                               { ParticleID( "n" ), ParticleID( "n" ),
                                 ParticleID( "n" ), ParticleID( "n" ) } } }
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
