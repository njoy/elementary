SCENARIO( "resolve" ) {

  GIVEN( "valid identifiers" ) {

    ParticleID in( "n" );
    ParticleID target( "Fe56" );

    ReactionType mt51( 51 );
    ReactionType mt102( 102 );

    ReactionType mt1( 1 );
    ReactionType mt18( 1 );

    THEN( "the daughter is returned for normal reactions" ) {

      CHECK( ParticleID( "Fe56_e1" ) == resolve( in, target, mt51 ) );
      CHECK( ParticleID( "Fe57" ) == resolve( in, target, mt102 ) );
    } // THEN

    THEN( "an exception is thrown for special reactions" ) {

      CHECK_THROWS( resolve( in, target, mt1 ) );
      CHECK_THROWS( resolve( in, target, mt18 ) );
    } // THEN
  } // GIVEN
} // SCENARIO
