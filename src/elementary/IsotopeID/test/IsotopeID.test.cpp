#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/IsotopeID.hpp"

// other includes
#include "elementary/ElementID.hpp"

// convenience typedefs
using ElementID = njoy::elementary::ElementID;
using IsotopeID = njoy::elementary::IsotopeID;

SCENARIO( "IsotopeID" ) {

  GIVEN( "valid data for an IsotopeID" ) {

    THEN( "an IsotopeID can be created" ) {

      IsotopeID id( 1, 1 );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( 1001 == id.za() );
      CHECK( "H1" == id.symbol() );
      CHECK( "H1" == id.name() );

      id = IsotopeID( 1001 );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( 1001 == id.za() );
      CHECK( "H1" == id.symbol() );
      CHECK( "H1" == id.name() );

      id = IsotopeID( "H1" );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( 1001 == id.za() );
      CHECK( "H1" == id.symbol() );
      CHECK( "H1" == id.name() );

      id = IsotopeID( "h1" );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1001 == id.za() );
      CHECK( 1 == id.mass() );
      CHECK( "H1" == id.symbol() );
      CHECK( "H1" == id.name() );

      id = IsotopeID( 1, 0 );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 0 == id.mass() );
      CHECK( 1000 == id.za() );
      CHECK( "H0" == id.symbol() );
      CHECK( "H0" == id.name() );

      id = IsotopeID( 1000 );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 0 == id.mass() );
      CHECK( 1000 == id.za() );
      CHECK( "H0" == id.symbol() );
      CHECK( "H0" == id.name() );

      id = IsotopeID( "H0" );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 0 == id.mass() );
      CHECK( 1000 == id.za() );
      CHECK( "H0" == id.symbol() );
      CHECK( "H0" == id.name() );

      id = IsotopeID( "h0" );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 0 == id.mass() );
      CHECK( 1000 == id.za() );
      CHECK( "H0" == id.symbol() );
      CHECK( "H0" == id.name() );

      id = IsotopeID( "H" );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 0 == id.mass() );
      CHECK( 1000 == id.za() );
      CHECK( "H0" == id.symbol() );
      CHECK( "H0" == id.name() );

      id = IsotopeID( "h" );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 0 == id.mass() );
      CHECK( 1000 == id.za() );
      CHECK( "H0" == id.symbol() );
      CHECK( "H0" == id.name() );
    } // THEN
  } // GIVEN

  GIVEN( "valid IsotopeID instances" ) {

    IsotopeID id1( "H1" );
    IsotopeID id2( "He4" );

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
