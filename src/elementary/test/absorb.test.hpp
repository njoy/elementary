SCENARIO( "absorb" ) {

  GIVEN( "valid identifiers" ) {

    FundamentalParticleID n( "n" );
    IsotopeID isotope_h2( "h2" );
    IsotopeID isotope_h1( "h1" );
    NucleusID h1( "h1" );
    NuclideID H1( "H1" );
    ParticleID particle_h1( "h1" );

    THEN( "an IsotopeID can be created by absorption" ) {

      CHECK( isotope_h2 == absorb( isotope_h1, n ) );
      CHECK( isotope_h2 == absorb( h1, n ) );
      CHECK( isotope_h2 == absorb( H1, n ) );
      CHECK( isotope_h2 == absorb( particle_h1, n ) );
    } // THEN
  } // GIVEN
} // SCENARIO
