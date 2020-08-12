#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/ParticleID.hpp"

// other includes
#include "elementary/FundamentalParticleID.hpp"
#include "elementary/NucleusID.hpp"
#include "elementary/NuclideID.hpp"
#include "elementary/Level.hpp"

// convenience typedefs
using ParticleID = njoy::elementary::ParticleID;
using FundamentalParticleID = njoy::elementary::FundamentalParticleID;
using NucleusID = njoy::elementary::NucleusID;
using NuclideID = njoy::elementary::NuclideID;
using Level = njoy::elementary::Level;

SCENARIO( "ParticleID" ) {

  GIVEN( "valid data for a ParticleID" ) {

    THEN( "a ParticleID can be created" ) {

      ParticleID id( FundamentalParticleID( "n" ) );
      CHECK( "n" == id.symbol() );
      CHECK( "neutron" == id.name() );
      CHECK( 1 == id.za() );
      CHECK( Level( 0 ) == id.level() );
      CHECK( true == id.isFundamentalParticle() );
      CHECK( false == id.isNucleus() );
      CHECK( false == id.isNuclide() );

      id = ParticleID( "n" );
      CHECK( "n" == id.symbol() );
      CHECK( "neutron" == id.name() );
      CHECK( 1 == id.za() );
      CHECK( Level( 0 ) == id.level() );
      CHECK( true == id.isFundamentalParticle() );
      CHECK( false == id.isNucleus() );
      CHECK( false == id.isNuclide() );

      id = ParticleID( NucleusID( "h2" ) );
      CHECK( "h2" == id.symbol() );
      CHECK( "h2" == id.name() );
      CHECK( 1002 == id.za() );
      CHECK( Level( 0 ) == id.level() );
      CHECK( false == id.isFundamentalParticle() );
      CHECK( true == id.isNucleus() );
      CHECK( false == id.isNuclide() );

      id = ParticleID( "h2" );
      CHECK( "h2" == id.symbol() );
      CHECK( "h2" == id.name() );
      CHECK( 1002 == id.za() );
      CHECK( Level( 0 ) == id.level() );
      CHECK( false == id.isFundamentalParticle() );
      CHECK( true == id.isNucleus() );
      CHECK( false == id.isNuclide() );

      id = ParticleID( NucleusID( "h2_e1" ) );
      CHECK( "h2_e1" == id.symbol() );
      CHECK( "h2_e1" == id.name() );
      CHECK( 1002 == id.za() );
      CHECK( Level( 1 ) == id.level() );
      CHECK( false == id.isFundamentalParticle() );
      CHECK( true == id.isNucleus() );
      CHECK( false == id.isNuclide() );

      id = ParticleID( "h2_e1" );
      CHECK( "h2_e1" == id.symbol() );
      CHECK( "h2_e1" == id.name() );
      CHECK( 1002 == id.za() );
      CHECK( Level( 1 ) == id.level() );
      CHECK( false == id.isFundamentalParticle() );
      CHECK( true == id.isNucleus() );
      CHECK( false == id.isNuclide() );

      id = ParticleID( NuclideID( "H2" ) );
      CHECK( "H2" == id.symbol() );
      CHECK( "H2" == id.name() );
      CHECK( 1002 == id.za() );
      CHECK( Level( 0 ) == id.level() );
      CHECK( false == id.isFundamentalParticle() );
      CHECK( false == id.isNucleus() );
      CHECK( true == id.isNuclide() );

      id = ParticleID( "H2" );
      CHECK( "H2" == id.symbol() );
      CHECK( "H2" == id.name() );
      CHECK( 1002 == id.za() );
      CHECK( Level( 0 ) == id.level() );
      CHECK( false == id.isFundamentalParticle() );
      CHECK( false == id.isNucleus() );
      CHECK( true == id.isNuclide() );

      id = ParticleID( NuclideID( "H2_e1" ) );
      CHECK( "H2_e1" == id.symbol() );
      CHECK( "H2_e1" == id.name() );
      CHECK( 1002 == id.za() );
      CHECK( Level( 1 ) == id.level() );
      CHECK( false == id.isFundamentalParticle() );
      CHECK( false == id.isNucleus() );
      CHECK( true == id.isNuclide() );

      id = ParticleID( "H2_e1" );
      CHECK( "H2_e1" == id.symbol() );
      CHECK( "H2_e1" == id.name() );
      CHECK( 1002 == id.za() );
      CHECK( Level( 1 ) == id.level() );
      CHECK( false == id.isFundamentalParticle() );
      CHECK( false == id.isNucleus() );
      CHECK( true == id.isNuclide() );
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

    // dicrete level < continuum for the same isotope
    id1 = ParticleID( "He4_e5" );
    id2 = ParticleID( "He4[continuum]" );

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

  GIVEN( "invalid data for an ParticleID" ) {

    THEN( "an exception is thrown" ) {

      CHECK_THROWS( ParticleID( "not a particle ID" ) ); // bad string
      CHECK_THROWS( ParticleID( "H400" ) ); // bad string: mass to high
      CHECK_THROWS( ParticleID( "h400" ) ); // bad string: mass to high
    } // THEN
  } // GIVEN
} // SCENARIO
