/**
 *  @brief Private helper function to convert a user provided number into a
 *         level number
 */
static LevelNumber verifyLevel( int number ) {

  if ( ( number >= 0 ) and
       ( number < 100 ) ) {

    return static_cast< LevelNumber >( number );
  }
  else {

    throw std::invalid_argument(
              "The number '" + std::to_string( number ) + "' is not a "
              "valid level number" );
  }
}
