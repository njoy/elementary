#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/ElementID.hpp"

// other includes
#include <map>
#include <unordered_map>

// convenience typedefs
using ElementID = njoy::elementary::ElementID;

SCENARIO( "ElementID" ) {

  GIVEN( "valid data for an ElementID" ) {

    THEN( "an ElementID can be created" ) {

      ElementID id( 1 );
      CHECK( 1 == id.number() );
      CHECK( "H" == id.symbol() );
      CHECK( "Hydrogen" == id.name() );

      id = ElementID( 2 );
      CHECK( 2 == id.number() );
      CHECK( "He" == id.symbol() );
      CHECK( "Helium" == id.name() );

      id = ElementID( 13 );
      CHECK( 13 == id.number() );
      CHECK( "Al" == id.symbol() );
      CHECK( "Aluminium" == id.name() );

      id = ElementID( "Aluminum" );
      CHECK( 13 == id.number() );
      CHECK( "Al" == id.symbol() );
      CHECK( "Aluminium" == id.name() );

      id = ElementID( "Aluminium" );
      CHECK( 13 == id.number() );
      CHECK( "Al" == id.symbol() );
      CHECK( "Aluminium" == id.name() );

      id = ElementID( "Al" );
      CHECK( 13 == id.number() );
      CHECK( "Al" == id.symbol() );
      CHECK( "Aluminium" == id.name() );

      id = ElementID( "aluminum" );
      CHECK( 13 == id.number() );
      CHECK( "Al" == id.symbol() );
      CHECK( "Aluminium" == id.name() );
    } // THEN
  } // GIVEN

  GIVEN( "valid ElementID instances" ) {

    ElementID id1( 1 );
    ElementID id2( 2 );

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

      std::map< ElementID, std::string > map{

        { id1, "1" }, { id2, "2" }
      };

      CHECK( map[ id1 ] == "1" );
      CHECK( map[ id2 ] == "2" );
      CHECK( map[ ElementID( 1 ) ] == "1" );
      CHECK( map[ ElementID( 2 ) ] == "2" );
    } // THEN

    THEN( "instances can be used as keys in a std::unordered_map" ) {

      std::unordered_map< ElementID, std::string > map{

        { id1, "1" }, { id2, "2" }
      };

      CHECK( map[ id1 ] == "1" );
      CHECK( map[ id2 ] == "2" );
      CHECK( map[ ElementID( 1 ) ] == "1" );
      CHECK( map[ ElementID( 2 ) ] == "2" );
    } // THEN
  } // GIVEN

  GIVEN( "invalid data for an ElementID" ) {

    THEN( "an exception is thrown" ) {

      CHECK_THROWS( ElementID( "not an element name, symbol or alternative" ) );
    } // THEN
  } // GIVEN
} // SCENARIO
