/**
 *  @brief Private helper function to validate the string as an ID or throw an
 *         error.
 */
void validate() const {

  if ( not Derived::validate( this->id_ ) ) {

    auto name = Derived::name();
    throw std::invalid_argument( "The string '" + this->id_ + "' is not a "
                                 "valid identifier string for " +
                                 name );
  }
}
