/**
 *  @brief String based constructor
 *
 *  This function throws an invalid_argument exception if the string is not
 *  a registered symbol, name or alternative.
 *
 *  @param[in] string   the symbol, name or alternative name of the element
 *                      (case insensitive)
 */
ElementID( const std::string& string ) : z_( lookup( string ) ) {}

/**
 *  @brief Constructor
 *
 *  This function throws an invalid_argument exception if the number is not
 *  between 1 and the largest registered element number.
 *
 *  @param[in] number   the element number
 */
ElementID( int number ) : z_( lookup( number ) ) {}
