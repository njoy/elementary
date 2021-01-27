/**
 *  @brief Verify if a string is a valid ReactionID
 *
 *  @param[in] string   the string to be validated
 */
static bool validate( const std::string& string ) {

  auto strings = split( string, "->" );
  if ( strings.size() == 2 ) {

    if ( ParticlePairID::validate( strings[0] ) ) {

      if ( SpecialDataType::isRegistered( strings[1] ) ) {

        return true;
      }
    }
  }
  return false;
}
