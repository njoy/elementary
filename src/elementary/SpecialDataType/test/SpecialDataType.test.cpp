#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/SpecialDataType.hpp"

// other includes

// convenience typedefs
using SpecialDataType = njoy::elementary::SpecialDataType;

SCENARIO( "SpecialDataType" ) {

  GIVEN( "strings and ints" ) {

    THEN( "it can be verified of they are registered" ) {

      CHECK( true == SpecialDataType::isRegistered( "nubar,total" ) );
      CHECK( true == SpecialDataType::isRegistered( 452 ) );

      CHECK( true == SpecialDataType::isRegistered( "mubar" ) );
      CHECK( true == SpecialDataType::isRegistered( 251 ) );

      CHECK( false == SpecialDataType::isRegistered( "not registered" ) );
      CHECK( false == SpecialDataType::isRegistered( 999 ) );
    } // THEN
  } // GIVEN

  GIVEN( "valid data for a SpecialDataType" ) {

    THEN( "a SpecialDataType can be created" ) {

      SpecialDataType id1( 452 );
      CHECK( 452 == id1.mt() );
      CHECK( "nubar,total" == id1.name() );

      SpecialDataType id2( "nubar,total" );
      CHECK( 452 == id2.mt() );
      CHECK( "nubar,total" == id2.name() );

      SpecialDataType id3( 251 );
      CHECK( 251 == id3.mt() );
      CHECK( "mubar" == id3.name() );

      SpecialDataType id4( "mubar" );
      CHECK( 251 == id4.mt() );
      CHECK( "mubar" == id4.name() );
    } // THEN
  } // GIVEN

  GIVEN( "invalid data for an SpecialDataType" ) {

    THEN( "an exception is thrown" ) {

      CHECK_THROWS( SpecialDataType( "not a reaction name or alternative" ) );
      CHECK_THROWS( SpecialDataType( 0 ) );
      CHECK_THROWS( SpecialDataType( -1 ) );
    } // THEN
  } // GIVEN
} // SCENARIO
