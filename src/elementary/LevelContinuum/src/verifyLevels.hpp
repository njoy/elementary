/**
 *  @brief Private helper function to verify the upper and lower level numbers
 */
static void verifyLevels( int lower, int upper ) {

  if ( not ( ( lower == 0 ) and ( upper == 0 ) ) ) {

    if ( lower >= upper ) {

      throw std::invalid_argument(
                "The lower level number '" + std::to_string( lower ) + "' is "
                "larger than or equal to the upper level number '" +
                std::to_string( lower ) + "'" );
    }
  }
}
