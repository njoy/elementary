#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/NucleusID.hpp"

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
using NucleusID = njoy::elementary::NucleusID;

SCENARIO( "NucleusID" ) {

  GIVEN( "valid data for a NucleusID" ) {

    THEN( "a NucleusID can be created" ) {

      NucleusID id( 1, 1, 0 );
      CHECK( IsotopeID( 1, 1 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( Level( 0 ) == id.level() );
      CHECK( 1001 == id.za() );
      CHECK( "h1" == id.symbol() );
      CHECK( "h1" == id.name() );

      id = NucleusID( 1001, 0 );
      CHECK( IsotopeID( 1, 1 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( Level( 0 ) == id.level() );
      CHECK( 1001 == id.za() );
      CHECK( "h1" == id.symbol() );
      CHECK( "h1" == id.name() );

      id = NucleusID( "h1" );
      CHECK( IsotopeID( 1, 1 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( Level( 0 ) == id.level() );
      CHECK( 1001 == id.za() );
      CHECK( "h1" == id.symbol() );
      CHECK( "h1" == id.name() );

      id = NucleusID( "h1_e0" );
      CHECK( IsotopeID( 1, 1 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( Level( 0 ) == id.level() );
      CHECK( 1001 == id.za() );
      CHECK( "h1" == id.symbol() );
      CHECK( "h1" == id.name() );

      id = NucleusID( 1, 1, 1 );
      CHECK( IsotopeID( 1, 1 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( Level( 1 ) == id.level() );
      CHECK( 1001 == id.za() );
      CHECK( "h1_e1" == id.symbol() );
      CHECK( "h1_e1" == id.name() );

      id = NucleusID( 1001, 1 );
      CHECK( IsotopeID( 1, 1 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( Level( 1 ) == id.level() );
      CHECK( 1001 == id.za() );
      CHECK( "h1_e1" == id.symbol() );
      CHECK( "h1_e1" == id.name() );

      id = NucleusID( "h1_e1" );
      CHECK( IsotopeID( 1, 1 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( Level( 1 ) == id.level() );
      CHECK( 1001 == id.za() );
      CHECK( "h1_e1" == id.symbol() );
      CHECK( "h1_e1" == id.name() );

      id = NucleusID( 1, 0, 0 );
      CHECK( IsotopeID( 1, 0 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 0 == id.mass() );
      CHECK( Level( 0 ) == id.level() );
      CHECK( 1000 == id.za() );
      CHECK( "h0" == id.symbol() );
      CHECK( "h0" == id.name() );

      id = NucleusID( "h0" );
      CHECK( IsotopeID( 1, 0 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 0 == id.mass() );
      CHECK( Level( 0 ) == id.level() );
      CHECK( 1000 == id.za() );
      CHECK( "h0" == id.symbol() );
      CHECK( "h0" == id.name() );

      auto continuum = njoy::elementary::Level::continuum;

      id = NucleusID( 1, 1, continuum );
      CHECK( IsotopeID( 1, 1 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( Level( continuum ) == id.level() );
      CHECK( 1001 == id.za() );
      CHECK( "h1[continuum]" == id.symbol() );
      CHECK( "h1[continuum]" == id.name() );

      id = NucleusID( 1001, continuum );
      CHECK( IsotopeID( 1, 1 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( Level( continuum ) == id.level() );
      CHECK( 1001 == id.za() );
      CHECK( "h1[continuum]" == id.symbol() );
      CHECK( "h1[continuum]" == id.name() );

      id = NucleusID( "h1[continuum]" );
      CHECK( IsotopeID( 1, 1 ) == id.isotope() );
      CHECK( ElementID( 1 ) == id.element() );
      CHECK( 1 == id.mass() );
      CHECK( Level( continuum ) == id.level() );
      CHECK( 1001 == id.za() );
      CHECK( "h1[continuum]" == id.symbol() );
      CHECK( "h1[continuum]" == id.name() );
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

    THEN( "instances can be used as keys in a std::map" ) {

      std::map< NucleusID, std::string > map{

        { id1, "1" }, { id2, "2" }
      };

      CHECK( map[ id1 ] == "1" );
      CHECK( map[ id2 ] == "2" );
      CHECK( map[ NucleusID( "h1" ) ] == "1" );
      CHECK( map[ NucleusID( "he4" ) ] == "2" );
    } // THEN

    THEN( "instances can be used as keys in a std::unordered_map" ) {

      std::unordered_map< NucleusID, std::string > map{

        { id1, "1" }, { id2, "2" }
      };

      CHECK( map[ id1 ] == "1" );
      CHECK( map[ id2 ] == "2" );
      CHECK( map[ NucleusID( "h1" ) ] == "1" );
      CHECK( map[ NucleusID( "he4" ) ] == "2" );
    } // THEN
  } // GIVEN

  GIVEN( "invalid data for an NucleusID" ) {

    THEN( "an exception is thrown" ) {

      CHECK_THROWS( NucleusID( -1, 0, 0 ) );  // negative element number
      CHECK_THROWS( NucleusID( 1, -1, 0 ) );  // negative mass number
      CHECK_THROWS( NucleusID( 119, 1, 0 ) ); // element above 118
      CHECK_THROWS( NucleusID( 1, 400, 0 ) ); // mass above 300
      CHECK_THROWS( NucleusID( 0, 0 ) );      // zero za
      CHECK_THROWS( NucleusID( -1, 0 ) );     // negative za
      CHECK_THROWS( NucleusID( "not a nuclide" ) ); // bad string
      CHECK_THROWS( NucleusID( "H1" ) );   // bad string: capital element
      CHECK_THROWS( NucleusID( "H400" ) ); // bad string: mass to high
    } // THEN
  } // GIVEN
} // SCENARIO
