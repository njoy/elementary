#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/ParticleTupleID.hpp"

// other includes

// convenience typedefs
using ParticleTupleID = njoy::elementary::ParticleTupleID;

SCENARIO( "ParticleTupleID" ) {

  GIVEN( "valid data for a ParticleTupleID" ) {

    THEN( "a ParticleTupleID can be created" ) {

      ParticleTupleID id( "n,Fe56" );
      CHECK( "n,Fe56" == id.symbol() );
    } // THEN
  } // GIVEN

  GIVEN( "valid ParticleTupleID instances" ) {

    ParticleTupleID id1( "n,Fe56" );
    ParticleTupleID id2( "n,Fe56_e1" );

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
