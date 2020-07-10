/**
 *  @brief Verify if a string is a valid ParticleTupleID
 *
 *  @param[in] string   the string to be validated
 */
static bool validate( const std::string& string ) {

  auto strings = split( string, "," );
  if ( strings.size() < 2 ) {

    return false;
  }
  for ( const auto& value : strings ) {

    try {

      ParticleID test( value );
    }
    catch ( ... ) {

      return false;
    }
  }

  return true;
}
