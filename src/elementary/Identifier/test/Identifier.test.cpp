#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/Identifier.hpp"

// convenience typedefs
template < typename Derived >
using Identifier = njoy::elementary::Identifier< Derived >;

class TestID : public Identifier< TestID > {

  friend Identifier< TestID >;

  static bool validate( const std::string& ) { return true; }
  static std::string name() { return "test ID"; }

public:

  TestID( const std::string& identifier ) : Identifier( identifier ) {};
};

class Size5ID : public Identifier< Size5ID > {

  friend Identifier< Size5ID >;

  static bool validate( const std::string& string ) {

    return string.size() == 5;
  }
  static std::string name() { return "test ID"; }

public:

  Size5ID( const std::string& identifier ) : Identifier( identifier ) {};
};

SCENARIO( "Identifier" ) {

  GIVEN( "valid data for an Identifier" ) {

    THEN( "an Identifier can be created" ) {

      TestID id1( "myId" );
      CHECK( "myId" == id1.symbol() );

      Size5ID id2( "size5" );
      CHECK( "size5" == id2.symbol() );
    } // THEN
  } // GIVEN

  GIVEN( "valid Identifier instances" ) {

    TestID id1( "a" );
    TestID id2( "b" );

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

  GIVEN( "invalid identifiers" ) {

    THEN( "constructing an Identifier throws an exception" ) {

      CHECK_THROWS( Size5ID( "notValidSize5Id" ) );
    } // THEN
  } // GIVEN
} // SCENARIO
