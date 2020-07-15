#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/LevelNumber.hpp"

// other includes

// convenience typedefs
using LevelNumber = njoy::elementary::LevelNumber;

SCENARIO( "LevelNumber" ) {

  GIVEN( "valid data for a LevelNumber" ) {

    THEN( "a LevelNumber can be created" ) {

      LevelNumber id( 0 );
      CHECK( 0 == id.number() );
      CHECK( "" == id.symbol() );
      CHECK( "e0" == id.name() );

      id = LevelNumber( "e0" );
      CHECK( 0 == id.number() );
      CHECK( "" == id.symbol() );
      CHECK( "e0" == id.name() );

      id = LevelNumber( "_e0" );
      CHECK( 0 == id.number() );
      CHECK( "" == id.symbol() );
      CHECK( "e0" == id.name() );

      id = LevelNumber( 1 );
      CHECK( 1 == id.number() );
      CHECK( "_e1" == id.symbol() );
      CHECK( "e1" == id.name() );

      id = LevelNumber( "e1" );
      CHECK( 1 == id.number() );
      CHECK( "_e1" == id.symbol() );
      CHECK( "e1" == id.name() );

      id = LevelNumber( "_e1" );
      CHECK( 1 == id.number() );
      CHECK( "_e1" == id.symbol() );
      CHECK( "e1" == id.name() );
    } // THEN
  } // GIVEN

  GIVEN( "valid LevelNumber instances" ) {

    LevelNumber id1( 0 );
    LevelNumber id2( 1 );

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

  GIVEN( "invalid data for an LevelNumber" ) {

    THEN( "an exception is thrown" ) {

      CHECK_THROWS( LevelNumber( "not a valid level number" ) );
      CHECK_THROWS( LevelNumber( -1 ) );  // negative level
      CHECK_THROWS( LevelNumber( 100 ) );  // too high
    } // THEN
  } // GIVEN
} // SCENARIO
