/**
 *  @brief Constructor
 *
 *  @param[in] identifier   the identifier string
 *  @param[in] validate     the optional flag to switch off validation
 */
Identifier( const std::string& identifier, bool validate = true ) :
  id_( identifier ), hash_( std::hash< std::string >{}( identifier ) ) {

  if ( validate ) { this->validate(); }
}
