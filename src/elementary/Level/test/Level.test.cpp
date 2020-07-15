#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/Level.hpp"

// other includes

// convenience typedefs
using Level = njoy::elementary::Level;

SCENARIO( "Level" ) {

  GIVEN( "valid data for a Level" ) {

    THEN( "a Level can be created" ) {

      Level id( 0 );
      CHECK( 0 == id.number() );
      CHECK( "" == id.symbol() );
      CHECK( "e0" == id.name() );

      id = Level( "e0" );
      CHECK( 0 == id.number() );
      CHECK( "" == id.symbol() );
      CHECK( "e0" == id.name() );

      id = Level( "_e0" );
      CHECK( 0 == id.number() );
      CHECK( "" == id.symbol() );
      CHECK( "e0" == id.name() );

      id = Level( 1 );
      CHECK( 1 == id.number() );
      CHECK( "_e1" == id.symbol() );
      CHECK( "e1" == id.name() );

      id = Level( "e1" );
      CHECK( 1 == id.number() );
      CHECK( "_e1" == id.symbol() );
      CHECK( "e1" == id.name() );

      id = Level( "_e1" );
      CHECK( 1 == id.number() );
      CHECK( "_e1" == id.symbol() );
      CHECK( "e1" == id.name() );

      auto continuum = njoy::elementary::Level::continuum;

      id = Level( continuum );
      CHECK( continuum == id.number() );
      CHECK( "[continuum]" == id.symbol() );
      CHECK( "[continuum]" == id.name() );
    } // THEN
  } // GIVEN

  GIVEN( "valid Level instances" ) {

    Level id1( 0 );
    Level id2( 1 );

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

  GIVEN( "invalid data for an Level" ) {

    THEN( "an exception is thrown" ) {

      CHECK_THROWS( Level( "not a valid level number" ) );
      CHECK_THROWS( Level( -1 ) );  // negative level
      CHECK_THROWS( Level( 100 ) );  // too high
    } // THEN
  } // GIVEN
} // SCENARIO
