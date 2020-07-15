/**
 *  @brief Constructor
 *
 *  This function throws an invalid_argument exception if invalid data is
 *  used.
 *
 *  @param[in] l   the level number
 */
Level( int l ) : level_( verifyLevel( l ) ) {}

/**
 *  @brief Constructor
 *
 *  This function throws an invalid_argument exception if invalid data is
 *  used.
 *
 *  @param[in] string   the string representation of a level number
 */
Level( const std::string& string ) :
  Level( matchLevel( string ) ) {}
