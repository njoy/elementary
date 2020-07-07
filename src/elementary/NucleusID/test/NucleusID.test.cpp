#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/NucleusID.hpp"

// other includes
#include "elementary/ElementID.hpp"
#include "elementary/IsotopeID.hpp"

// convenience typedefs
using ElementID = njoy::elementary::ElementID;
using IsotopeID = njoy::elementary::IsotopeID;
using NucleusID = njoy::elementary::NucleusID;

SCENARIO( "NucleusID" ) {

  GIVEN( "valid data for a NucleusID" ) {

    THEN( "a NucleusID can be created" ) {

      NucleusID id( 1, 1, 0 );
      CHECK( IsotopeID( 1, 1 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( 0 == id.level() );
      CHECK( "h1" == id.symbol() );
      CHECK( "h1" == id.name() );

      id = NucleusID( "h1" );
      CHECK( IsotopeID( 1, 1 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( 0 == id.level() );
      CHECK( "h1" == id.symbol() );
      CHECK( "h1" == id.name() );

      id = NucleusID( 1, 1, 1 );
      CHECK( IsotopeID( 1, 1 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( 1 == id.level() );
      CHECK( "h1_e1" == id.symbol() );
      CHECK( "h1_e1" == id.name() );

      id = NucleusID( "h1_e1" );
      CHECK( IsotopeID( 1, 1 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( 1 == id.level() );
      CHECK( "h1_e1" == id.symbol() );
      CHECK( "h1_e1" == id.name() );

      id = NucleusID( 1, 0, 0 );
      CHECK( IsotopeID( 1, 0 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 0 == id.mass() );
      CHECK( 0 == id.level() );
      CHECK( "h0" == id.symbol() );
      CHECK( "h0" == id.name() );

      id = NucleusID( "h0" );
      CHECK( IsotopeID( 1, 0 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 0 == id.mass() );
      CHECK( 0 == id.level() );
      CHECK( "h0" == id.symbol() );
      CHECK( "h0" == id.name() );
    } // THEN
  } // GIVEN

  GIVEN( "valid NucleusID instances" ) {

    NucleusID id1( "h1" );
    NucleusID id2( "he4" );

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
