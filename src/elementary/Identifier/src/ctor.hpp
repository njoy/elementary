/**
 *  @brief Constructor
 *
 *  @param[in] identifier   the identifier string
 */
Identifier( const std::string& identifier ) : id_( identifier ) {

  this->validate();
}
