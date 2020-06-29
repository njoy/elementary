#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/FundamentalParticleID.hpp"

// convenience typedefs
using FundamentalParticleID = njoy::elementary::FundamentalParticleID;

SCENARIO( "FundamentalParticleID" ) {

  GIVEN( "valid data for an FundamentalParticleID" ) {

    THEN( "an FundamentalParticleID can be created" ) {

      FundamentalParticleID id( "n" );
      CHECK( "n" == id.symbol() );
      CHECK( "neutron" == id.name() );
      CHECK( 10 == id.hash() );

      id = FundamentalParticleID( "photon" );
      CHECK( "photon" == id.symbol() );
      CHECK( "photon" == id.name() );
      CHECK( 0 == id.hash() );

      id = FundamentalParticleID( "g" );
      CHECK( "photon" == id.symbol() );
      CHECK( "photon" == id.name() );
      CHECK( 0 == id.hash() );

      id = FundamentalParticleID( "gamma" );
      CHECK( "photon" == id.symbol() );
      CHECK( "photon" == id.name() );
      CHECK( 0 == id.hash() );

      id = FundamentalParticleID( "GAMMA" );
      CHECK( "photon" == id.symbol() );
      CHECK( "photon" == id.name() );
      CHECK( 0 == id.hash() );

      id = FundamentalParticleID( "x-ray" );
      CHECK( "photon" == id.symbol() );
      CHECK( "photon" == id.name() );
      CHECK( 0 == id.hash() );
    } // THEN
  } // GIVEN

  GIVEN( "valid FundamentalParticleID instances" ) {

    FundamentalParticleID id1( "n" );
    FundamentalParticleID id2( "p" );

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
