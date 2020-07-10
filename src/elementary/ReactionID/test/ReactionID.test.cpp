#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/ReactionID.hpp"

// other includes
#include "elementary/ParticlePairID.hpp"
#include "elementary/ParticleTupleID.hpp"

// convenience typedefs
using ParticlePairID = njoy::elementary::ParticlePairID;
using ParticleTupleID = njoy::elementary::ParticleTupleID;
using ReactionID = njoy::elementary::ReactionID;

SCENARIO( "ParticlePairID" ) {

  GIVEN( "valid data for a ReactionID" ) {

    THEN( "a ReactionID can be created" ) {

      // particle identifiers as separate arguments
      ReactionID id1( ParticlePairID( "n,Fe56" ), ParticlePairID( "n,Fe56" ) );
      CHECK( "n,Fe56->n,Fe56" == id1.symbol() );

      // using a string
      ReactionID id2( "n,Fe56->n,Fe56" );
      CHECK( "n,Fe56->n,Fe56" == id2.symbol() );
    } // THEN
  } // GIVEN

  GIVEN( "valid ReactionID instances" ) {

    ReactionID id1( ParticlePairID( "n,Fe56" ), ParticlePairID( "n,Fe56" ) );
    ReactionID id2( ParticlePairID( "n,Fe56" ), ParticlePairID( "n,Fe56_e1" ) );

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

  GIVEN( "invalid data for an ReactionID" ) {

    THEN( "an exception is thrown" ) {

      CHECK_THROWS( ReactionID( "not a reaction ID" ) );
      CHECK_THROWS( ReactionID( "n,Fe56" ) ); // valid particle pair, no reaction
    } // THEN
  } // GIVEN
} // SCENARIO
