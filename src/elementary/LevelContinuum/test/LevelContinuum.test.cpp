#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/LevelContinuum.hpp"

// other includes
#include "elementary/LevelNumber.hpp"

// convenience typedefs
using LevelNumber = njoy::elementary::LevelNumber;
using LevelContinuum = njoy::elementary::LevelContinuum;

SCENARIO( "LevelContinuum" ) {

  GIVEN( "valid data for a LevelContinuum" ) {

    THEN( "a LevelContinuum can be created" ) {

      LevelContinuum id;
      CHECK( LevelNumber( 0 ) == id.lower() );
      CHECK( LevelNumber( 0 ) == id.upper() );
      CHECK( "[continuum]" == id.symbol() );
      CHECK( "[continuum]" == id.name() );

      id = LevelContinuum( 0, 0 );
      CHECK( LevelNumber( 0 ) == id.lower() );
      CHECK( LevelNumber( 0 ) == id.upper() );
      CHECK( "[continuum]" == id.symbol() );
      CHECK( "[continuum]" == id.name() );

      id = LevelContinuum( "[continuum]" );
      CHECK( LevelNumber( 0 ) == id.lower() );
      CHECK( LevelNumber( 0 ) == id.upper() );
      CHECK( "[continuum]" == id.symbol() );
      CHECK( "[continuum]" == id.name() );

      id = LevelContinuum( 0, 15 );
      CHECK( LevelNumber( 0 ) == id.lower() );
      CHECK( LevelNumber( 15 ) == id.upper() );
      CHECK( "[continuum:e0-e15]" == id.symbol() );
      CHECK( "[continuum:e0-e15]" == id.name() );

      id = LevelContinuum( "[continuum:e0-e15]" );
      CHECK( LevelNumber( 0 ) == id.lower() );
      CHECK( LevelNumber( 15 ) == id.upper() );
      CHECK( "[continuum:e0-e15]" == id.symbol() );
      CHECK( "[continuum:e0-e15]" == id.name() );

      id = LevelContinuum( 10, 15 );
      CHECK( LevelNumber( 10 ) == id.lower() );
      CHECK( LevelNumber( 15 ) == id.upper() );
      CHECK( "[continuum:e10-e15]" == id.symbol() );
      CHECK( "[continuum:e10-e15]" == id.name() );

      id = LevelContinuum( "[continuum:e10-e15]" );
      CHECK( LevelNumber( 10 ) == id.lower() );
      CHECK( LevelNumber( 15 ) == id.upper() );
      CHECK( "[continuum:e10-e15]" == id.symbol() );
      CHECK( "[continuum:e10-e15]" == id.name() );
    } // THEN
  } // GIVEN

  GIVEN( "invalid data for an LevelNumber" ) {

    THEN( "an exception is thrown" ) {

      CHECK_THROWS( LevelContinuum( "not a valid level number" ) );
      CHECK_THROWS( LevelContinuum( 1, 1 ) );      // equal, upper == lower
      CHECK_THROWS( LevelContinuum( 1, 0 ) );      // upper < lower
      CHECK_THROWS( LevelContinuum( 100, 110 ) );  // too high
    } // THEN
  } // GIVEN
} // SCENARIO
