#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/ParticlePairID.hpp"

// other includes
#include "elementary/ParticleID.hpp"

// convenience typedefs
using ParticlePairID = njoy::elementary::ParticlePairID;
using ParticleID = njoy::elementary::ParticleID;

SCENARIO( "ParticlePairID" ) {

  GIVEN( "valid data for a ParticlePairID" ) {

    THEN( "a ParticlePairID can be created" ) {

      // particle identifiers as separate arguments
      ParticlePairID id1( ParticleID( "n" ), ParticleID( "Fe56" ) );
      CHECK( "n,Fe56" == id1.symbol() );

      // using a string
      ParticlePairID id2( "n,Fe56" );
      CHECK( "n,Fe56" == id2.symbol() );
    } // THEN
  } // GIVEN

  GIVEN( "valid ParticlePairID" ) {

    THEN( "the particles and residual identifiers can be extracted" ) {

      ParticlePairID id( "n,Fe56" );

      CHECK( ParticleID( "n" ) == id.particle() );
      CHECK( ParticleID( "Fe56" ) == id.residual() );
    } // THEN
  } // GIVEN

  GIVEN( "valid ParticlePairID instances" ) {

    ParticlePairID id1( ParticleID( "n" ), ParticleID( "Fe56" ) );
    ParticlePairID id2( ParticleID( "n" ), ParticleID( "Fe56_e1" ) );

    THEN( "instances can be compared" ) {

      CHECK( ( id1 <  id1 ) == false );
      CHECK( ( id1 == id1 ) == true );
      CHECK( ( id1 != id1 ) == false );
      CHECK( ( id1 <  id2 ) == true );
      CHECK( ( id1 == id2 ) == false );
      CHECK( ( id1 != id2 ) == true );
      CHECK( ( id2 <  id1 ) == false );
      CHECK( ( id2 == id1 ) == false );
      CHECK( ( id2 != id1 ) == true );
    } // THEN
  } // GIVEN

  GIVEN( "invalid data for an ParticlePairID" ) {

    THEN( "an exception is thrown" ) {

      CHECK_THROWS( ParticlePairID( "not a particle pair ID" ) );
      CHECK_THROWS( ParticlePairID( "n,p,Fe56" ) );  // particle tuple, not pair
      CHECK_THROWS( ParticlePairID( "Fe56" ) );      // single valid particle
    } // THEN
  } // GIVEN
} // SCENARIO
