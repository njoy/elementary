#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/ReactionID.hpp"

// other includes
#include <map>
#include <unordered_map>
#include "elementary/ParticlePairID.hpp"
#include "elementary/ParticleTupleID.hpp"

// convenience typedefs
using ParticleID = njoy::elementary::ParticleID;
using ParticlePairID = njoy::elementary::ParticlePairID;
using ParticleTupleID = njoy::elementary::ParticleTupleID;
using ReactionType = njoy::elementary::ReactionType;
using ReactionID = njoy::elementary::ReactionID;

SCENARIO( "ParticlePairID" ) {

  GIVEN( "valid data for a ReactionID" ) {

    THEN( "a ReactionID can be created" ) {

      // particle pair identifiers as separate arguments
      ReactionID id1( ParticlePairID( "n,Fe56" ), ParticlePairID( "n,Fe56" ) );
      CHECK( "n,Fe56->n,Fe56" == id1.symbol() );

      // particle pair and tuple identifiers as separate arguments
      ReactionID id2( ParticlePairID( "n,Fe56" ), ParticleTupleID( "n,Fe56" ) );
      CHECK( "n,Fe56->n,Fe56" == id2.symbol() );

      // using a string
      ReactionID id3( "n,Fe56->n,Fe56" );
      CHECK( "n,Fe56->n,Fe56" == id3.symbol() );

      id3 = ReactionID( "n,Fe56->capture" );
      CHECK( "n,Fe56->capture" == id3.symbol() );

      // using a reaction type
      ReactionID id4( ParticleID( "n" ), ParticleID( "Fe56" ), ReactionType( "elastic" ) );
      CHECK( "n,Fe56->n,Fe56" == id4.symbol() );

      id4 = ReactionID( ParticleID( "n" ), ParticleID( "Fe56" ), ReactionType( 2 ) );
      CHECK( "n,Fe56->n,Fe56" == id4.symbol() );

      id4 = ReactionID( ParticleID( "n" ), ParticleID( "Fe56_e1" ), ReactionType( 2 ) );
      CHECK( "n,Fe56_e1->n,Fe56" == id4.symbol() );

      id4 = ReactionID( ParticleID( "n" ), ParticleID( "Fe56" ), ReactionType( 51 ) );
      CHECK( "n,Fe56->n,Fe56_e1" == id4.symbol() );

      id4 = ReactionID( ParticleID( "n" ), ParticleID( "Fe56" ), ReactionType( 1 ) );
      CHECK( "n,Fe56->total" == id4.symbol() );

      id4 = ReactionID( ParticleID( "n" ), ParticleID( "Fe56" ), ReactionType( 5 ) );
      CHECK( "n,Fe56->anything" == id4.symbol() );

      id4 = ReactionID( ParticleID( "n" ), ParticleID( "Fe56" ), ReactionType( 4 ) );
      CHECK( "n,Fe56->inelastic" == id4.symbol() );

      id4 = ReactionID( ParticleID( "n" ), ParticleID( "Fe56" ), ReactionType( 102 ) );
      CHECK( "n,Fe56->capture" == id4.symbol() );

      id4 = ReactionID( ParticleID( "n" ), ParticleID( "Fe56" ), ReactionType( 16 ) );
      CHECK( "n,Fe56->n,n,Fe55" == id4.symbol() );

      id4 = ReactionID( ParticleID( "n" ), ParticleID( "Fe56" ), ReactionType( 649 ) );
      CHECK( "n,Fe56->p,Mn56[continuum]" == id4.symbol() );
    } // THEN
  } // GIVEN

  GIVEN( "valid ReactionID" ) {

    THEN( "the incident and outgoing identifiers can be extracted" ) {

      ReactionID id( "n,Fe56->n,Fe56_e1" );

      CHECK( ParticlePairID( "n,Fe56" ) == id.incident() );
      CHECK( ParticleTupleID( "n,Fe56_e1" ) == id.outgoing() );
    } // THEN
  } // GIVEN

  GIVEN( "valid ReactionID instances" ) {

    ReactionID id1( ParticlePairID( "n,Fe56" ), ParticlePairID( "n,Fe56" ) );
    ReactionID id2( ParticlePairID( "n,Fe56" ), ParticlePairID( "n,Fe56_e1" ) );

    THEN( "instances can be compared" ) {

      CHECK( ( id1 <  id1 ) == false );
      CHECK( ( id1 <= id1 ) == true );
      CHECK( ( id1 >  id1 ) == false );
      CHECK( ( id1 >= id1 ) == true );
      CHECK( ( id1 == id1 ) == true );
      CHECK( ( id1 != id1 ) == false );
      CHECK( ( id1 <  id2 ) == true );
      CHECK( ( id1 <= id2 ) == true );
      CHECK( ( id1 >  id2 ) == false );
      CHECK( ( id1 >= id2 ) == false );
      CHECK( ( id1 == id2 ) == false );
      CHECK( ( id1 != id2 ) == true );
      CHECK( ( id2 <  id1 ) == false );
      CHECK( ( id2 <= id1 ) == false );
      CHECK( ( id2 >  id1 ) == true );
      CHECK( ( id2 >= id1 ) == true );
      CHECK( ( id2 == id1 ) == false );
      CHECK( ( id2 != id1 ) == true );
    } // THEN

    THEN( "instances can be used as keys in a std::map" ) {

      std::map< ReactionID, std::string > map{

        { id1, "1" }, { id2, "2" }
      };

      CHECK( map[ id1 ] == "1" );
      CHECK( map[ id2 ] == "2" );
      CHECK( map[ ReactionID( "n,Fe56->n,Fe56" ) ] == "1" );
      CHECK( map[ ReactionID( "n,Fe56->n,Fe56_e1" ) ] == "2" );
    } // THEN

    THEN( "instances can be used as keys in a std::unordered_map" ) {

      std::unordered_map< ReactionID, std::string > map{

        { id1, "1" }, { id2, "2" }
      };

      CHECK( map[ id1 ] == "1" );
      CHECK( map[ id2 ] == "2" );
      CHECK( map[ ReactionID( "n,Fe56->n,Fe56" ) ] == "1" );
      CHECK( map[ ReactionID( "n,Fe56->n,Fe56_e1" ) ] == "2" );
    } // THEN
  } // GIVEN

  GIVEN( "invalid data for an ReactionID" ) {

    THEN( "an exception is thrown" ) {

      CHECK_THROWS( ReactionID( "not a reaction ID" ) );
      CHECK_THROWS( ReactionID( "n,Fe56" ) ); // valid particle pair, no reaction
    } // THEN
  } // GIVEN
} // SCENARIO
