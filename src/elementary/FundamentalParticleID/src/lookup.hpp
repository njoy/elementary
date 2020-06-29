/**
 *  @brief Private helper function to convert a user provided string into an
 *         element number
 */
static Hash lookup( const std::string& string ) {

  try {

    return FundamentalParticleID::conversion_dictionary.at( tolower( string ) );
  }
  catch ( ... ) {

    throw std::invalid_argument(
              "The string '" + string + "' is not a valid fundamental particle "
              "symbol, name or alternative" );
  }
}
