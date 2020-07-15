/**
 *  @brief Constructor for unspecified continuum levels
 */
LevelContinuum() : lower_( 0 ), upper_( 0 ) {}

/**
 *  @brief Constructor
 *
 *  This function throws an invalid_argument exception if invalid data is
 *  used.
 *
 *  @param[in] lower   the lower energy level number of the continuum
 *  @param[in] upper   the upper energy level number of the continuum
 */
LevelContinuum( int lower, int upper ) :
  lower_( lower ), upper_( upper ) {

  verifyLevels( this->lower_.number(), this->upper_.number() );
}

private:

/**
 *  @brief Private constructor
 */
LevelContinuum( const std::pair< int, int >& pair ) :
  LevelContinuum( pair.first, pair.second ) {}

public:

/**
 *  @brief Constructor
 *
 *  This function throws an invalid_argument exception if invalid data is
 *  used.
 *
 *  @param[in] string   the string representation of a level continuum
 */
LevelContinuum( const std::string& string ) :
  LevelContinuum( matchContinuum( string ) ) {}
