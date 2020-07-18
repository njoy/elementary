/**
 *  @brief String based constructor
 *
 *  This function throws an invalid_argument exception if the string is not
 *  a registered name or alternative.
 *
 *  @param[in] string   the name or alternative name of the reaction
 *                      (case insensitive)
 */
ReactionType( const std::string& string ) : name_( lookup( string ) ) {}

/**
 *  @brief Constructor
 *
 *  This function throws an invalid_argument exception if the number is not
 *  a registered mt number.
 *
 *  @param[in] number   the mt number
 */
ReactionType( int number ) : name_( lookup( number ) ) {}
