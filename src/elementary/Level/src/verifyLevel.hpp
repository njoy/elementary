/**
 *  @brief Private helper function to convert a user provided number into a
 *         level number
 */
static Number verifyLevel( int number ) {

  if ( ( ( number >= 0 ) and ( number < 100 ) ) or
       ( number == continuum ) ) {

    return static_cast< Number >( number );
  }
  else {

    throw std::invalid_argument(
              "The number '" + std::to_string( number ) + "' is not a "
              "valid level number" );
  }
}
