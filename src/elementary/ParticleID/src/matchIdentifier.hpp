/**
 *  @brief Private helper function to produce an identifier
 */
IdentifierVariant
matchIdentifier( const std::string& string ) {

  try {

    return FundamentalParticleID( string );
  }
  catch ( const std::invalid_argument& ) {

    try {

      return NuclideID( string );
    }
    catch ( const std::invalid_argument& ) {

      try {

        return NucleusID( string );
      }
      catch ( const std::invalid_argument& ) {

        throw std::invalid_argument(
                  "The string '" + string + "' does not appear to be a "
                  "valid particle identifier" );
      }
    }
  }
}
