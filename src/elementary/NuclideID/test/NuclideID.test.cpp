#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/NuclideID.hpp"

// other includes
#include "elementary/ElementID.hpp"
#include "elementary/IsotopeID.hpp"

// convenience typedefs
using ElementID = njoy::elementary::ElementID;
using IsotopeID = njoy::elementary::IsotopeID;
using NuclideID = njoy::elementary::NuclideID;

SCENARIO( "NuclideID" ) {

  GIVEN( "valid data for a NuclideID" ) {

    THEN( "a NuclideID can be created" ) {

      NuclideID id( 1, 1, 0 );
      CHECK( IsotopeID( 1, 1 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( 0 == id.level() );
      CHECK( 1001 == id.za() );
      CHECK( "H1" == id.symbol() );
      CHECK( "H1" == id.name() );

      id = NuclideID( "H1" );
      CHECK( IsotopeID( 1, 1 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( 0 == id.level() );
      CHECK( 1001 == id.za() );
      CHECK( "H1" == id.symbol() );
      CHECK( "H1" == id.name() );

      id = NuclideID( "H1_e0" );
      CHECK( IsotopeID( 1, 1 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( 0 == id.level() );
      CHECK( 1001 == id.za() );
      CHECK( "H1" == id.symbol() );
      CHECK( "H1" == id.name() );

      id = NuclideID( 1, 1, 1 );
      CHECK( IsotopeID( 1, 1 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( 1 == id.level() );
      CHECK( 1001 == id.za() );
      CHECK( "H1_e1" == id.symbol() );
      CHECK( "H1_e1" == id.name() );

      id = NuclideID( "H1_e1" );
      CHECK( IsotopeID( 1, 1 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( 1 == id.level() );
      CHECK( 1001 == id.za() );
      CHECK( "H1_e1" == id.symbol() );
      CHECK( "H1_e1" == id.name() );

      id = NuclideID( 1, 0, 0 );
      CHECK( IsotopeID( 1, 0 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 0 == id.mass() );
      CHECK( 0 == id.level() );
      CHECK( 1000 == id.za() );
      CHECK( "H0" == id.symbol() );
      CHECK( "H0" == id.name() );

      id = NuclideID( "H0" );
      CHECK( IsotopeID( 1, 0 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 0 == id.mass() );
      CHECK( 0 == id.level() );
      CHECK( 1000 == id.za() );
      CHECK( "H0" == id.symbol() );
      CHECK( "H0" == id.name() );
    } // THEN
  } // GIVEN

  GIVEN( "valid NuclideID instances" ) {

    NuclideID id1( "H1" );
    NuclideID id2( "He4" );

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
