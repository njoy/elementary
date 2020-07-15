/**
 *  @brief Private helper function to produce a regex match
 */
static std::pair< int, int >
matchContinuum( const std::string& string ) {

  std::smatch match;
  if ( std::regex_match( string, match, LevelContinuum::regex ) ) {

    return match[1] == "" ? std::make_pair< int, int >( 0, 0 )
                          : std::make_pair< int, int >( std::stoi( match[2] ),
                                                        std::stoi( match[3] ) );
  }

  throw std::invalid_argument(
            "The string '" + string + "' does not appear to be a "
            "valid level continuum" );
}
