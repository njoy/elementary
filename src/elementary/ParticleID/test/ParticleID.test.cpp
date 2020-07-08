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
      CHECK( 1 == id.za() );

      id = ParticleID( "n" );
      CHECK( "n" == id.symbol() );
      CHECK( "neutron" == id.name() );
      CHECK( 1 == id.za() );

      id = ParticleID( NucleusID( "h2" ) );
      CHECK( "h2" == id.symbol() );
      CHECK( "h2" == id.name() );
      CHECK( 1002 == id.za() );

      id = ParticleID( "h2" );
      CHECK( "h2" == id.symbol() );
      CHECK( "h2" == id.name() );
      CHECK( 1002 == id.za() );

      id = ParticleID( NuclideID( "H2" ) );
      CHECK( "H2" == id.symbol() );
      CHECK( "H2" == id.name() );
      CHECK( 1002 == id.za() );

      id = ParticleID( "H2" );
      CHECK( "H2" == id.symbol() );
      CHECK( "H2" == id.name() );
      CHECK( 1002 == id.za() );
    } // THEN
  } // GIVEN

  GIVEN( "valid ParticleID instances" ) {

    // fundamental particle < nucleus
    ParticleID id1 = ParticleID( "n" );
    ParticleID id2 = ParticleID( "he4" );

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
    id1 = ParticleID( "he4" );
    id2 = ParticleID( "He4" );

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
