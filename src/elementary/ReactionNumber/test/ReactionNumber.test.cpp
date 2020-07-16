#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/ReactionNumber.hpp"

// other includes
#include "elementary/ParticleID.hpp"

// convenience typedefs
using ReactionNumber = njoy::elementary::ReactionNumber;
using ParticleID = njoy::elementary::ParticleID;

SCENARIO( "ReactionNumber" ) {

  const ParticleID neutron( "n" );
  const ParticleID proton( "p" );
  const ParticleID deuteron( "h2" );
  const ParticleID triton( "h3" );
  const ParticleID helion( "he3" );
  const ParticleID alpha( "he4" );

  GIVEN( "valid data for a ReactionNumber" ) {

    THEN( "a ReactionNumber can be created" ) {

      ReactionNumber id1( 1 );
      CHECK( 1 == id1.mt() );
      CHECK( "total" == id1.name() );
      CHECK( 0 == id1.particles().size() );

      ReactionNumber id2( 2 );
      CHECK( 2 == id2.mt() );
      CHECK( "elastic" == id2.name() );
      CHECK( 0 == id2.particles().size() );

      ReactionNumber id11( 11 );
      CHECK( 11 == id11.mt() );
      CHECK( "2nd" == id11.name() );
      CHECK( 3 == id11.particles().size() );
      CHECK( neutron == id11.particles()[0] );
      CHECK( neutron == id11.particles()[1] );
      CHECK( deuteron == id11.particles()[2] );

      ReactionNumber id16( 16 );
      CHECK( 16 == id16.mt() );
      CHECK( "2n" == id16.name() );
      CHECK( 2 == id16.particles().size() );
      CHECK( neutron == id16.particles()[0] );
      CHECK( neutron == id16.particles()[1] );

      ReactionNumber id17( 17 );
      CHECK( 17 == id17.mt() );
      CHECK( "3n" == id17.name() );
      CHECK( 3 == id17.particles().size() );
      CHECK( neutron == id17.particles()[0] );
      CHECK( neutron == id17.particles()[1] );
      CHECK( neutron == id17.particles()[2] );

      ReactionNumber id22( 22 );
      CHECK( 22 == id22.mt() );
      CHECK( "na" == id22.name() );
      CHECK( 2 == id22.particles().size() );
      CHECK( neutron == id22.particles()[0] );
      CHECK( alpha == id22.particles()[1] );

      ReactionNumber id23( 23 );
      CHECK( 23 == id23.mt() );
      CHECK( "n3a" == id23.name() );
      CHECK( 4 == id23.particles().size() );
      CHECK( neutron == id23.particles()[0] );
      CHECK( alpha == id23.particles()[1] );
      CHECK( alpha == id23.particles()[2] );
      CHECK( alpha == id23.particles()[3] );

      ReactionNumber id24( 24 );
      CHECK( 24 == id24.mt() );
      CHECK( "2na" == id24.name() );
      CHECK( 3 == id24.particles().size() );
      CHECK( neutron == id24.particles()[0] );
      CHECK( neutron == id24.particles()[1] );
      CHECK( alpha == id24.particles()[2] );

      ReactionNumber id37( 37 );
      CHECK( 37 == id37.mt() );
      CHECK( "4n" == id37.name() );
      CHECK( 4 == id37.particles().size() );
      CHECK( neutron == id37.particles()[0] );
      CHECK( neutron == id37.particles()[1] );
      CHECK( neutron == id37.particles()[2] );
      CHECK( neutron == id37.particles()[3] );
    } // THEN
  } // GIVEN

  GIVEN( "invalid data for an ReactionNumber" ) {

    THEN( "an exception is thrown" ) {

      CHECK_THROWS( ReactionNumber( "not a reaction name or alternative" ) );
      CHECK_THROWS( ReactionNumber( 0 ) );
      CHECK_THROWS( ReactionNumber( -1 ) );
    } // THEN
  } // GIVEN
} // SCENARIO
