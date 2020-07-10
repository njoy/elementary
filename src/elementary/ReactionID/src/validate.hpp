/**
 *  @brief Verify if a string is a valid ReactionID
 *
 *  @param[in] string   the string to be validated
 */
static bool validate( const std::string& string ) {

  auto strings = split( string, "->" );
  if ( strings.size() != 2 ) {

    return false;
  }
  try {

    ParticleTupleID test1( strings[0] );
    ParticleTupleID test2( strings[1] );
  }
  catch ( ... ) {

    return false;
  }
  return true;
}
