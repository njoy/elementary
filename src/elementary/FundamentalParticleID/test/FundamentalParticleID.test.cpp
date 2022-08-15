#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/FundamentalParticleID.hpp"

// other includes
#include <map>
#include <unordered_map>

// convenience typedefs
using FundamentalParticleID = njoy::elementary::FundamentalParticleID;

SCENARIO( "FundamentalParticleID" ) {

  GIVEN( "valid data for an FundamentalParticleID" ) {

    THEN( "an FundamentalParticleID can be created" ) {

      FundamentalParticleID id( "n" );
      CHECK( "n" == id.symbol() );
      CHECK( "neutron" == id.name() );
      CHECK( 1 == id.za() );
      CHECK( 1 == id.hash() );

      id = FundamentalParticleID( "photon" );
      CHECK( "photon" == id.symbol() );
      CHECK( "photon" == id.name() );
      CHECK( 0 == id.za() );
      CHECK( 0 == id.hash() );

      id = FundamentalParticleID( "g" );
      CHECK( "photon" == id.symbol() );
      CHECK( "photon" == id.name() );
      CHECK( 0 == id.za() );
      CHECK( 0 == id.hash() );

      id = FundamentalParticleID( "gamma" );
      CHECK( "photon" == id.symbol() );
      CHECK( "photon" == id.name() );
      CHECK( 0 == id.za() );
      CHECK( 0 == id.hash() );

      id = FundamentalParticleID( "GAMMA" );
      CHECK( "photon" == id.symbol() );
      CHECK( "photon" == id.name() );
      CHECK( 0 == id.za() );
      CHECK( 0 == id.hash() );

      id = FundamentalParticleID( "x-ray" );
      CHECK( "photon" == id.symbol() );
      CHECK( "photon" == id.name() );
      CHECK( 0 == id.za() );
      CHECK( 0 == id.hash() );
    } // THEN
  } // GIVEN

  GIVEN( "valid FundamentalParticleID instances" ) {

    FundamentalParticleID id1( "n" );
    FundamentalParticleID id2( "p" );

    THEN( "instances can be compared" ) {

      CHECK( ( id1 <  id1 ) == false );
      CHECK( ( id1 <= id1 ) == true );
      CHECK( ( id1 >  id1 ) == false );
      CHECK( ( id1 >= id1 ) == true );
      CHECK( ( id1 == id1 ) == true );
      CHECK( ( id1 != id1 ) == false );
      CHECK( ( id1 <  id2 ) == true );
      CHECK( ( id1 <= id2 ) == true );
      CHECK( ( id1 >  id2 ) == false );
      CHECK( ( id1 >= id2 ) == false );
      CHECK( ( id1 == id2 ) == false );
      CHECK( ( id1 != id2 ) == true );
      CHECK( ( id2 <  id1 ) == false );
      CHECK( ( id2 <= id1 ) == false );
      CHECK( ( id2 >  id1 ) == true );
      CHECK( ( id2 >= id1 ) == true );
      CHECK( ( id2 == id1 ) == false );
      CHECK( ( id2 != id1 ) == true );
    } // THEN

    THEN( "instances can be used as keys in a std::map" ) {

      std::map< FundamentalParticleID, std::string > map{

        { id1, "1" }, { id2, "2" }
      };

      CHECK( map[ id1 ] == "1" );
      CHECK( map[ id2 ] == "2" );
      CHECK( map[ FundamentalParticleID( "n" ) ] == "1" );
      CHECK( map[ FundamentalParticleID( "p" ) ] == "2" );
    } // THEN

    THEN( "instances can be used as keys in a std::unordered_map" ) {

      std::unordered_map< FundamentalParticleID, std::string > map{

        { id1, "1" }, { id2, "2" }
      };

      CHECK( map[ id1 ] == "1" );
      CHECK( map[ id2 ] == "2" );
      CHECK( map[ FundamentalParticleID( "n" ) ] == "1" );
      CHECK( map[ FundamentalParticleID( "p" ) ] == "2" );
    } // THEN
  } // GIVEN

  GIVEN( "invalid data for an FundamentalParticleID" ) {

    THEN( "an exception is thrown" ) {

      CHECK_THROWS(
        FundamentalParticleID(
          "not a fundamental particle name, symbol or alternative" ) );
    } // THEN
  } // GIVEN
} // SCENARIO
