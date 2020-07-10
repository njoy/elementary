#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/ParticleTupleID.hpp"

// other includes
#include "elementary/ParticleID.hpp"

// convenience typedefs
using ParticleTupleID = njoy::elementary::ParticleTupleID;
using ParticleID = njoy::elementary::ParticleID;

SCENARIO( "ParticleTupleID" ) {

  GIVEN( "valid data for a ParticleTupleID" ) {

    THEN( "a ParticleTupleID can be created" ) {

      // particle identifiers as separate arguments
      ParticleTupleID id1( ParticleID( "n" ), ParticleID( "Fe56" ) );
      CHECK( "n,Fe56" == id1.symbol() );

      ParticleTupleID id2( ParticleID( "n" ), ParticleID( "p" ),
                           ParticleID( "Fe56" ) );
      CHECK( "n,p,Fe56" == id2.symbol() );

      ParticleTupleID id3( ParticleID( "n" ), ParticleID( "p" ),
                           ParticleID( "he4" ), ParticleID( "Fe56" ) );
      CHECK( "n,p,he4,Fe56" == id3.symbol() );

      // using a vector
      std::vector< ParticleID > identifiers = {
        ParticleID( "n" ), ParticleID( "p" ),
        ParticleID( "he4" ), ParticleID( "Fe56" ) };
      ParticleTupleID id4( identifiers );
      CHECK( "n,p,he4,Fe56" == id4.symbol() );

      // using a string
      ParticleTupleID id5( "n,Fe56" );
      CHECK( "n,Fe56" == id5.symbol() );
    } // THEN
  } // GIVEN

  GIVEN( "valid ParticleTupleID instances" ) {

    ParticleTupleID id1( ParticleID( "n" ), ParticleID( "Fe56" ) );
    ParticleTupleID id2( ParticleID( "n" ), ParticleID( "Fe56_e1" ) );

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
} // SCENARIO
