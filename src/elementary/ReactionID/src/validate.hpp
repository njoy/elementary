/**
 *  @brief Verify if a string is a valid ReactionID
 *
 *  @param[in] string   the string to be validated
 */
static bool validate( const std::string& string ) {

  auto strings = utility::split( string, "->" );
  if ( strings.size() != 2 ) {

    return false;
  }
  return ( ParticleTupleID::validate( strings[0] ) and
           ParticleTupleID::validate( strings[1] ) );
}
