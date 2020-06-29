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
      CHECK( "h1_e0" == id.name() );
    } // THEN
  } // GIVEN

  GIVEN( "valid NucleusID instances" ) {

    NucleusID id1( 1, 1, 0 );
    NucleusID id2( 2, 4, 0 );

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
