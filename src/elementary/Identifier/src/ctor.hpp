/**
 *  @brief Constructor
 *
 *  @param[in] identifier   the identifier string
 */
Identifier( const std::string& identifier, bool validate = true ) :
  id_( identifier ) {

  if ( validate ) { this->validate(); }
}
