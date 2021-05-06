/**
 *  @brief Private helper function to convert a user provided string into an
 *         element number
 */
static Number lookup( const std::string& string ) {

  try {

    return ElementID::conversion_dictionary.at(
               utility::tolower( string ) );
  }
  catch ( ... ) {

    throw std::invalid_argument(
              "The string '" + string + "' is not a valid element symbol, "
              "name or alternative" );
  }
}

/**
 *  @brief Private helper function to convert a user provided number into an
 *         element number
 */
static Number lookup( int number ) {

  if ( ( number > 0 ) and
       ( number <= ElementID::element_dictionary.rbegin()->first ) ) {

    return static_cast< Number >( number );
  }
  else {

    throw std::invalid_argument(
              "The number '" + std::to_string( number ) + "' is not a "
              "valid element number" );
  }
}
