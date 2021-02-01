/**
 *  @brief Verify if a string is a valid identifier string for a particle pair
 *
 *  @param[in] string   the string to be validated
 */
static bool validate( const std::string& string ) {

  auto strings = utility::split( string, "," );
  if ( strings.size() != 2 ) {

    if ( ReactionType::isRegistered( string ) ) {

      ReactionType type( string );
      if ( ( type.isSpecial() or ( type.symbol() == "capture" ) ) and
           ( type.symbol() != "elastic" ) ) {

        return true;
      }
    }
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
