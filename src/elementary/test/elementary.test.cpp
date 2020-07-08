#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/src/absorb.hpp"
#include "elementary/src/emit.hpp"

// other includes
#include "elementary/FundamentalParticleID.hpp"
#include "elementary/IsotopeID.hpp"
#include "elementary/NucleusID.hpp"
#include "elementary/NuclideID.hpp"
#include "elementary/ParticleID.hpp"

// convenience typedefs
using FundamentalParticleID = njoy::elementary::FundamentalParticleID;
using IsotopeID = njoy::elementary::IsotopeID;
using NucleusID = njoy::elementary::NucleusID;
using NuclideID = njoy::elementary::NuclideID;
using ParticleID = njoy::elementary::ParticleID;

SCENARIO( "absorb" ) {

  GIVEN( "valid identifiers" ) {

    FundamentalParticleID n( "n" );
    IsotopeID isotope_h1( "h1" );
    NucleusID h1( "h1" );
    NuclideID H1( "H1" );
    ParticleID particle_h1( "h1" );

    THEN( "an IsotopeID can be created by absorption" ) {

      CHECK( IsotopeID( 1002 ) == njoy::elementary::absorb( isotope_h1, n ) );
      CHECK( IsotopeID( 1002 ) == njoy::elementary::absorb( h1, n ) );
      CHECK( IsotopeID( 1002 ) == njoy::elementary::absorb( H1, n ) );
      CHECK( IsotopeID( 1002 ) == njoy::elementary::absorb( particle_h1, n ) );
    } // THEN
  } // GIVEN
} // SCENARIO

SCENARIO( "emit" ) {

  GIVEN( "valid identifiers" ) {

    FundamentalParticleID n( "n" );
    IsotopeID isotope_h2( "h2" );
    NucleusID h2( "h2" );
    NuclideID H2( "H2" );
    ParticleID particle_h2( "h2" );

    THEN( "an IsotopeID can be created by emission" ) {

      CHECK( IsotopeID( 1001 ) == njoy::elementary::emit( isotope_h2, n ) );
      CHECK( IsotopeID( 1001 ) == njoy::elementary::emit( h2, n ) );
      CHECK( IsotopeID( 1001 ) == njoy::elementary::emit( H2, n ) );
      CHECK( IsotopeID( 1001 ) == njoy::elementary::emit( particle_h2, n ) );
    } // THEN
  } // GIVEN
} // SCENARIO
