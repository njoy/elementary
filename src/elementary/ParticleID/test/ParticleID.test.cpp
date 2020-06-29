#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/ParticleID.hpp"

// other includes
#include "elementary/FundamentalParticleID.hpp"
#include "elementary/NucleusID.hpp"
#include "elementary/NuclideID.hpp"

// convenience typedefs
using ParticleID = njoy::elementary::ParticleID;
using FundamentalParticleID = njoy::elementary::FundamentalParticleID;
using NucleusID = njoy::elementary::NucleusID;
using NuclideID = njoy::elementary::NuclideID;

SCENARIO( "ParticleID" ) {

  GIVEN( "valid data for a ParticleID" ) {

    THEN( "a ParticleID can be created" ) {

      ParticleID id( FundamentalParticleID( "n" ) );
      CHECK( "n" == id.symbol() );
      CHECK( "neutron" == id.name() );

      id = ParticleID( NucleusID( 1, 2, 0 ) );
      CHECK( "h2" == id.symbol() );
      CHECK( "h2" == id.name() );

      id = ParticleID( NuclideID( 1, 2, 0 ) );
      CHECK( "H2" == id.symbol() );
      CHECK( "H2" == id.name() );
    } // THEN
  } // GIVEN

  GIVEN( "valid ParticleID instances" ) {

    // fundamental particle < nucleus
    ParticleID id1 = ParticleID( FundamentalParticleID( "n" ) );
    ParticleID id2 = ParticleID( NucleusID( 2, 4, 0 ) );

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

    // nucleus < nuclide for the same isotope
    id1 = ParticleID( NucleusID( 2, 4, 0 ) );
    id2 = ParticleID( NuclideID( 2, 4, 0 ) );

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
