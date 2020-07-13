/**
 *  @brief Verify if a string is a valid ParticlePairID
 *
 *  @param[in] string   the string to be validated
 */
static bool validate( const std::string& string ) {

  auto strings = split( string, "," );
  if ( strings.size() != 2 ) {

    return false;
  }
  try {

    ParticleID test1( strings[0] );
    ParticleID test2( strings[1] );
  }
  catch ( ... ) {

    return false;
  }
  return true;
}
