#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/src/absorb.hpp"
#include "elementary/src/emit.hpp"
#include "elementary/src/join.hpp"
#include "elementary/src/split.hpp"

// other includes
#include "elementary/FundamentalParticleID.hpp"
#include "elementary/IsotopeID.hpp"
#include "elementary/NucleusID.hpp"
#include "elementary/NuclideID.hpp"
#include "elementary/ParticleID.hpp"

// convenience typedefs
using FundamentalParticleID = njoy::elementary::FundamentalParticleID;
using IsotopeID = njoy::elementary::IsotopeID;
using NucleusID = njoy::elementary::NucleusID;
using NuclideID = njoy::elementary::NuclideID;
using ParticleID = njoy::elementary::ParticleID;

SCENARIO( "absorb" ) {

  GIVEN( "valid identifiers" ) {

    FundamentalParticleID n( "n" );
    IsotopeID isotope_h2( "h2" );
    IsotopeID isotope_h1( "h1" );
    NucleusID h1( "h1" );
    NuclideID H1( "H1" );
    ParticleID particle_h1( "h1" );

    THEN( "an IsotopeID can be created by absorption" ) {

      CHECK( isotope_h2 == njoy::elementary::absorb( isotope_h1, n ) );
      CHECK( isotope_h2 == njoy::elementary::absorb( h1, n ) );
      CHECK( isotope_h2 == njoy::elementary::absorb( H1, n ) );
      CHECK( isotope_h2 == njoy::elementary::absorb( particle_h1, n ) );
    } // THEN
  } // GIVEN
} // SCENARIO

SCENARIO( "emit" ) {

  GIVEN( "valid identifiers" ) {

    FundamentalParticleID n( "n" );
    IsotopeID isotope_h1( "h1" );
    IsotopeID isotope_h2( "h2" );
    NucleusID h2( "h2" );
    NuclideID H2( "H2" );
    ParticleID particle_h2( "h2" );

    THEN( "an IsotopeID can be created by emission" ) {

      CHECK( isotope_h1 == njoy::elementary::emit( isotope_h2, n ) );
      CHECK( isotope_h1 == njoy::elementary::emit( h2, n ) );
      CHECK( isotope_h1 == njoy::elementary::emit( H2, n ) );
      CHECK( isotope_h1 == njoy::elementary::emit( particle_h2, n ) );
    } // THEN
  } // GIVEN
} // SCENARIO

SCENARIO( "join" ) {

  GIVEN( "a vector of strings" ) {

    std::vector< std::string > empty = {};
    std::vector< std::string > one = { "ab" };
    std::vector< std::string > strings = { "ab", "cd", "ef" };

    THEN( "the strings can be joined together with a separator" ) {

      CHECK( "" == njoy::elementary::join( empty, "->" ) );
      CHECK( "ab" == njoy::elementary::join( one, "->" ) );
      CHECK( "ab->cd->ef" == njoy::elementary::join( strings, "->" ) );
    } // THEN

    THEN( "the strings can be joined together without a separator" ) {

      CHECK( "" == njoy::elementary::join( empty ) );
      CHECK( "ab" == njoy::elementary::join( one ) );
      CHECK( "abcdef" == njoy::elementary::join( strings ) );
    } // THEN
  } // GIVEN
} // SCENARIO

SCENARIO( "split" ) {

  GIVEN( "a string" ) {

    std::string empty = "";
    std::string none = "abcdef";
    std::string middle = "ab->cd->ef";
    std::string start = "->ab->cd->ef";
    std::string end = "ab->cd->ef->";

    THEN( "the strings can be split" ) {

      auto result = njoy::elementary::split( empty, "->" );
      CHECK( 1 == result.size() );
      CHECK( "" == result[0] );

      result = njoy::elementary::split( none, "->" );
      CHECK( 1 == result.size() );
      CHECK( "abcdef" == result[0] );

      result = njoy::elementary::split( middle, "->" );
      CHECK( 3 == result.size() );
      CHECK( "ab" == result[0] );
      CHECK( "cd" == result[1] );
      CHECK( "ef" == result[2] );

      result = njoy::elementary::split( start, "->" );
      CHECK( 4 == result.size() );
      CHECK( "" == result[0] );
      CHECK( "ab" == result[1] );
      CHECK( "cd" == result[2] );
      CHECK( "ef" == result[3] );

      result = njoy::elementary::split( end, "->" );
      CHECK( 4 == result.size() );
      CHECK( "ab" == result[0] );
      CHECK( "cd" == result[1] );
      CHECK( "ef" == result[2] );
      CHECK( "" == result[3] );
    } // THEN
  } // GIVEN
} // SCENARIO
