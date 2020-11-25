#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/NuclideID.hpp"

// other includes
#include <map>
#include <unordered_map>
#include "elementary/ElementID.hpp"
#include "elementary/IsotopeID.hpp"
#include "elementary/Level.hpp"

// convenience typedefs
using ElementID = njoy::elementary::ElementID;
using IsotopeID = njoy::elementary::IsotopeID;
using Level = njoy::elementary::Level;
using NuclideID = njoy::elementary::NuclideID;

SCENARIO( "NuclideID" ) {

  GIVEN( "valid data for a NuclideID" ) {

    THEN( "a NuclideID can be created" ) {

      NuclideID id( 1, 1, 0 );
      CHECK( IsotopeID( 1, 1 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( Level( 0 ) == id.level() );
      CHECK( 1001 == id.za() );
      CHECK( "H1" == id.symbol() );
      CHECK( "H1" == id.name() );

      id = NuclideID( 1001, 0 );
      CHECK( IsotopeID( 1, 1 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( Level( 0 ) == id.level() );
      CHECK( 1001 == id.za() );
      CHECK( "H1" == id.symbol() );
      CHECK( "H1" == id.name() );

      id = NuclideID( "H1" );
      CHECK( IsotopeID( 1, 1 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( Level( 0 ) == id.level() );
      CHECK( 1001 == id.za() );
      CHECK( "H1" == id.symbol() );
      CHECK( "H1" == id.name() );

      id = NuclideID( "H1_e0" );
      CHECK( IsotopeID( 1, 1 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( Level( 0 ) == id.level() );
      CHECK( 1001 == id.za() );
      CHECK( "H1" == id.symbol() );
      CHECK( "H1" == id.name() );

      id = NuclideID( 1, 1, 1 );
      CHECK( IsotopeID( 1, 1 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( Level( 1 ) == id.level() );
      CHECK( 1001 == id.za() );
      CHECK( "H1_e1" == id.symbol() );
      CHECK( "H1_e1" == id.name() );

      id = NuclideID( 1001, 1 );
      CHECK( IsotopeID( 1, 1 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( Level( 1 ) == id.level() );
      CHECK( 1001 == id.za() );
      CHECK( "H1_e1" == id.symbol() );
      CHECK( "H1_e1" == id.name() );

      id = NuclideID( "H1_e1" );
      CHECK( IsotopeID( 1, 1 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( Level( 1 ) == id.level() );
      CHECK( 1001 == id.za() );
      CHECK( "H1_e1" == id.symbol() );
      CHECK( "H1_e1" == id.name() );

      id = NuclideID( 1, 0, 0 );
      CHECK( IsotopeID( 1, 0 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 0 == id.mass() );
      CHECK( Level( 0 ) == id.level() );
      CHECK( 1000 == id.za() );
      CHECK( "H0" == id.symbol() );
      CHECK( "H0" == id.name() );

      id = NuclideID( "H0" );
      CHECK( IsotopeID( 1, 0 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 0 == id.mass() );
      CHECK( Level( 0 ) == id.level() );
      CHECK( 1000 == id.za() );
      CHECK( "H0" == id.symbol() );
      CHECK( "H0" == id.name() );

      auto continuum = njoy::elementary::Level::continuum;

      id = NuclideID( 1, 1, continuum );
      CHECK( IsotopeID( 1, 1 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( Level( continuum ) == id.level() );
      CHECK( 1001 == id.za() );
      CHECK( "H1[continuum]" == id.symbol() );
      CHECK( "H1[continuum]" == id.name() );

      id = NuclideID( 1001, continuum );
      CHECK( IsotopeID( 1, 1 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( Level( continuum ) == id.level() );
      CHECK( 1001 == id.za() );
      CHECK( "H1[continuum]" == id.symbol() );
      CHECK( "H1[continuum]" == id.name() );

      id = NuclideID( "H1[continuum]" );
      CHECK( IsotopeID( 1, 1 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( Level( continuum ) == id.level() );
      CHECK( 1001 == id.za() );
      CHECK( "H1[continuum]" == id.symbol() );
      CHECK( "H1[continuum]" == id.name() );
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

    THEN( "instances can be used as keys in a std::map" ) {

      std::map< NuclideID, std::string > map{

        { id1, "1" }, { id2, "2" }
      };

      CHECK( map[ id1 ] == "1" );
      CHECK( map[ id2 ] == "2" );
      CHECK( map[ NuclideID( "H1" ) ] == "1" );
      CHECK( map[ NuclideID( "He4" ) ] == "2" );
    } // THEN

    THEN( "instances can be used as keys in a std::unordered_map" ) {

      std::unordered_map< NuclideID, std::string > map{

        { id1, "1" }, { id2, "2" }
      };

      CHECK( map[ id1 ] == "1" );
      CHECK( map[ id2 ] == "2" );
      CHECK( map[ NuclideID( "H1" ) ] == "1" );
      CHECK( map[ NuclideID( "He4" ) ] == "2" );
    } // THEN
  } // GIVEN

  GIVEN( "invalid data for an NuclideID" ) {

    THEN( "an exception is thrown" ) {

      CHECK_THROWS( NuclideID( -1, 0, 0 ) );  // negative element number
      CHECK_THROWS( NuclideID( 1, -1, 0 ) );  // negative mass number
      CHECK_THROWS( NuclideID( 119, 1, 0 ) ); // element above 118
      CHECK_THROWS( NuclideID( 1, 400, 0 ) ); // mass above 300
      CHECK_THROWS( NuclideID( 0, 0 ) );      // zero za
      CHECK_THROWS( NuclideID( -1, 0 ) );     // negative za
      CHECK_THROWS( NuclideID( "not a nuclide" ) ); // bad string
      CHECK_THROWS( NuclideID( "H400" ) ); // bad string: mass to high
    } // THEN
  } // GIVEN
} // SCENARIO
