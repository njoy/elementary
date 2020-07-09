#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/JoinedIdentifier.hpp"

// convenience typedefs
template < typename Derived >
using JoinedIdentifier = njoy::elementary::JoinedIdentifier< Derived >;

class TestID : public JoinedIdentifier< TestID > {

  friend Identifier< TestID >;
  friend JoinedIdentifier< TestID >;

  static bool validate( const std::string& ) { return true; }
  static std::string name() { return "test ID"; }
  static std::string separator() { return " "; }

public:

  TestID( std::vector< std::string >&& identifiers ) :
    JoinedIdentifier( std::move( identifiers ) ) {};
};

SCENARIO( "JoinedIdentifier" ) {

  GIVEN( "valid data for a JoinedIdentifier" ) {

    THEN( "a JoinedIdentifier can be created" ) {

      TestID id1( { "myId", "Is", "Joined" } );
      CHECK( "myId Is Joined" == id1.symbol() );
    } // THEN
  } // GIVEN

  GIVEN( "valid Identifier instances" ) {

    TestID id1( { "a", "b" } );
    TestID id2( { "b", "c" } );

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
