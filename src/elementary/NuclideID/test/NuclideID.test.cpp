#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/NuclideID.hpp"

// other includes
#include "elementary/NuclideID.hpp"

// convenience typedefs
using ElementID = njoy::elementary::ElementID;
using NuclideID = njoy::elementary::NuclideID;

SCENARIO( "NuclideID" ) {

  GIVEN( "valid data for a NuclideID" ) {

    THEN( "a NuclideID can be created" ) {

      NuclideID id( 1, 1, 0 );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( 0 == id.level() );
      CHECK( "H1_e0" == id.name() );
    } // THEN
  } // GIVEN

  GIVEN( "valid ElementID instances" ) {

    NuclideID id1( 1, 1, 0 );
    NuclideID id2( 2, 4, 0 );

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
