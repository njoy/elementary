/**
 *  @brief Private helper function to produce a regex match
 */
static int
matchLevel( const std::string& string ) {

  std::smatch match;
  if ( std::regex_match( string, match, LevelNumber::regex ) ) {

    return std::stoi( match[1] );
  }

  throw std::invalid_argument(
            "The string '" + string + "' does not appear to be a "
            "valid level number" );
}
