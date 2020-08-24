#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/ParticleTupleID.hpp"

// other includes
#include "elementary/ParticleID.hpp"

// convenience typedefs
using ParticlePairID = njoy::elementary::ParticlePairID;
using ParticleTupleID = njoy::elementary::ParticleTupleID;
using ParticleID = njoy::elementary::ParticleID;

SCENARIO( "ParticleTupleID" ) {

  GIVEN( "valid data for a ParticleTupleID" ) {

    THEN( "a ParticleTupleID can be created" ) {

      // particle identifiers as separate arguments
      ParticleTupleID id1( ParticleID( "n" ), ParticleID( "Fe56" ) );
      CHECK( "n,Fe56" == id1.symbol() );

      ParticleTupleID id2( ParticleID( "n" ), ParticleID( "p" ),
                           ParticleID( "Fe56" ) );
      CHECK( "n,p,Fe56" == id2.symbol() );

      ParticleTupleID id3( ParticleID( "n" ), ParticleID( "p" ),
                           ParticleID( "he4" ), ParticleID( "Fe56" ) );
      CHECK( "n,p,he4,Fe56" == id3.symbol() );

      // using a vector
      std::vector< ParticleID > identifiers = {
        ParticleID( "n" ), ParticleID( "p" ),
        ParticleID( "he4" ), ParticleID( "Fe56" ) };
      ParticleTupleID id4( identifiers );
      CHECK( "n,p,he4,Fe56" == id4.symbol() );

      // using a string - multiple particles
      ParticleTupleID id5( "n,p,Fe56" );
      CHECK( "n,p,Fe56" == id5.symbol() );

      // using a string - from a registered reaction type
      ParticleTupleID id6( "total" );
      CHECK( "total" == id6.symbol() );

      id6 = ParticleTupleID( "capture" );
      CHECK( "capture" == id6.symbol() );

      // using a particle pair
      ParticleTupleID id7( ParticlePairID( ParticleID( "n" ),
                                           ParticleID( "Fe56" ) ) );
      CHECK( "n,Fe56" == id7.symbol() );
    } // THEN
  } // GIVEN

  GIVEN( "valid ParticleTupleID" ) {

    THEN( "the particles and residual identifiers can be extracted" ) {

      ParticleTupleID id1( "n,Fe56" );

      auto particles = id1.particles();
      auto residual = id1.residual();

      CHECK( 1 == particles.size() );
      CHECK( ParticleID( "n" ) == particles[0] );
      CHECK( ParticleID( "Fe56" ) == residual );

      ParticleTupleID id2( "n,p,he4,Fe56" );

      particles = id2.particles();
      residual = id2.residual();

      CHECK( 3 == particles.size() );
      CHECK( ParticleID( "n" ) == particles[0] );
      CHECK( ParticleID( "p" ) == particles[1] );
      CHECK( ParticleID( "he4" ) == particles[2] );
      CHECK( ParticleID( "Fe56" ) == residual );
    } // THEN
  } // GIVEN

  GIVEN( "valid ParticleTupleID instances" ) {

    ParticleTupleID id1( ParticleID( "n" ), ParticleID( "Fe56" ) );
    ParticleTupleID id2( ParticleID( "n" ), ParticleID( "Fe56_e1" ) );

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

  GIVEN( "invalid data for an ParticleTupleID" ) {

    THEN( "an exception is thrown" ) {

      CHECK_THROWS( ParticleTupleID( "not a particle tuple ID" ) );
      CHECK_THROWS( ParticleTupleID( "Fe56" ) );    // single valid particle
      CHECK_THROWS( ParticleTupleID( "elastic" ) ); // registered, not allowed
    } // THEN
  } // GIVEN
} // SCENARIO
