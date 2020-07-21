SCENARIO( "emit" ) {

  GIVEN( "valid identifiers" ) {

    FundamentalParticleID n( "n" );
    IsotopeID isotope_h1( "h1" );
    IsotopeID isotope_h2( "h2" );
    NucleusID h2( "h2" );
    NuclideID H2( "H2" );
    ParticleID particle_h2( "h2" );

    THEN( "an IsotopeID can be created by emission" ) {

      CHECK( isotope_h1 == emit( isotope_h2, n ) );
      CHECK( isotope_h1 == emit( h2, n ) );
      CHECK( isotope_h1 == emit( H2, n ) );
      CHECK( isotope_h1 == emit( particle_h2, n ) );
    } // THEN
  } // GIVEN
} // SCENARIO
