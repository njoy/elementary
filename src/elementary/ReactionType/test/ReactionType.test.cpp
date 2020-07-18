#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/ReactionType.hpp"

// other includes
#include "elementary/ParticleID.hpp"

// convenience typedefs
using ReactionType = njoy::elementary::ReactionType;
using ParticleID = njoy::elementary::ParticleID;

SCENARIO( "ReactionType" ) {

  const ParticleID neutron( "n" );
  const ParticleID proton( "p" );
  const ParticleID deuteron( "h2" );
  const ParticleID triton( "h3" );
  const ParticleID helion( "he3" );
  const ParticleID alpha( "he4" );

  GIVEN( "strings and ints" ) {

    THEN( "it can be verified of they are registered" ) {

      CHECK( true == ReactionType::isRegistered( "total" ) );
      CHECK( true == ReactionType::isRegistered( 1 ) );

      CHECK( false == ReactionType::isRegistered( "not registered" ) );
      CHECK( false == ReactionType::isRegistered( 999 ) );
    } // THEN
  } // GIVEN

  GIVEN( "valid data for a ReactionType" ) {

    THEN( "a ReactionType can be created" ) {

      ReactionType id1( 1 );
      CHECK( 1 == id1.mt() );
      CHECK( "total" == id1.name() );
      CHECK( 0 == id1.particles().size() );

      ReactionType id2( 2 );
      CHECK( 2 == id2.mt() );
      CHECK( "elastic" == id2.name() );
      CHECK( 0 == id2.particles().size() );

      ReactionType id11( 11 );
      CHECK( 11 == id11.mt() );
      CHECK( "2nd" == id11.name() );
      CHECK( 3 == id11.particles().size() );
      CHECK( neutron == id11.particles()[0] );
      CHECK( neutron == id11.particles()[1] );
      CHECK( deuteron == id11.particles()[2] );

      ReactionType id16( 16 );
      CHECK( 16 == id16.mt() );
      CHECK( "2n(t)" == id16.name() );
      CHECK( 2 == id16.particles().size() );
      CHECK( neutron == id16.particles()[0] );
      CHECK( neutron == id16.particles()[1] );

      ReactionType id17( 17 );
      CHECK( 17 == id17.mt() );
      CHECK( "3n" == id17.name() );
      CHECK( 3 == id17.particles().size() );
      CHECK( neutron == id17.particles()[0] );
      CHECK( neutron == id17.particles()[1] );
      CHECK( neutron == id17.particles()[2] );

      ReactionType id22( 22 );
      CHECK( 22 == id22.mt() );
      CHECK( "na" == id22.name() );
      CHECK( 2 == id22.particles().size() );
      CHECK( neutron == id22.particles()[0] );
      CHECK( alpha == id22.particles()[1] );

      ReactionType id23( 23 );
      CHECK( 23 == id23.mt() );
      CHECK( "n3a" == id23.name() );
      CHECK( 4 == id23.particles().size() );
      CHECK( neutron == id23.particles()[0] );
      CHECK( alpha == id23.particles()[1] );
      CHECK( alpha == id23.particles()[2] );
      CHECK( alpha == id23.particles()[3] );

      ReactionType id24( 24 );
      CHECK( 24 == id24.mt() );
      CHECK( "2na" == id24.name() );
      CHECK( 3 == id24.particles().size() );
      CHECK( neutron == id24.particles()[0] );
      CHECK( neutron == id24.particles()[1] );
      CHECK( alpha == id24.particles()[2] );

      ReactionType id37( 37 );
      CHECK( 37 == id37.mt() );
      CHECK( "4n" == id37.name() );
      CHECK( 4 == id37.particles().size() );
      CHECK( neutron == id37.particles()[0] );
      CHECK( neutron == id37.particles()[1] );
      CHECK( neutron == id37.particles()[2] );
      CHECK( neutron == id37.particles()[3] );
    } // THEN
  } // GIVEN

  GIVEN( "invalid data for an ReactionType" ) {

    THEN( "an exception is thrown" ) {

      CHECK_THROWS( ReactionType( "not a reaction name or alternative" ) );
      CHECK_THROWS( ReactionType( 0 ) );
      CHECK_THROWS( ReactionType( -1 ) );
    } // THEN
  } // GIVEN
} // SCENARIO
