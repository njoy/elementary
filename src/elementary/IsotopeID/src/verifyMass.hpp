/**
 *  @brief Private helper function to convert a user provided number into a
 *         mass number
 */
static MassNumber verifyMass( int number ) {

  if ( ( number >= 0 ) and
       ( number < 300 ) ) {

    return static_cast< MassNumber >( number );
  }
  else {

    throw std::invalid_argument(
              "The number '" + std::to_string( number ) + "' is not a "
              "valid atomic mass number" );
  }
}
