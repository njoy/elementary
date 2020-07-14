#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/src/absorb.hpp"
#include "elementary/src/emit.hpp"
#include "elementary/src/join.hpp"
#include "elementary/src/split.hpp"
#include "elementary/src/fromEndfReactionNumber.hpp"
#include "elementary/src/toEndfReactionNumber.hpp"

// other includes
#include "elementary/FundamentalParticleID.hpp"
#include "elementary/IsotopeID.hpp"
#include "elementary/NucleusID.hpp"
#include "elementary/NuclideID.hpp"
#include "elementary/ParticleID.hpp"
#include "elementary/ReactionID.hpp"

// convenience typedefs
using namespace njoy::elementary;

SCENARIO( "absorb" ) {

  GIVEN( "valid identifiers" ) {

    FundamentalParticleID n( "n" );
    IsotopeID isotope_h2( "h2" );
    IsotopeID isotope_h1( "h1" );
    NucleusID h1( "h1" );
    NuclideID H1( "H1" );
    ParticleID particle_h1( "h1" );

    THEN( "an IsotopeID can be created by absorption" ) {

      CHECK( isotope_h2 == absorb( isotope_h1, n ) );
      CHECK( isotope_h2 == absorb( h1, n ) );
      CHECK( isotope_h2 == absorb( H1, n ) );
      CHECK( isotope_h2 == absorb( particle_h1, n ) );
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

      CHECK( isotope_h1 == emit( isotope_h2, n ) );
      CHECK( isotope_h1 == emit( h2, n ) );
      CHECK( isotope_h1 == emit( H2, n ) );
      CHECK( isotope_h1 == emit( particle_h2, n ) );
    } // THEN
  } // GIVEN
} // SCENARIO

SCENARIO( "join" ) {

  GIVEN( "a vector of strings" ) {

    std::vector< std::string > empty = {};
    std::vector< std::string > one = { "ab" };
    std::vector< std::string > strings = { "ab", "cd", "ef" };

    THEN( "the strings can be joined together with a separator" ) {

      CHECK( "" == join( empty, "->" ) );
      CHECK( "ab" == join( one, "->" ) );
      CHECK( "ab->cd->ef" == join( strings, "->" ) );
    } // THEN

    THEN( "the strings can be joined together without a separator" ) {

      CHECK( "" == join( empty ) );
      CHECK( "ab" == join( one ) );
      CHECK( "abcdef" == join( strings ) );
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

      auto result = split( empty, "->" );
      CHECK( 1 == result.size() );
      CHECK( "" == result[0] );

      result = split( none, "->" );
      CHECK( 1 == result.size() );
      CHECK( "abcdef" == result[0] );

      result = split( middle, "->" );
      CHECK( 3 == result.size() );
      CHECK( "ab" == result[0] );
      CHECK( "cd" == result[1] );
      CHECK( "ef" == result[2] );

      result = split( start, "->" );
      CHECK( 4 == result.size() );
      CHECK( "" == result[0] );
      CHECK( "ab" == result[1] );
      CHECK( "cd" == result[2] );
      CHECK( "ef" == result[3] );

      result = split( end, "->" );
      CHECK( 4 == result.size() );
      CHECK( "ab" == result[0] );
      CHECK( "cd" == result[1] );
      CHECK( "ef" == result[2] );
      CHECK( "" == result[3] );
    } // THEN
  } // GIVEN
} // SCENARIO

SCENARIO( "fromEndfReactionNumber" ) {

  GIVEN( "a valid incident particle, target and MT number " ) {

    THEN( "the reaction identifier can be retrieved" ) {

      ParticleID neutron( "n" );
      ParticleID proton( "p" );
      ParticleID Fe56_e0( "Fe56" );

      // incident neutrons
      CHECK( ReactionID( "n,Fe56->n,Fe56" ) == fromEndfReactionNumber( neutron, Fe56_e0, 2 ) );

      CHECK( ReactionID( "n,Fe56->n,n,n,Fe54" ) == fromEndfReactionNumber( neutron, Fe56_e0, 17 ) );

      CHECK( ReactionID( "n,Fe56->n,n,n,n,Fe53" ) == fromEndfReactionNumber( neutron, Fe56_e0, 37 ) );

      // incident protons
      CHECK( ReactionID( "p,Fe56->p,Fe56" ) == fromEndfReactionNumber( proton, Fe56_e0, 2 ) );

      CHECK( ReactionID( "p,Fe56->n,n,n,Co54" ) == fromEndfReactionNumber( proton, Fe56_e0, 17 ) );

      CHECK( ReactionID( "p,Fe56->n,n,n,n,Co53" ) == fromEndfReactionNumber( proton, Fe56_e0, 37 ) );
    } // THEN
  } // GIVEN
} // SCENARIO

SCENARIO( "toEndfReactionNumber" ) {

  GIVEN( "a valid reaction identifier compatible with ENDF" ) {

    THEN( "the ENDF MT number can be retrieved" ) {

      // incident neutrons
      CHECK( 2 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56" ) ) );

/*      CHECK( 17 == toEndfReactionNumber( ReactionID( "n,Fe56->n,n,n,Fe54" ) ) );

      CHECK( 37 == toEndfReactionNumber( ReactionID( "n,Fe56->n,n,n,n,Fe53" ) ) );

      CHECK( 51 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e1" ) ) );
      CHECK( 52 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e2" ) ) );
      CHECK( 53 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e3" ) ) );
      CHECK( 54 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e4" ) ) );
      CHECK( 55 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e5" ) ) );
      CHECK( 56 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e6" ) ) );
      CHECK( 57 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e7" ) ) );
      CHECK( 58 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e8" ) ) );
      CHECK( 59 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e9" ) ) );
      CHECK( 60 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e10" ) ) );
      CHECK( 61 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e11" ) ) );
      CHECK( 62 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e12" ) ) );
      CHECK( 63 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e13" ) ) );
      CHECK( 64 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e14" ) ) );
      CHECK( 65 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e15" ) ) );
      CHECK( 66 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e16" ) ) );
      CHECK( 67 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e17" ) ) );
      CHECK( 68 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e18" ) ) );
      CHECK( 69 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e19" ) ) );
      CHECK( 70 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e20" ) ) );
      CHECK( 71 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e21" ) ) );
      CHECK( 72 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e22" ) ) );
      CHECK( 73 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e23" ) ) );
      CHECK( 74 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e24" ) ) );
      CHECK( 75 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e25" ) ) );
      CHECK( 76 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e26" ) ) );
      CHECK( 77 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e27" ) ) );
      CHECK( 78 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e28" ) ) );
      CHECK( 79 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e29" ) ) );
      CHECK( 80 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e30" ) ) );
      CHECK( 81 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e31" ) ) );
      CHECK( 82 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e32" ) ) );
      CHECK( 83 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e33" ) ) );
      CHECK( 84 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e34" ) ) );
      CHECK( 85 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e35" ) ) );
      CHECK( 86 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e36" ) ) );
      CHECK( 87 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e37" ) ) );
      CHECK( 88 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e38" ) ) );
      CHECK( 89 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e39" ) ) );
      CHECK( 90 == toEndfReactionNumber( ReactionID( "n,Fe56->n,Fe56_e40" ) ) );

      CHECK( 875 == toEndfReactionNumber( ReactionID( "n,Fe56->n,n,Fe55" ) ) );
      CHECK( 876 == toEndfReactionNumber( ReactionID( "n,Fe56->n,n,Fe55_e1" ) ) );
      CHECK( 877 == toEndfReactionNumber( ReactionID( "n,Fe56->n,n,Fe55_e2" ) ) );
      CHECK( 878 == toEndfReactionNumber( ReactionID( "n,Fe56->n,n,Fe55_e3" ) ) );
      CHECK( 879 == toEndfReactionNumber( ReactionID( "n,Fe56->n,n,Fe55_e4" ) ) );
      CHECK( 880 == toEndfReactionNumber( ReactionID( "n,Fe56->n,n,Fe55_e5" ) ) );
      CHECK( 881 == toEndfReactionNumber( ReactionID( "n,Fe56->n,n,Fe55_e6" ) ) );
      CHECK( 882 == toEndfReactionNumber( ReactionID( "n,Fe56->n,n,Fe55_e7" ) ) );
      CHECK( 883 == toEndfReactionNumber( ReactionID( "n,Fe56->n,n,Fe55_e8" ) ) );
      CHECK( 884 == toEndfReactionNumber( ReactionID( "n,Fe56->n,n,Fe55_e9" ) ) );
      CHECK( 885 == toEndfReactionNumber( ReactionID( "n,Fe56->n,n,Fe55_e10" ) ) );
      CHECK( 886 == toEndfReactionNumber( ReactionID( "n,Fe56->n,n,Fe55_e11" ) ) );
      CHECK( 887 == toEndfReactionNumber( ReactionID( "n,Fe56->n,n,Fe55_e12" ) ) );
      CHECK( 888 == toEndfReactionNumber( ReactionID( "n,Fe56->n,n,Fe55_e13" ) ) );
      CHECK( 889 == toEndfReactionNumber( ReactionID( "n,Fe56->n,n,Fe55_e14" ) ) );
      CHECK( 890 == toEndfReactionNumber( ReactionID( "n,Fe56->n,n,Fe55_e15" ) ) );*/

      // incident protons
      CHECK( 2 == toEndfReactionNumber( ReactionID( "p,Fe56->p,Fe56" ) ) );

/*      CHECK( 17 == toEndfReactionNumber( ReactionID( "p,Fe56->n,n,n,Co54" ) ) );

      CHECK( 37 == toEndfReactionNumber( ReactionID( "p,Fe56->n,n,n,n,Co53" ) ) );

      CHECK( 51 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e1" ) ) );
      CHECK( 52 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e2" ) ) );
      CHECK( 53 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e3" ) ) );
      CHECK( 54 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e4" ) ) );
      CHECK( 55 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e5" ) ) );
      CHECK( 56 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e6" ) ) );
      CHECK( 57 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e7" ) ) );
      CHECK( 58 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e8" ) ) );
      CHECK( 59 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e9" ) ) );
      CHECK( 60 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e10" ) ) );
      CHECK( 61 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e11" ) ) );
      CHECK( 62 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e12" ) ) );
      CHECK( 63 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e13" ) ) );
      CHECK( 64 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e14" ) ) );
      CHECK( 65 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e15" ) ) );
      CHECK( 66 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e16" ) ) );
      CHECK( 67 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e17" ) ) );
      CHECK( 68 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e18" ) ) );
      CHECK( 69 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e19" ) ) );
      CHECK( 70 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e20" ) ) );
      CHECK( 71 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e21" ) ) );
      CHECK( 72 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e22" ) ) );
      CHECK( 73 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e23" ) ) );
      CHECK( 74 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e24" ) ) );
      CHECK( 75 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e25" ) ) );
      CHECK( 76 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e26" ) ) );
      CHECK( 77 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e27" ) ) );
      CHECK( 78 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e28" ) ) );
      CHECK( 79 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e29" ) ) );
      CHECK( 80 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e30" ) ) );
      CHECK( 81 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e31" ) ) );
      CHECK( 82 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e32" ) ) );
      CHECK( 83 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e33" ) ) );
      CHECK( 84 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e34" ) ) );
      CHECK( 85 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e35" ) ) );
      CHECK( 86 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e36" ) ) );
      CHECK( 87 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e37" ) ) );
      CHECK( 88 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e38" ) ) );
      CHECK( 89 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e39" ) ) );
      CHECK( 90 == toEndfReactionNumber( ReactionID( "p,Fe56->n,Co56_e40" ) ) );

      CHECK( 875 == toEndfReactionNumber( ReactionID( "p,Fe56->n,n,Co55" ) ) );
      CHECK( 876 == toEndfReactionNumber( ReactionID( "p,Fe56->n,n,Co55_e1" ) ) );
      CHECK( 877 == toEndfReactionNumber( ReactionID( "p,Fe56->n,n,Co55_e2" ) ) );
      CHECK( 878 == toEndfReactionNumber( ReactionID( "p,Fe56->n,n,Co55_e3" ) ) );
      CHECK( 879 == toEndfReactionNumber( ReactionID( "p,Fe56->n,n,Co55_e4" ) ) );
      CHECK( 880 == toEndfReactionNumber( ReactionID( "p,Fe56->n,n,Co55_e5" ) ) );
      CHECK( 881 == toEndfReactionNumber( ReactionID( "p,Fe56->n,n,Co55_e6" ) ) );
      CHECK( 882 == toEndfReactionNumber( ReactionID( "p,Fe56->n,n,Co55_e7" ) ) );
      CHECK( 883 == toEndfReactionNumber( ReactionID( "p,Fe56->n,n,Co55_e8" ) ) );
      CHECK( 884 == toEndfReactionNumber( ReactionID( "p,Fe56->n,n,Co55_e9" ) ) );
      CHECK( 885 == toEndfReactionNumber( ReactionID( "p,Fe56->n,n,Co55_e10" ) ) );
      CHECK( 886 == toEndfReactionNumber( ReactionID( "p,Fe56->n,n,Co55_e11" ) ) );
      CHECK( 887 == toEndfReactionNumber( ReactionID( "p,Fe56->n,n,Co55_e12" ) ) );
      CHECK( 888 == toEndfReactionNumber( ReactionID( "p,Fe56->n,n,Co55_e13" ) ) );
      CHECK( 889 == toEndfReactionNumber( ReactionID( "p,Fe56->n,n,Co55_e14" ) ) );
      CHECK( 890 == toEndfReactionNumber( ReactionID( "p,Fe56->n,n,Co55_e15" ) ) );*/
    } // THEN
  } // GIVEN
} // SCENARIO
