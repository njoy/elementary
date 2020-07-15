/**
 *  @brief Private helper function to produce a regex match
 */
static int
matchLevel( const std::string& string ) {

  std::smatch match;
  if ( std::regex_match( string, match, Level::regex ) ) {

    return match[3] == "" ? std::stoi( match[2] ) : continuum;
  }

  throw std::invalid_argument(
            "The string '" + string + "' does not appear to be a "
            "valid level number" );
}
