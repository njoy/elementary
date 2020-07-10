/**
 *  @brief Verify if a string is a valid ParticleTupleID
 *
 *  @param[in] string   the string to be valdiated
 */
static bool validate( const std::string& string ) {

  auto strings = split( string, "," );
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
