#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/Identifier.hpp"

// other includes
#include <map>
#include <unordered_map>

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

namespace std {

  // std::hash override for the Identifier class
  template <>
  struct hash< TestID > {

    size_t operator()( const TestID& key ) const {

      return key.hash();
    }
  };

} // namespace std

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

    THEN( "instances can be used as keys in a std::map" ) {

      std::map< TestID, std::string > map{

        { id1, "1" }, { id2, "2" }
      };

      CHECK( map[ id1 ] == "1" );
      CHECK( map[ id2 ] == "2" );
      CHECK( map[ TestID( "a" ) ] == "1" );
      CHECK( map[ TestID( "b" ) ] == "2" );
    } // THEN

    THEN( "instances can be used as keys in a std::unordered_map" ) {

      std::unordered_map< TestID, std::string > map{

        { id1, "1" }, { id2, "2" }
      };

      CHECK( map[ id1 ] == "1" );
      CHECK( map[ id2 ] == "2" );
      CHECK( map[ TestID( "a" ) ] == "1" );
      CHECK( map[ TestID( "b" ) ] == "2" );
    } // THEN
  } // GIVEN

  GIVEN( "invalid identifiers" ) {

    THEN( "constructing an Identifier throws an exception" ) {

      CHECK_THROWS( Size5ID( "notValidSize5Id" ) );
    } // THEN
  } // GIVEN
} // SCENARIO
