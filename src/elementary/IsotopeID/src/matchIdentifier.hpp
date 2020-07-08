/**
 *  @brief Private helper function to produce a regex match
 */
static std::pair< std::string, int >
matchIdentifier( const std::string& string ) {

  std::smatch match;
  if ( std::regex_match( string, match, IsotopeID::regex ) ) {

    return std::make_pair( match[1],
                           match[2] != "" ? std::stoi( match[2] ) : 0 );
  }

  throw std::invalid_argument(
            "The string '" + string + "' does not appear to be a "
            "valid isotope identifier" );
}
