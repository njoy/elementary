/**
 *  @brief Private helper function to transform identifiers into strings.
 */
std::string generate( const std::vector< ParticleID >& ids ) {

  std::vector< std::string > strings;
  std::transform( ids.begin(), ids.end(), std::back_inserter( strings ),
                  [] ( const auto& id ) { return id.symbol(); } );
  return join( strings, "," );
}
