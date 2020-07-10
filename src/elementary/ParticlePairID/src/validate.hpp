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
  return ParticleTupleID::validate( string );
}
