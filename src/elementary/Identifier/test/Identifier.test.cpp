#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/Identifier.hpp"

// convenience typedefs
template < typename Tag >
using Identifier = njoy::elementary::Identifier< Tag >;

// dummy template type and validation function
struct Dummy {};

namespace njoy {
namespace elementary {

  // specialised validateIdentifier function for the Dummy tag
  template <> bool validateIdentifier< Dummy >( const std::string& identifier ) noexcept {

    if ( identifier.size() != 5 ) { return false; }
    return true;
  }
}
}

SCENARIO( "Identifier" ) {

  GIVEN( "valid data for an Identifier" ) {

    THEN( "an Identifier can be created using the default validation "
          "function" ) {

      // default constructor
      Identifier< double > defaultId;
      CHECK( "" == defaultId.string() );

      // create new id
      Identifier< double > id( "myId" );
      CHECK( "myId" == id.string() );
    } // THEN

    THEN( "an Identifier can be created with a user defined validation "
          "function" ) {

      // default constructor
      Identifier< Dummy > defaultId;
      CHECK( "" == defaultId.string() );

      // create new id
      Identifier< Dummy > id( "size5" );
      CHECK( "size5" == id.string() );
    } // THEN

    THEN( "an Identifier can be streamed from an input stream" ) {

      std::istringstream in( "size5 SIZE5");
      Identifier< Dummy > id;

      in >> id;
      CHECK( "size5" ==  id.string() );
      CHECK( in.fail() == false );
      CHECK( in.eof() == false );

      in >> id;
      CHECK( "SIZE5" ==  id.string() );
      CHECK( in.fail() == false );
      CHECK( in.eof() == true );
    } // THEN
  } // GIVEN

  GIVEN( "valid Identifier instances" ) {

    Identifier< double > id1( "a" );
    Identifier< double > id2( "b" );

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

    THEN( "instances can be streamed to an output stream" ) {

      std::ostringstream out;
      Identifier< double > id( "myId" );

      out << id;

      CHECK( "myId" == out.str() );
    } // THEN
  } // GIVEN

  GIVEN( "invalid identifiers" ) {

    THEN( "constructing an Identifier throws an exception" ) {

      CHECK_THROWS( Identifier< Dummy >( "notValidId" ) );
    } // THEN

    THEN( "streaming an Identifier throws an exception" ) {

      Identifier< Dummy > id( "size5" );
      std::istringstream in( "this should fail");

      in >> id;
      CHECK( in.fail() == true );
      CHECK( "size5" == id.string() );

      in.clear();
      std::string temp;
      std::getline( in, temp );
      CHECK( "this should fail" == temp );
    } // THEN
  } // GIVEN
} // SCENARIO
