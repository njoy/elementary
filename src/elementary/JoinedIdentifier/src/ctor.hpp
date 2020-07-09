/**
 *  @brief Constructor
 *
 *  @param[in] identifier   the identifier string
 */
JoinedIdentifier( const std::string& identifier, bool validate = true ) :
  Identifier< Derived >( identifier, validate ) {}

/**
 *  @brief Constructor
 *
 *  @param[in] identifiers   the identifier strings
 */
JoinedIdentifier( std::vector< std::string >&& identifiers,
                  bool validate = true ) :
  Identifier< Derived >( this->generate( std::move( identifiers ) ),
                         validate ) {}
