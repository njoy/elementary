/**
 *  @brief Private helper function to convert a user provided string into a
 *         reaction number
 */
static Number lookup( const std::string& string ) {

  try {

    return ReactionNumber::conversion_dictionary.at( tolower( string ) );
  }
  catch ( const std::out_of_range& ) {

    throw std::invalid_argument(
              "The string '" + string + "' is not a registered ENDF reaction "
              "name or alternative" );
  }
}

/**
 *  @brief Private helper function to convert a user provided number into a
 *         reaction number
 */
static Number lookup( int number ) {

  if ( ReactionNumber::mt_dictionary.find( number ) !=
       ReactionNumber::mt_dictionary.end() ) {

    return static_cast< Number >( number );
  }
  else {

    throw std::invalid_argument(
              "The number '" + std::to_string( number ) + "' is not a "
              "registered ENDF MT number" );
  }
}
