/**
 *  @brief Private helper function to convert a user provided string into a
 *         reaction number
 */
static const std::string& lookup( const std::string& string ) {

  try {

    return ReactionNumber::name_conversion_dictionary.at( tolower( string ) );
  }
  catch ( const std::out_of_range& ) {

    throw std::invalid_argument(
              "The string '" + string + "' is not a registered reaction "
              "name or alternative" );
  }
}

/**
 *  @brief Private helper function to convert a user provided number into a
 *         reaction number
 */
static const std::string& lookup( int number ) {

  try {

    return ReactionNumber::mt_conversion_dictionary.at( number );
  }
  catch ( const std::out_of_range& ) {

    throw std::invalid_argument(
              "The number '" + std::to_string( number ) + "' is not a "
              "registered ENDF MT number" );
  }
}
