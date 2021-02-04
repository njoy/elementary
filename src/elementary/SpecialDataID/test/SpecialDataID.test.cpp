#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/SpecialDataID.hpp"

// other includes
#include <map>
#include <unordered_map>
#include "elementary/ParticleID.hpp"
#include "elementary/ParticlePairID.hpp"
#include "elementary/SpecialDataType.hpp"

// convenience typedefs
using ParticleID = njoy::elementary::ParticleID;
using ParticlePairID = njoy::elementary::ParticlePairID;
using SpecialDataType = njoy::elementary::SpecialDataType;
using SpecialDataID = njoy::elementary::SpecialDataID;

SCENARIO( "ParticlePairID" ) {

  GIVEN( "valid data for a SpecialDataID" ) {

    THEN( "a SpecialDataID can be created" ) {

      // using a string
      SpecialDataID id3( "n,U235->nubar,total" );
      CHECK( "n,U235->nubar,total" == id3.symbol() );

      id3 = SpecialDataID( "n,U235->xp" );
      CHECK( "n,U235->xp" == id3.symbol() );

      // using a reaction type
      SpecialDataID id4( ParticleID( "n" ), ParticleID( "U235" ), SpecialDataType( "xp" ) );
      CHECK( "n,U235->xp" == id4.symbol() );

      id4 = SpecialDataID( ParticleID( "n" ), ParticleID( "U235" ), SpecialDataType( 203 ) );
      CHECK( "n,U235->xp" == id4.symbol() );
    } // THEN
  } // GIVEN

  GIVEN( "valid SpecialDataID" ) {

    THEN( "the incident identifier can be extracted" ) {

      SpecialDataID id( "n,U235->xp" );

      CHECK( ParticlePairID( "n,U235" ) == id.incident() );
    } // THEN
  } // GIVEN

  GIVEN( "valid SpecialDataID instances" ) {

    SpecialDataID id1( ParticleID( "n" ), ParticleID( "U235" ),
                       SpecialDataType( 458 ) );
    SpecialDataID id2( ParticleID( "n" ), ParticleID( "U235" ),
                       SpecialDataType( 203 ) );

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

    THEN( "instances can be used as keys in a std::map" ) {

      std::map< SpecialDataID, std::string > map{

        { id1, "1" }, { id2, "2" }
      };

      CHECK( map[ id1 ] == "1" );
      CHECK( map[ id2 ] == "2" );
      CHECK( map[ SpecialDataID( "n,U235->qfission" ) ] == "1" );
      CHECK( map[ SpecialDataID( "n,U235->xp" ) ] == "2" );
    } // THEN

    THEN( "instances can be used as keys in a std::unordered_map" ) {

      std::unordered_map< SpecialDataID, std::string > map{

        { id1, "1" }, { id2, "2" }
      };

      CHECK( map[ id1 ] == "1" );
      CHECK( map[ id2 ] == "2" );
      CHECK( map[ SpecialDataID( "n,U235->qfission" ) ] == "1" );
      CHECK( map[ SpecialDataID( "n,U235->xp" ) ] == "2" );
    } // THEN
  } // GIVEN

  GIVEN( "invalid data for an SpecialDataID" ) {

    THEN( "an exception is thrown" ) {

      CHECK_THROWS( SpecialDataID( "not a special data ID" ) );
      CHECK_THROWS( SpecialDataID( "n,U235" ) ); // valid particle pair, no special data
    } // THEN
  } // GIVEN
} // SCENARIO
