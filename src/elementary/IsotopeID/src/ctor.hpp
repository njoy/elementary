private:

/**
 *  @brief Private constructor
 */
IsotopeID( ElementID&& element, int a ) :
  element_( std::move( element ) ), mass_( verifyMass( a ) ) {}

/**
 *  @brief Private constructor
 */
IsotopeID( const std::pair< std::string, int >&& pair ) :
  IsotopeID( ElementID( pair.first ), pair.second ) {}

public:

/**
 *  @brief Constructor
 *
 *  This function throws an invalid_argument exception if invalid data is
 *  used.
 *
 *  @param[in] z   the element number
 *  @param[in] a   the mass number
 */
IsotopeID( int z, int a ) : IsotopeID( ElementID( z ), a ) {}

/**
 *  @brief Constructor
 *
 *  This function throws an invalid_argument exception if invalid data is
 *  used.
 *
 *  @param[in] za   the za number
 */
IsotopeID( int za ) : IsotopeID( ( za - za%1000 ) / 1000, za%1000 ) {}

/**
 *  @brief Constructor
 *
 *  This function throws an invalid_argument exception if invalid data is
 *  used.
 *
 *  @param[in] string   the string representation of the isotope
 */
IsotopeID( const std::string& string ) :
  IsotopeID( matchIdentifier( string ) ) {}
