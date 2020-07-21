SCENARIO( "join" ) {

  GIVEN( "a vector of strings" ) {

    std::vector< std::string > empty = {};
    std::vector< std::string > one = { "ab" };
    std::vector< std::string > strings = { "ab", "cd", "ef" };

    THEN( "the strings can be joined together with a separator" ) {

      CHECK( "" == join( empty, "->" ) );
      CHECK( "ab" == join( one, "->" ) );
      CHECK( "ab->cd->ef" == join( strings, "->" ) );
    } // THEN

    THEN( "the strings can be joined together without a separator" ) {

      CHECK( "" == join( empty ) );
      CHECK( "ab" == join( one ) );
      CHECK( "abcdef" == join( strings ) );
    } // THEN
  } // GIVEN
} // SCENARIO
