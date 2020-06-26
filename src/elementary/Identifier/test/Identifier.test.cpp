#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/Identifier.hpp"

// convenience typedefs
using Identifier = njoy::elementary::Identifier;

// dummy template type and validation function
struct Dummy {};

namespace njoy {
namespace elementary {

  // specialised validateIdentifier function for the Dummy tag
  template <> bool validateIdentifier< Dummy >( const std::string& identifier ) {

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
      Identifer< double > defaultId;
      CHECK( "" == defaultId.string() );

      // create new id
      Identifer< double > id( "myId" );
      CHECK( "myId" == defaultId.string() );
    } // THEN

    THEN( "an Identifier can be created with a user defined validation "
          "function" ) {

      // default constructor
      Identifer< Dummy > defaultId;
      CHECK( "" == defaultId.string() );

      // create new id
      Identifer< Dummy > id( "size5" );
      CHECK( "size5" == defaultId.string() );
    } // THEN

    THEN( "an Identifier can be streamed from an input stream" ) {

      std::istringstream in( "size5 SIZE5");
      Identifier< Dummy > id;

      in >> id;
      CHECK( size5 ==  id.string() );
      CHECK_TRUE( !in.fail() );
      CHECK_TRUE( !in.eof() );

      in >> id;
      CHECK( SIZE5 ==  id.string() );
      CHECK_TRUE( !in.fail() );
      CHECK_TRUE( !in.eof() );
    } // THEN
  } // GIVEN

  GIVEN( "valid Identifier instances" ) {

    Identifer< double > id1( "a" );
    Identifer< double > id2( "b" );

    THEN( "instances can be compared" ) {

      CHECK_FALSE( id1 <  id1 );
      CHECK_TRUE( id1 == id1 );
      CHECK_FALSE( id1 != id1 );
      CHECK_TRUE( id1 <  id2 );
      CHECK_FALSE( id1 == id2 );
      CHECK_TRUE( id1 != id2 );
      CHECK_FALSE( id2 <  id1 );
      CHECK_FALSE( id2 == id1 );
      CHECK_TRUE( id2 != id1 );
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

      CHECK_THROW( Identifier< Dummy >( "notValidId" ) );
    } // THEN

    THEN( "streaming an Identifier throws an exception" ) {

      Identifier< Dummy > id( "size5" );
      std::istringstream in( "this should fail");

      in >> id;
      CHECK_TRUE( in.fail() );
      CHECK_TRUE( "size5" == id.string() );

      in.clear();
      std::string temp;
      std::getline( in, temp );
      CHECK( "this should fail" == temp );
    } // THEN
  } // GIVEN
} // SCENARIO
