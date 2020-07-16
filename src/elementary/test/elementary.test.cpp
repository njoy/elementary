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

      CHECK( ReactionID( "n,Fe56->n,n,h2,Mn53" ) == fromEndfReactionNumber( neutron, Fe56_e0, 11 ) );

      CHECK( ReactionID( "n,Fe56->n,n,n,Fe54" ) == fromEndfReactionNumber( neutron, Fe56_e0, 17 ) );

      CHECK( ReactionID( "n,Fe56->n,he4,Cr52" ) == fromEndfReactionNumber( neutron, Fe56_e0, 22 ) );
      CHECK( ReactionID( "n,Fe56->n,he4,he4,he4,Ca44" ) == fromEndfReactionNumber( neutron, Fe56_e0, 23 ) );
      CHECK( ReactionID( "n,Fe56->n,n,he4,Cr51" ) == fromEndfReactionNumber( neutron, Fe56_e0, 24 ) );

      CHECK( ReactionID( "n,Fe56->n,n,n,n,Fe53" ) == fromEndfReactionNumber( neutron, Fe56_e0, 37 ) );

      CHECK( ReactionID( "n,Fe56->n,Fe56_e1" ) == fromEndfReactionNumber( neutron, Fe56_e0, 51 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e2" ) == fromEndfReactionNumber( neutron, Fe56_e0, 52 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e3" ) == fromEndfReactionNumber( neutron, Fe56_e0, 53 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e4" ) == fromEndfReactionNumber( neutron, Fe56_e0, 54 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e5" ) == fromEndfReactionNumber( neutron, Fe56_e0, 55 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e6" ) == fromEndfReactionNumber( neutron, Fe56_e0, 56 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e7" ) == fromEndfReactionNumber( neutron, Fe56_e0, 57 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e8" ) == fromEndfReactionNumber( neutron, Fe56_e0, 58 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e9" ) == fromEndfReactionNumber( neutron, Fe56_e0, 59 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e10" ) == fromEndfReactionNumber( neutron, Fe56_e0, 60 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e11" ) == fromEndfReactionNumber( neutron, Fe56_e0, 61 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e12" ) == fromEndfReactionNumber( neutron, Fe56_e0, 62 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e13" ) == fromEndfReactionNumber( neutron, Fe56_e0, 63 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e14" ) == fromEndfReactionNumber( neutron, Fe56_e0, 64 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e15" ) == fromEndfReactionNumber( neutron, Fe56_e0, 65 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e16" ) == fromEndfReactionNumber( neutron, Fe56_e0, 66 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e17" ) == fromEndfReactionNumber( neutron, Fe56_e0, 67 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e18" ) == fromEndfReactionNumber( neutron, Fe56_e0, 68 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e19" ) == fromEndfReactionNumber( neutron, Fe56_e0, 69 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e20" ) == fromEndfReactionNumber( neutron, Fe56_e0, 70 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e21" ) == fromEndfReactionNumber( neutron, Fe56_e0, 71 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e22" ) == fromEndfReactionNumber( neutron, Fe56_e0, 72 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e23" ) == fromEndfReactionNumber( neutron, Fe56_e0, 73 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e24" ) == fromEndfReactionNumber( neutron, Fe56_e0, 74 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e25" ) == fromEndfReactionNumber( neutron, Fe56_e0, 75 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e26" ) == fromEndfReactionNumber( neutron, Fe56_e0, 76 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e27" ) == fromEndfReactionNumber( neutron, Fe56_e0, 77 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e28" ) == fromEndfReactionNumber( neutron, Fe56_e0, 78 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e29" ) == fromEndfReactionNumber( neutron, Fe56_e0, 79 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e30" ) == fromEndfReactionNumber( neutron, Fe56_e0, 80 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e31" ) == fromEndfReactionNumber( neutron, Fe56_e0, 81 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e32" ) == fromEndfReactionNumber( neutron, Fe56_e0, 82 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e33" ) == fromEndfReactionNumber( neutron, Fe56_e0, 83 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e34" ) == fromEndfReactionNumber( neutron, Fe56_e0, 84 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e35" ) == fromEndfReactionNumber( neutron, Fe56_e0, 85 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e36" ) == fromEndfReactionNumber( neutron, Fe56_e0, 86 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e37" ) == fromEndfReactionNumber( neutron, Fe56_e0, 87 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e38" ) == fromEndfReactionNumber( neutron, Fe56_e0, 88 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e39" ) == fromEndfReactionNumber( neutron, Fe56_e0, 89 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56_e40" ) == fromEndfReactionNumber( neutron, Fe56_e0, 90 ) );
      CHECK( ReactionID( "n,Fe56->n,Fe56[continuum]" ) == fromEndfReactionNumber( neutron, Fe56_e0, 91 ) );

      CHECK( ReactionID( "n,Fe56->p,Mn56" ) == fromEndfReactionNumber( neutron, Fe56_e0, 600 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e1" ) == fromEndfReactionNumber( neutron, Fe56_e0, 601 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e2" ) == fromEndfReactionNumber( neutron, Fe56_e0, 602 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e3" ) == fromEndfReactionNumber( neutron, Fe56_e0, 603 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e4" ) == fromEndfReactionNumber( neutron, Fe56_e0, 604 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e5" ) == fromEndfReactionNumber( neutron, Fe56_e0, 605 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e6" ) == fromEndfReactionNumber( neutron, Fe56_e0, 606 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e7" ) == fromEndfReactionNumber( neutron, Fe56_e0, 607 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e8" ) == fromEndfReactionNumber( neutron, Fe56_e0, 608 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e9" ) == fromEndfReactionNumber( neutron, Fe56_e0, 609 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e10" ) == fromEndfReactionNumber( neutron, Fe56_e0, 610 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e11" ) == fromEndfReactionNumber( neutron, Fe56_e0, 611 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e12" ) == fromEndfReactionNumber( neutron, Fe56_e0, 612 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e13" ) == fromEndfReactionNumber( neutron, Fe56_e0, 613 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e14" ) == fromEndfReactionNumber( neutron, Fe56_e0, 614 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e15" ) == fromEndfReactionNumber( neutron, Fe56_e0, 615 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e16" ) == fromEndfReactionNumber( neutron, Fe56_e0, 616 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e17" ) == fromEndfReactionNumber( neutron, Fe56_e0, 617 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e18" ) == fromEndfReactionNumber( neutron, Fe56_e0, 618 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e19" ) == fromEndfReactionNumber( neutron, Fe56_e0, 619 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e20" ) == fromEndfReactionNumber( neutron, Fe56_e0, 620 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e21" ) == fromEndfReactionNumber( neutron, Fe56_e0, 621 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e22" ) == fromEndfReactionNumber( neutron, Fe56_e0, 622 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e23" ) == fromEndfReactionNumber( neutron, Fe56_e0, 623 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e24" ) == fromEndfReactionNumber( neutron, Fe56_e0, 624 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e25" ) == fromEndfReactionNumber( neutron, Fe56_e0, 625 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e26" ) == fromEndfReactionNumber( neutron, Fe56_e0, 626 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e27" ) == fromEndfReactionNumber( neutron, Fe56_e0, 627 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e28" ) == fromEndfReactionNumber( neutron, Fe56_e0, 628 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e29" ) == fromEndfReactionNumber( neutron, Fe56_e0, 629 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e30" ) == fromEndfReactionNumber( neutron, Fe56_e0, 630 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e31" ) == fromEndfReactionNumber( neutron, Fe56_e0, 631 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e32" ) == fromEndfReactionNumber( neutron, Fe56_e0, 632 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e33" ) == fromEndfReactionNumber( neutron, Fe56_e0, 633 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e34" ) == fromEndfReactionNumber( neutron, Fe56_e0, 634 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e35" ) == fromEndfReactionNumber( neutron, Fe56_e0, 635 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e36" ) == fromEndfReactionNumber( neutron, Fe56_e0, 636 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e37" ) == fromEndfReactionNumber( neutron, Fe56_e0, 637 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e38" ) == fromEndfReactionNumber( neutron, Fe56_e0, 638 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e39" ) == fromEndfReactionNumber( neutron, Fe56_e0, 639 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e40" ) == fromEndfReactionNumber( neutron, Fe56_e0, 640 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e41" ) == fromEndfReactionNumber( neutron, Fe56_e0, 641 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e42" ) == fromEndfReactionNumber( neutron, Fe56_e0, 642 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e43" ) == fromEndfReactionNumber( neutron, Fe56_e0, 643 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e44" ) == fromEndfReactionNumber( neutron, Fe56_e0, 644 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e45" ) == fromEndfReactionNumber( neutron, Fe56_e0, 645 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e46" ) == fromEndfReactionNumber( neutron, Fe56_e0, 646 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e47" ) == fromEndfReactionNumber( neutron, Fe56_e0, 647 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56_e48" ) == fromEndfReactionNumber( neutron, Fe56_e0, 648 ) );
      CHECK( ReactionID( "n,Fe56->p,Mn56[continuum]" ) == fromEndfReactionNumber( neutron, Fe56_e0, 649 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55" ) == fromEndfReactionNumber( neutron, Fe56_e0, 650 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e1" ) == fromEndfReactionNumber( neutron, Fe56_e0, 651 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e2" ) == fromEndfReactionNumber( neutron, Fe56_e0, 652 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e3" ) == fromEndfReactionNumber( neutron, Fe56_e0, 653 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e4" ) == fromEndfReactionNumber( neutron, Fe56_e0, 654 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e5" ) == fromEndfReactionNumber( neutron, Fe56_e0, 655 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e6" ) == fromEndfReactionNumber( neutron, Fe56_e0, 656 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e7" ) == fromEndfReactionNumber( neutron, Fe56_e0, 657 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e8" ) == fromEndfReactionNumber( neutron, Fe56_e0, 658 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e9" ) == fromEndfReactionNumber( neutron, Fe56_e0, 659 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e10" ) == fromEndfReactionNumber( neutron, Fe56_e0, 660 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e11" ) == fromEndfReactionNumber( neutron, Fe56_e0, 661 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e12" ) == fromEndfReactionNumber( neutron, Fe56_e0, 662 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e13" ) == fromEndfReactionNumber( neutron, Fe56_e0, 663 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e14" ) == fromEndfReactionNumber( neutron, Fe56_e0, 664 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e15" ) == fromEndfReactionNumber( neutron, Fe56_e0, 665 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e16" ) == fromEndfReactionNumber( neutron, Fe56_e0, 666 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e17" ) == fromEndfReactionNumber( neutron, Fe56_e0, 667 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e18" ) == fromEndfReactionNumber( neutron, Fe56_e0, 668 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e19" ) == fromEndfReactionNumber( neutron, Fe56_e0, 669 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e20" ) == fromEndfReactionNumber( neutron, Fe56_e0, 670 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e21" ) == fromEndfReactionNumber( neutron, Fe56_e0, 671 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e22" ) == fromEndfReactionNumber( neutron, Fe56_e0, 672 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e23" ) == fromEndfReactionNumber( neutron, Fe56_e0, 673 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e24" ) == fromEndfReactionNumber( neutron, Fe56_e0, 674 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e25" ) == fromEndfReactionNumber( neutron, Fe56_e0, 675 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e26" ) == fromEndfReactionNumber( neutron, Fe56_e0, 676 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e27" ) == fromEndfReactionNumber( neutron, Fe56_e0, 677 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e28" ) == fromEndfReactionNumber( neutron, Fe56_e0, 678 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e29" ) == fromEndfReactionNumber( neutron, Fe56_e0, 679 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e30" ) == fromEndfReactionNumber( neutron, Fe56_e0, 680 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e31" ) == fromEndfReactionNumber( neutron, Fe56_e0, 681 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e32" ) == fromEndfReactionNumber( neutron, Fe56_e0, 682 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e33" ) == fromEndfReactionNumber( neutron, Fe56_e0, 683 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e34" ) == fromEndfReactionNumber( neutron, Fe56_e0, 684 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e35" ) == fromEndfReactionNumber( neutron, Fe56_e0, 685 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e36" ) == fromEndfReactionNumber( neutron, Fe56_e0, 686 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e37" ) == fromEndfReactionNumber( neutron, Fe56_e0, 687 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e38" ) == fromEndfReactionNumber( neutron, Fe56_e0, 688 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e39" ) == fromEndfReactionNumber( neutron, Fe56_e0, 689 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e40" ) == fromEndfReactionNumber( neutron, Fe56_e0, 690 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e41" ) == fromEndfReactionNumber( neutron, Fe56_e0, 691 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e42" ) == fromEndfReactionNumber( neutron, Fe56_e0, 692 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e43" ) == fromEndfReactionNumber( neutron, Fe56_e0, 693 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e44" ) == fromEndfReactionNumber( neutron, Fe56_e0, 694 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e45" ) == fromEndfReactionNumber( neutron, Fe56_e0, 695 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e46" ) == fromEndfReactionNumber( neutron, Fe56_e0, 696 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e47" ) == fromEndfReactionNumber( neutron, Fe56_e0, 697 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55_e48" ) == fromEndfReactionNumber( neutron, Fe56_e0, 698 ) );
      CHECK( ReactionID( "n,Fe56->h2,Mn55[continuum]" ) == fromEndfReactionNumber( neutron, Fe56_e0, 699 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54" ) == fromEndfReactionNumber( neutron, Fe56_e0, 700 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e1" ) == fromEndfReactionNumber( neutron, Fe56_e0, 701 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e2" ) == fromEndfReactionNumber( neutron, Fe56_e0, 702 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e3" ) == fromEndfReactionNumber( neutron, Fe56_e0, 703 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e4" ) == fromEndfReactionNumber( neutron, Fe56_e0, 704 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e5" ) == fromEndfReactionNumber( neutron, Fe56_e0, 705 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e6" ) == fromEndfReactionNumber( neutron, Fe56_e0, 706 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e7" ) == fromEndfReactionNumber( neutron, Fe56_e0, 707 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e8" ) == fromEndfReactionNumber( neutron, Fe56_e0, 708 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e9" ) == fromEndfReactionNumber( neutron, Fe56_e0, 709 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e10" ) == fromEndfReactionNumber( neutron, Fe56_e0, 710 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e11" ) == fromEndfReactionNumber( neutron, Fe56_e0, 711 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e12" ) == fromEndfReactionNumber( neutron, Fe56_e0, 712 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e13" ) == fromEndfReactionNumber( neutron, Fe56_e0, 713 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e14" ) == fromEndfReactionNumber( neutron, Fe56_e0, 714 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e15" ) == fromEndfReactionNumber( neutron, Fe56_e0, 715 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e16" ) == fromEndfReactionNumber( neutron, Fe56_e0, 716 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e17" ) == fromEndfReactionNumber( neutron, Fe56_e0, 717 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e18" ) == fromEndfReactionNumber( neutron, Fe56_e0, 718 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e19" ) == fromEndfReactionNumber( neutron, Fe56_e0, 719 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e20" ) == fromEndfReactionNumber( neutron, Fe56_e0, 720 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e21" ) == fromEndfReactionNumber( neutron, Fe56_e0, 721 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e22" ) == fromEndfReactionNumber( neutron, Fe56_e0, 722 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e23" ) == fromEndfReactionNumber( neutron, Fe56_e0, 723 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e24" ) == fromEndfReactionNumber( neutron, Fe56_e0, 724 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e25" ) == fromEndfReactionNumber( neutron, Fe56_e0, 725 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e26" ) == fromEndfReactionNumber( neutron, Fe56_e0, 726 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e27" ) == fromEndfReactionNumber( neutron, Fe56_e0, 727 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e28" ) == fromEndfReactionNumber( neutron, Fe56_e0, 728 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e29" ) == fromEndfReactionNumber( neutron, Fe56_e0, 729 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e30" ) == fromEndfReactionNumber( neutron, Fe56_e0, 730 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e31" ) == fromEndfReactionNumber( neutron, Fe56_e0, 731 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e32" ) == fromEndfReactionNumber( neutron, Fe56_e0, 732 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e33" ) == fromEndfReactionNumber( neutron, Fe56_e0, 733 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e34" ) == fromEndfReactionNumber( neutron, Fe56_e0, 734 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e35" ) == fromEndfReactionNumber( neutron, Fe56_e0, 735 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e36" ) == fromEndfReactionNumber( neutron, Fe56_e0, 736 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e37" ) == fromEndfReactionNumber( neutron, Fe56_e0, 737 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e38" ) == fromEndfReactionNumber( neutron, Fe56_e0, 738 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e39" ) == fromEndfReactionNumber( neutron, Fe56_e0, 739 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e40" ) == fromEndfReactionNumber( neutron, Fe56_e0, 740 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e41" ) == fromEndfReactionNumber( neutron, Fe56_e0, 741 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e42" ) == fromEndfReactionNumber( neutron, Fe56_e0, 742 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e43" ) == fromEndfReactionNumber( neutron, Fe56_e0, 743 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e44" ) == fromEndfReactionNumber( neutron, Fe56_e0, 744 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e45" ) == fromEndfReactionNumber( neutron, Fe56_e0, 745 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e46" ) == fromEndfReactionNumber( neutron, Fe56_e0, 746 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e47" ) == fromEndfReactionNumber( neutron, Fe56_e0, 747 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54_e48" ) == fromEndfReactionNumber( neutron, Fe56_e0, 748 ) );
      CHECK( ReactionID( "n,Fe56->h3,Mn54[continuum]" ) == fromEndfReactionNumber( neutron, Fe56_e0, 749 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54" ) == fromEndfReactionNumber( neutron, Fe56_e0, 750 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e1" ) == fromEndfReactionNumber( neutron, Fe56_e0, 751 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e2" ) == fromEndfReactionNumber( neutron, Fe56_e0, 752 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e3" ) == fromEndfReactionNumber( neutron, Fe56_e0, 753 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e4" ) == fromEndfReactionNumber( neutron, Fe56_e0, 754 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e5" ) == fromEndfReactionNumber( neutron, Fe56_e0, 755 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e6" ) == fromEndfReactionNumber( neutron, Fe56_e0, 756 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e7" ) == fromEndfReactionNumber( neutron, Fe56_e0, 757 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e8" ) == fromEndfReactionNumber( neutron, Fe56_e0, 758 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e9" ) == fromEndfReactionNumber( neutron, Fe56_e0, 759 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e10" ) == fromEndfReactionNumber( neutron, Fe56_e0, 760 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e11" ) == fromEndfReactionNumber( neutron, Fe56_e0, 761 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e12" ) == fromEndfReactionNumber( neutron, Fe56_e0, 762 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e13" ) == fromEndfReactionNumber( neutron, Fe56_e0, 763 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e14" ) == fromEndfReactionNumber( neutron, Fe56_e0, 764 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e15" ) == fromEndfReactionNumber( neutron, Fe56_e0, 765 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e16" ) == fromEndfReactionNumber( neutron, Fe56_e0, 766 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e17" ) == fromEndfReactionNumber( neutron, Fe56_e0, 767 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e18" ) == fromEndfReactionNumber( neutron, Fe56_e0, 768 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e19" ) == fromEndfReactionNumber( neutron, Fe56_e0, 769 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e20" ) == fromEndfReactionNumber( neutron, Fe56_e0, 770 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e21" ) == fromEndfReactionNumber( neutron, Fe56_e0, 771 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e22" ) == fromEndfReactionNumber( neutron, Fe56_e0, 772 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e23" ) == fromEndfReactionNumber( neutron, Fe56_e0, 773 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e24" ) == fromEndfReactionNumber( neutron, Fe56_e0, 774 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e25" ) == fromEndfReactionNumber( neutron, Fe56_e0, 775 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e26" ) == fromEndfReactionNumber( neutron, Fe56_e0, 776 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e27" ) == fromEndfReactionNumber( neutron, Fe56_e0, 777 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e28" ) == fromEndfReactionNumber( neutron, Fe56_e0, 778 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e29" ) == fromEndfReactionNumber( neutron, Fe56_e0, 779 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e30" ) == fromEndfReactionNumber( neutron, Fe56_e0, 780 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e31" ) == fromEndfReactionNumber( neutron, Fe56_e0, 781 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e32" ) == fromEndfReactionNumber( neutron, Fe56_e0, 782 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e33" ) == fromEndfReactionNumber( neutron, Fe56_e0, 783 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e34" ) == fromEndfReactionNumber( neutron, Fe56_e0, 784 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e35" ) == fromEndfReactionNumber( neutron, Fe56_e0, 785 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e36" ) == fromEndfReactionNumber( neutron, Fe56_e0, 786 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e37" ) == fromEndfReactionNumber( neutron, Fe56_e0, 787 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e38" ) == fromEndfReactionNumber( neutron, Fe56_e0, 788 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e39" ) == fromEndfReactionNumber( neutron, Fe56_e0, 789 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e40" ) == fromEndfReactionNumber( neutron, Fe56_e0, 790 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e41" ) == fromEndfReactionNumber( neutron, Fe56_e0, 791 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e42" ) == fromEndfReactionNumber( neutron, Fe56_e0, 792 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e43" ) == fromEndfReactionNumber( neutron, Fe56_e0, 793 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e44" ) == fromEndfReactionNumber( neutron, Fe56_e0, 794 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e45" ) == fromEndfReactionNumber( neutron, Fe56_e0, 795 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e46" ) == fromEndfReactionNumber( neutron, Fe56_e0, 796 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e47" ) == fromEndfReactionNumber( neutron, Fe56_e0, 797 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54_e48" ) == fromEndfReactionNumber( neutron, Fe56_e0, 798 ) );
      CHECK( ReactionID( "n,Fe56->he3,Cr54[continuum]" ) == fromEndfReactionNumber( neutron, Fe56_e0, 799 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53" ) == fromEndfReactionNumber( neutron, Fe56_e0, 800 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e1" ) == fromEndfReactionNumber( neutron, Fe56_e0, 801 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e2" ) == fromEndfReactionNumber( neutron, Fe56_e0, 802 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e3" ) == fromEndfReactionNumber( neutron, Fe56_e0, 803 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e4" ) == fromEndfReactionNumber( neutron, Fe56_e0, 804 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e5" ) == fromEndfReactionNumber( neutron, Fe56_e0, 805 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e6" ) == fromEndfReactionNumber( neutron, Fe56_e0, 806 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e7" ) == fromEndfReactionNumber( neutron, Fe56_e0, 807 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e8" ) == fromEndfReactionNumber( neutron, Fe56_e0, 808 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e9" ) == fromEndfReactionNumber( neutron, Fe56_e0, 809 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e10" ) == fromEndfReactionNumber( neutron, Fe56_e0, 810 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e11" ) == fromEndfReactionNumber( neutron, Fe56_e0, 811 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e12" ) == fromEndfReactionNumber( neutron, Fe56_e0, 812 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e13" ) == fromEndfReactionNumber( neutron, Fe56_e0, 813 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e14" ) == fromEndfReactionNumber( neutron, Fe56_e0, 814 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e15" ) == fromEndfReactionNumber( neutron, Fe56_e0, 815 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e16" ) == fromEndfReactionNumber( neutron, Fe56_e0, 816 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e17" ) == fromEndfReactionNumber( neutron, Fe56_e0, 817 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e18" ) == fromEndfReactionNumber( neutron, Fe56_e0, 818 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e19" ) == fromEndfReactionNumber( neutron, Fe56_e0, 819 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e20" ) == fromEndfReactionNumber( neutron, Fe56_e0, 820 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e21" ) == fromEndfReactionNumber( neutron, Fe56_e0, 821 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e22" ) == fromEndfReactionNumber( neutron, Fe56_e0, 822 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e23" ) == fromEndfReactionNumber( neutron, Fe56_e0, 823 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e24" ) == fromEndfReactionNumber( neutron, Fe56_e0, 824 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e25" ) == fromEndfReactionNumber( neutron, Fe56_e0, 825 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e26" ) == fromEndfReactionNumber( neutron, Fe56_e0, 826 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e27" ) == fromEndfReactionNumber( neutron, Fe56_e0, 827 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e28" ) == fromEndfReactionNumber( neutron, Fe56_e0, 828 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e29" ) == fromEndfReactionNumber( neutron, Fe56_e0, 829 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e30" ) == fromEndfReactionNumber( neutron, Fe56_e0, 830 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e31" ) == fromEndfReactionNumber( neutron, Fe56_e0, 831 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e32" ) == fromEndfReactionNumber( neutron, Fe56_e0, 832 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e33" ) == fromEndfReactionNumber( neutron, Fe56_e0, 833 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e34" ) == fromEndfReactionNumber( neutron, Fe56_e0, 834 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e35" ) == fromEndfReactionNumber( neutron, Fe56_e0, 835 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e36" ) == fromEndfReactionNumber( neutron, Fe56_e0, 836 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e37" ) == fromEndfReactionNumber( neutron, Fe56_e0, 837 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e38" ) == fromEndfReactionNumber( neutron, Fe56_e0, 838 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e39" ) == fromEndfReactionNumber( neutron, Fe56_e0, 839 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e40" ) == fromEndfReactionNumber( neutron, Fe56_e0, 840 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e41" ) == fromEndfReactionNumber( neutron, Fe56_e0, 841 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e42" ) == fromEndfReactionNumber( neutron, Fe56_e0, 842 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e43" ) == fromEndfReactionNumber( neutron, Fe56_e0, 843 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e44" ) == fromEndfReactionNumber( neutron, Fe56_e0, 844 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e45" ) == fromEndfReactionNumber( neutron, Fe56_e0, 845 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e46" ) == fromEndfReactionNumber( neutron, Fe56_e0, 846 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e47" ) == fromEndfReactionNumber( neutron, Fe56_e0, 847 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53_e48" ) == fromEndfReactionNumber( neutron, Fe56_e0, 848 ) );
      CHECK( ReactionID( "n,Fe56->he4,Cr53[continuum]" ) == fromEndfReactionNumber( neutron, Fe56_e0, 849 ) );
      CHECK( ReactionID( "n,Fe56->n,n,Fe55" ) == fromEndfReactionNumber( neutron, Fe56_e0, 875 ) );
      CHECK( ReactionID( "n,Fe56->n,n,Fe55_e1" ) == fromEndfReactionNumber( neutron, Fe56_e0, 876 ) );
      CHECK( ReactionID( "n,Fe56->n,n,Fe55_e2" ) == fromEndfReactionNumber( neutron, Fe56_e0, 877 ) );
      CHECK( ReactionID( "n,Fe56->n,n,Fe55_e3" ) == fromEndfReactionNumber( neutron, Fe56_e0, 878 ) );
      CHECK( ReactionID( "n,Fe56->n,n,Fe55_e4" ) == fromEndfReactionNumber( neutron, Fe56_e0, 879 ) );
      CHECK( ReactionID( "n,Fe56->n,n,Fe55_e5" ) == fromEndfReactionNumber( neutron, Fe56_e0, 880 ) );
      CHECK( ReactionID( "n,Fe56->n,n,Fe55_e6" ) == fromEndfReactionNumber( neutron, Fe56_e0, 881 ) );
      CHECK( ReactionID( "n,Fe56->n,n,Fe55_e7" ) == fromEndfReactionNumber( neutron, Fe56_e0, 882 ) );
      CHECK( ReactionID( "n,Fe56->n,n,Fe55_e8" ) == fromEndfReactionNumber( neutron, Fe56_e0, 883 ) );
      CHECK( ReactionID( "n,Fe56->n,n,Fe55_e9" ) == fromEndfReactionNumber( neutron, Fe56_e0, 884 ) );
      CHECK( ReactionID( "n,Fe56->n,n,Fe55_e10" ) == fromEndfReactionNumber( neutron, Fe56_e0, 885 ) );
      CHECK( ReactionID( "n,Fe56->n,n,Fe55_e11" ) == fromEndfReactionNumber( neutron, Fe56_e0, 886 ) );
      CHECK( ReactionID( "n,Fe56->n,n,Fe55_e12" ) == fromEndfReactionNumber( neutron, Fe56_e0, 887 ) );
      CHECK( ReactionID( "n,Fe56->n,n,Fe55_e13" ) == fromEndfReactionNumber( neutron, Fe56_e0, 888 ) );
      CHECK( ReactionID( "n,Fe56->n,n,Fe55_e14" ) == fromEndfReactionNumber( neutron, Fe56_e0, 889 ) );
      CHECK( ReactionID( "n,Fe56->n,n,Fe55_e15" ) == fromEndfReactionNumber( neutron, Fe56_e0, 890 ) );
      CHECK( ReactionID( "n,Fe56->n,n,Fe55[continuum]" ) == fromEndfReactionNumber( neutron, Fe56_e0, 891 ) );

      // incident protons
      CHECK( ReactionID( "p,Fe56->p,Fe56" ) == fromEndfReactionNumber( proton, Fe56_e0, 2 ) );

      CHECK( ReactionID( "p,Fe56->n,n,h2,Fe53" ) == fromEndfReactionNumber( proton, Fe56_e0, 11 ) );

      CHECK( ReactionID( "p,Fe56->n,n,n,Co54" ) == fromEndfReactionNumber( proton, Fe56_e0, 17 ) );

      CHECK( ReactionID( "p,Fe56->n,he4,Mn52" ) == fromEndfReactionNumber( proton, Fe56_e0, 22 ) );
      CHECK( ReactionID( "p,Fe56->n,he4,he4,he4,Sc44" ) == fromEndfReactionNumber( proton, Fe56_e0, 23 ) );
      CHECK( ReactionID( "p,Fe56->n,n,he4,Mn51" ) == fromEndfReactionNumber( proton, Fe56_e0, 24 ) );

      CHECK( ReactionID( "p,Fe56->n,n,n,n,Co53" ) == fromEndfReactionNumber( proton, Fe56_e0, 37 ) );

      CHECK( ReactionID( "p,Fe56->n,Co56_e1" ) == fromEndfReactionNumber( proton, Fe56_e0, 51 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e2" ) == fromEndfReactionNumber( proton, Fe56_e0, 52 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e3" ) == fromEndfReactionNumber( proton, Fe56_e0, 53 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e4" ) == fromEndfReactionNumber( proton, Fe56_e0, 54 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e5" ) == fromEndfReactionNumber( proton, Fe56_e0, 55 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e6" ) == fromEndfReactionNumber( proton, Fe56_e0, 56 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e7" ) == fromEndfReactionNumber( proton, Fe56_e0, 57 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e8" ) == fromEndfReactionNumber( proton, Fe56_e0, 58 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e9" ) == fromEndfReactionNumber( proton, Fe56_e0, 59 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e10" ) == fromEndfReactionNumber( proton, Fe56_e0, 60 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e11" ) == fromEndfReactionNumber( proton, Fe56_e0, 61 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e12" ) == fromEndfReactionNumber( proton, Fe56_e0, 62 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e13" ) == fromEndfReactionNumber( proton, Fe56_e0, 63 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e14" ) == fromEndfReactionNumber( proton, Fe56_e0, 64 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e15" ) == fromEndfReactionNumber( proton, Fe56_e0, 65 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e16" ) == fromEndfReactionNumber( proton, Fe56_e0, 66 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e17" ) == fromEndfReactionNumber( proton, Fe56_e0, 67 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e18" ) == fromEndfReactionNumber( proton, Fe56_e0, 68 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e19" ) == fromEndfReactionNumber( proton, Fe56_e0, 69 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e20" ) == fromEndfReactionNumber( proton, Fe56_e0, 70 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e21" ) == fromEndfReactionNumber( proton, Fe56_e0, 71 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e22" ) == fromEndfReactionNumber( proton, Fe56_e0, 72 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e23" ) == fromEndfReactionNumber( proton, Fe56_e0, 73 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e24" ) == fromEndfReactionNumber( proton, Fe56_e0, 74 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e25" ) == fromEndfReactionNumber( proton, Fe56_e0, 75 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e26" ) == fromEndfReactionNumber( proton, Fe56_e0, 76 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e27" ) == fromEndfReactionNumber( proton, Fe56_e0, 77 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e28" ) == fromEndfReactionNumber( proton, Fe56_e0, 78 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e29" ) == fromEndfReactionNumber( proton, Fe56_e0, 79 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e30" ) == fromEndfReactionNumber( proton, Fe56_e0, 80 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e31" ) == fromEndfReactionNumber( proton, Fe56_e0, 81 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e32" ) == fromEndfReactionNumber( proton, Fe56_e0, 82 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e33" ) == fromEndfReactionNumber( proton, Fe56_e0, 83 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e34" ) == fromEndfReactionNumber( proton, Fe56_e0, 84 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e35" ) == fromEndfReactionNumber( proton, Fe56_e0, 85 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e36" ) == fromEndfReactionNumber( proton, Fe56_e0, 86 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e37" ) == fromEndfReactionNumber( proton, Fe56_e0, 87 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e38" ) == fromEndfReactionNumber( proton, Fe56_e0, 88 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e39" ) == fromEndfReactionNumber( proton, Fe56_e0, 89 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56_e40" ) == fromEndfReactionNumber( proton, Fe56_e0, 90 ) );
      CHECK( ReactionID( "p,Fe56->n,Co56[continuum]" ) == fromEndfReactionNumber( proton, Fe56_e0, 91 ) );

      CHECK( ReactionID( "p,Fe56->p,Fe56" ) == fromEndfReactionNumber( proton, Fe56_e0, 600 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e1" ) == fromEndfReactionNumber( proton, Fe56_e0, 601 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e2" ) == fromEndfReactionNumber( proton, Fe56_e0, 602 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e3" ) == fromEndfReactionNumber( proton, Fe56_e0, 603 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e4" ) == fromEndfReactionNumber( proton, Fe56_e0, 604 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e5" ) == fromEndfReactionNumber( proton, Fe56_e0, 605 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e6" ) == fromEndfReactionNumber( proton, Fe56_e0, 606 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e7" ) == fromEndfReactionNumber( proton, Fe56_e0, 607 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e8" ) == fromEndfReactionNumber( proton, Fe56_e0, 608 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e9" ) == fromEndfReactionNumber( proton, Fe56_e0, 609 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e10" ) == fromEndfReactionNumber( proton, Fe56_e0, 610 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e11" ) == fromEndfReactionNumber( proton, Fe56_e0, 611 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e12" ) == fromEndfReactionNumber( proton, Fe56_e0, 612 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e13" ) == fromEndfReactionNumber( proton, Fe56_e0, 613 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e14" ) == fromEndfReactionNumber( proton, Fe56_e0, 614 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e15" ) == fromEndfReactionNumber( proton, Fe56_e0, 615 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e16" ) == fromEndfReactionNumber( proton, Fe56_e0, 616 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e17" ) == fromEndfReactionNumber( proton, Fe56_e0, 617 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e18" ) == fromEndfReactionNumber( proton, Fe56_e0, 618 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e19" ) == fromEndfReactionNumber( proton, Fe56_e0, 619 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e20" ) == fromEndfReactionNumber( proton, Fe56_e0, 620 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e21" ) == fromEndfReactionNumber( proton, Fe56_e0, 621 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e22" ) == fromEndfReactionNumber( proton, Fe56_e0, 622 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e23" ) == fromEndfReactionNumber( proton, Fe56_e0, 623 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e24" ) == fromEndfReactionNumber( proton, Fe56_e0, 624 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e25" ) == fromEndfReactionNumber( proton, Fe56_e0, 625 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e26" ) == fromEndfReactionNumber( proton, Fe56_e0, 626 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e27" ) == fromEndfReactionNumber( proton, Fe56_e0, 627 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e28" ) == fromEndfReactionNumber( proton, Fe56_e0, 628 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e29" ) == fromEndfReactionNumber( proton, Fe56_e0, 629 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e30" ) == fromEndfReactionNumber( proton, Fe56_e0, 630 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e31" ) == fromEndfReactionNumber( proton, Fe56_e0, 631 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e32" ) == fromEndfReactionNumber( proton, Fe56_e0, 632 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e33" ) == fromEndfReactionNumber( proton, Fe56_e0, 633 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e34" ) == fromEndfReactionNumber( proton, Fe56_e0, 634 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e35" ) == fromEndfReactionNumber( proton, Fe56_e0, 635 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e36" ) == fromEndfReactionNumber( proton, Fe56_e0, 636 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e37" ) == fromEndfReactionNumber( proton, Fe56_e0, 637 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e38" ) == fromEndfReactionNumber( proton, Fe56_e0, 638 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e39" ) == fromEndfReactionNumber( proton, Fe56_e0, 639 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e40" ) == fromEndfReactionNumber( proton, Fe56_e0, 640 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e41" ) == fromEndfReactionNumber( proton, Fe56_e0, 641 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e42" ) == fromEndfReactionNumber( proton, Fe56_e0, 642 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e43" ) == fromEndfReactionNumber( proton, Fe56_e0, 643 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e44" ) == fromEndfReactionNumber( proton, Fe56_e0, 644 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e45" ) == fromEndfReactionNumber( proton, Fe56_e0, 645 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e46" ) == fromEndfReactionNumber( proton, Fe56_e0, 646 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e47" ) == fromEndfReactionNumber( proton, Fe56_e0, 647 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56_e48" ) == fromEndfReactionNumber( proton, Fe56_e0, 648 ) );
      CHECK( ReactionID( "p,Fe56->p,Fe56[continuum]" ) == fromEndfReactionNumber( proton, Fe56_e0, 649 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55" ) == fromEndfReactionNumber( proton, Fe56_e0, 650 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e1" ) == fromEndfReactionNumber( proton, Fe56_e0, 651 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e2" ) == fromEndfReactionNumber( proton, Fe56_e0, 652 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e3" ) == fromEndfReactionNumber( proton, Fe56_e0, 653 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e4" ) == fromEndfReactionNumber( proton, Fe56_e0, 654 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e5" ) == fromEndfReactionNumber( proton, Fe56_e0, 655 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e6" ) == fromEndfReactionNumber( proton, Fe56_e0, 656 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e7" ) == fromEndfReactionNumber( proton, Fe56_e0, 657 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e8" ) == fromEndfReactionNumber( proton, Fe56_e0, 658 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e9" ) == fromEndfReactionNumber( proton, Fe56_e0, 659 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e10" ) == fromEndfReactionNumber( proton, Fe56_e0, 660 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e11" ) == fromEndfReactionNumber( proton, Fe56_e0, 661 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e12" ) == fromEndfReactionNumber( proton, Fe56_e0, 662 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e13" ) == fromEndfReactionNumber( proton, Fe56_e0, 663 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e14" ) == fromEndfReactionNumber( proton, Fe56_e0, 664 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e15" ) == fromEndfReactionNumber( proton, Fe56_e0, 665 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e16" ) == fromEndfReactionNumber( proton, Fe56_e0, 666 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e17" ) == fromEndfReactionNumber( proton, Fe56_e0, 667 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e18" ) == fromEndfReactionNumber( proton, Fe56_e0, 668 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e19" ) == fromEndfReactionNumber( proton, Fe56_e0, 669 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e20" ) == fromEndfReactionNumber( proton, Fe56_e0, 670 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e21" ) == fromEndfReactionNumber( proton, Fe56_e0, 671 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e22" ) == fromEndfReactionNumber( proton, Fe56_e0, 672 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e23" ) == fromEndfReactionNumber( proton, Fe56_e0, 673 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e24" ) == fromEndfReactionNumber( proton, Fe56_e0, 674 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e25" ) == fromEndfReactionNumber( proton, Fe56_e0, 675 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e26" ) == fromEndfReactionNumber( proton, Fe56_e0, 676 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e27" ) == fromEndfReactionNumber( proton, Fe56_e0, 677 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e28" ) == fromEndfReactionNumber( proton, Fe56_e0, 678 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e29" ) == fromEndfReactionNumber( proton, Fe56_e0, 679 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e30" ) == fromEndfReactionNumber( proton, Fe56_e0, 680 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e31" ) == fromEndfReactionNumber( proton, Fe56_e0, 681 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e32" ) == fromEndfReactionNumber( proton, Fe56_e0, 682 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e33" ) == fromEndfReactionNumber( proton, Fe56_e0, 683 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e34" ) == fromEndfReactionNumber( proton, Fe56_e0, 684 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e35" ) == fromEndfReactionNumber( proton, Fe56_e0, 685 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e36" ) == fromEndfReactionNumber( proton, Fe56_e0, 686 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e37" ) == fromEndfReactionNumber( proton, Fe56_e0, 687 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e38" ) == fromEndfReactionNumber( proton, Fe56_e0, 688 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e39" ) == fromEndfReactionNumber( proton, Fe56_e0, 689 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e40" ) == fromEndfReactionNumber( proton, Fe56_e0, 690 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e41" ) == fromEndfReactionNumber( proton, Fe56_e0, 691 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e42" ) == fromEndfReactionNumber( proton, Fe56_e0, 692 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e43" ) == fromEndfReactionNumber( proton, Fe56_e0, 693 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e44" ) == fromEndfReactionNumber( proton, Fe56_e0, 694 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e45" ) == fromEndfReactionNumber( proton, Fe56_e0, 695 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e46" ) == fromEndfReactionNumber( proton, Fe56_e0, 696 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e47" ) == fromEndfReactionNumber( proton, Fe56_e0, 697 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55_e48" ) == fromEndfReactionNumber( proton, Fe56_e0, 698 ) );
      CHECK( ReactionID( "p,Fe56->h2,Fe55[continuum]" ) == fromEndfReactionNumber( proton, Fe56_e0, 699 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54" ) == fromEndfReactionNumber( proton, Fe56_e0, 700 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e1" ) == fromEndfReactionNumber( proton, Fe56_e0, 701 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e2" ) == fromEndfReactionNumber( proton, Fe56_e0, 702 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e3" ) == fromEndfReactionNumber( proton, Fe56_e0, 703 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e4" ) == fromEndfReactionNumber( proton, Fe56_e0, 704 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e5" ) == fromEndfReactionNumber( proton, Fe56_e0, 705 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e6" ) == fromEndfReactionNumber( proton, Fe56_e0, 706 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e7" ) == fromEndfReactionNumber( proton, Fe56_e0, 707 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e8" ) == fromEndfReactionNumber( proton, Fe56_e0, 708 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e9" ) == fromEndfReactionNumber( proton, Fe56_e0, 709 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e10" ) == fromEndfReactionNumber( proton, Fe56_e0, 710 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e11" ) == fromEndfReactionNumber( proton, Fe56_e0, 711 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e12" ) == fromEndfReactionNumber( proton, Fe56_e0, 712 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e13" ) == fromEndfReactionNumber( proton, Fe56_e0, 713 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e14" ) == fromEndfReactionNumber( proton, Fe56_e0, 714 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e15" ) == fromEndfReactionNumber( proton, Fe56_e0, 715 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e16" ) == fromEndfReactionNumber( proton, Fe56_e0, 716 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e17" ) == fromEndfReactionNumber( proton, Fe56_e0, 717 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e18" ) == fromEndfReactionNumber( proton, Fe56_e0, 718 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e19" ) == fromEndfReactionNumber( proton, Fe56_e0, 719 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e20" ) == fromEndfReactionNumber( proton, Fe56_e0, 720 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e21" ) == fromEndfReactionNumber( proton, Fe56_e0, 721 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e22" ) == fromEndfReactionNumber( proton, Fe56_e0, 722 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e23" ) == fromEndfReactionNumber( proton, Fe56_e0, 723 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e24" ) == fromEndfReactionNumber( proton, Fe56_e0, 724 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e25" ) == fromEndfReactionNumber( proton, Fe56_e0, 725 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e26" ) == fromEndfReactionNumber( proton, Fe56_e0, 726 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e27" ) == fromEndfReactionNumber( proton, Fe56_e0, 727 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e28" ) == fromEndfReactionNumber( proton, Fe56_e0, 728 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e29" ) == fromEndfReactionNumber( proton, Fe56_e0, 729 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e30" ) == fromEndfReactionNumber( proton, Fe56_e0, 730 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e31" ) == fromEndfReactionNumber( proton, Fe56_e0, 731 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e32" ) == fromEndfReactionNumber( proton, Fe56_e0, 732 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e33" ) == fromEndfReactionNumber( proton, Fe56_e0, 733 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e34" ) == fromEndfReactionNumber( proton, Fe56_e0, 734 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e35" ) == fromEndfReactionNumber( proton, Fe56_e0, 735 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e36" ) == fromEndfReactionNumber( proton, Fe56_e0, 736 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e37" ) == fromEndfReactionNumber( proton, Fe56_e0, 737 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e38" ) == fromEndfReactionNumber( proton, Fe56_e0, 738 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e39" ) == fromEndfReactionNumber( proton, Fe56_e0, 739 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e40" ) == fromEndfReactionNumber( proton, Fe56_e0, 740 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e41" ) == fromEndfReactionNumber( proton, Fe56_e0, 741 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e42" ) == fromEndfReactionNumber( proton, Fe56_e0, 742 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e43" ) == fromEndfReactionNumber( proton, Fe56_e0, 743 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e44" ) == fromEndfReactionNumber( proton, Fe56_e0, 744 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e45" ) == fromEndfReactionNumber( proton, Fe56_e0, 745 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e46" ) == fromEndfReactionNumber( proton, Fe56_e0, 746 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e47" ) == fromEndfReactionNumber( proton, Fe56_e0, 747 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54_e48" ) == fromEndfReactionNumber( proton, Fe56_e0, 748 ) );
      CHECK( ReactionID( "p,Fe56->h3,Fe54[continuum]" ) == fromEndfReactionNumber( proton, Fe56_e0, 749 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54" ) == fromEndfReactionNumber( proton, Fe56_e0, 750 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e1" ) == fromEndfReactionNumber( proton, Fe56_e0, 751 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e2" ) == fromEndfReactionNumber( proton, Fe56_e0, 752 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e3" ) == fromEndfReactionNumber( proton, Fe56_e0, 753 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e4" ) == fromEndfReactionNumber( proton, Fe56_e0, 754 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e5" ) == fromEndfReactionNumber( proton, Fe56_e0, 755 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e6" ) == fromEndfReactionNumber( proton, Fe56_e0, 756 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e7" ) == fromEndfReactionNumber( proton, Fe56_e0, 757 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e8" ) == fromEndfReactionNumber( proton, Fe56_e0, 758 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e9" ) == fromEndfReactionNumber( proton, Fe56_e0, 759 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e10" ) == fromEndfReactionNumber( proton, Fe56_e0, 760 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e11" ) == fromEndfReactionNumber( proton, Fe56_e0, 761 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e12" ) == fromEndfReactionNumber( proton, Fe56_e0, 762 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e13" ) == fromEndfReactionNumber( proton, Fe56_e0, 763 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e14" ) == fromEndfReactionNumber( proton, Fe56_e0, 764 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e15" ) == fromEndfReactionNumber( proton, Fe56_e0, 765 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e16" ) == fromEndfReactionNumber( proton, Fe56_e0, 766 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e17" ) == fromEndfReactionNumber( proton, Fe56_e0, 767 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e18" ) == fromEndfReactionNumber( proton, Fe56_e0, 768 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e19" ) == fromEndfReactionNumber( proton, Fe56_e0, 769 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e20" ) == fromEndfReactionNumber( proton, Fe56_e0, 770 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e21" ) == fromEndfReactionNumber( proton, Fe56_e0, 771 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e22" ) == fromEndfReactionNumber( proton, Fe56_e0, 772 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e23" ) == fromEndfReactionNumber( proton, Fe56_e0, 773 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e24" ) == fromEndfReactionNumber( proton, Fe56_e0, 774 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e25" ) == fromEndfReactionNumber( proton, Fe56_e0, 775 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e26" ) == fromEndfReactionNumber( proton, Fe56_e0, 776 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e27" ) == fromEndfReactionNumber( proton, Fe56_e0, 777 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e28" ) == fromEndfReactionNumber( proton, Fe56_e0, 778 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e29" ) == fromEndfReactionNumber( proton, Fe56_e0, 779 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e30" ) == fromEndfReactionNumber( proton, Fe56_e0, 780 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e31" ) == fromEndfReactionNumber( proton, Fe56_e0, 781 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e32" ) == fromEndfReactionNumber( proton, Fe56_e0, 782 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e33" ) == fromEndfReactionNumber( proton, Fe56_e0, 783 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e34" ) == fromEndfReactionNumber( proton, Fe56_e0, 784 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e35" ) == fromEndfReactionNumber( proton, Fe56_e0, 785 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e36" ) == fromEndfReactionNumber( proton, Fe56_e0, 786 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e37" ) == fromEndfReactionNumber( proton, Fe56_e0, 787 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e38" ) == fromEndfReactionNumber( proton, Fe56_e0, 788 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e39" ) == fromEndfReactionNumber( proton, Fe56_e0, 789 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e40" ) == fromEndfReactionNumber( proton, Fe56_e0, 790 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e41" ) == fromEndfReactionNumber( proton, Fe56_e0, 791 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e42" ) == fromEndfReactionNumber( proton, Fe56_e0, 792 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e43" ) == fromEndfReactionNumber( proton, Fe56_e0, 793 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e44" ) == fromEndfReactionNumber( proton, Fe56_e0, 794 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e45" ) == fromEndfReactionNumber( proton, Fe56_e0, 795 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e46" ) == fromEndfReactionNumber( proton, Fe56_e0, 796 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e47" ) == fromEndfReactionNumber( proton, Fe56_e0, 797 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54_e48" ) == fromEndfReactionNumber( proton, Fe56_e0, 798 ) );
      CHECK( ReactionID( "p,Fe56->he3,Mn54[continuum]" ) == fromEndfReactionNumber( proton, Fe56_e0, 799 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53" ) == fromEndfReactionNumber( proton, Fe56_e0, 800 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e1" ) == fromEndfReactionNumber( proton, Fe56_e0, 801 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e2" ) == fromEndfReactionNumber( proton, Fe56_e0, 802 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e3" ) == fromEndfReactionNumber( proton, Fe56_e0, 803 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e4" ) == fromEndfReactionNumber( proton, Fe56_e0, 804 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e5" ) == fromEndfReactionNumber( proton, Fe56_e0, 805 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e6" ) == fromEndfReactionNumber( proton, Fe56_e0, 806 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e7" ) == fromEndfReactionNumber( proton, Fe56_e0, 807 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e8" ) == fromEndfReactionNumber( proton, Fe56_e0, 808 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e9" ) == fromEndfReactionNumber( proton, Fe56_e0, 809 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e10" ) == fromEndfReactionNumber( proton, Fe56_e0, 810 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e11" ) == fromEndfReactionNumber( proton, Fe56_e0, 811 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e12" ) == fromEndfReactionNumber( proton, Fe56_e0, 812 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e13" ) == fromEndfReactionNumber( proton, Fe56_e0, 813 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e14" ) == fromEndfReactionNumber( proton, Fe56_e0, 814 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e15" ) == fromEndfReactionNumber( proton, Fe56_e0, 815 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e16" ) == fromEndfReactionNumber( proton, Fe56_e0, 816 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e17" ) == fromEndfReactionNumber( proton, Fe56_e0, 817 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e18" ) == fromEndfReactionNumber( proton, Fe56_e0, 818 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e19" ) == fromEndfReactionNumber( proton, Fe56_e0, 819 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e20" ) == fromEndfReactionNumber( proton, Fe56_e0, 820 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e21" ) == fromEndfReactionNumber( proton, Fe56_e0, 821 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e22" ) == fromEndfReactionNumber( proton, Fe56_e0, 822 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e23" ) == fromEndfReactionNumber( proton, Fe56_e0, 823 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e24" ) == fromEndfReactionNumber( proton, Fe56_e0, 824 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e25" ) == fromEndfReactionNumber( proton, Fe56_e0, 825 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e26" ) == fromEndfReactionNumber( proton, Fe56_e0, 826 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e27" ) == fromEndfReactionNumber( proton, Fe56_e0, 827 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e28" ) == fromEndfReactionNumber( proton, Fe56_e0, 828 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e29" ) == fromEndfReactionNumber( proton, Fe56_e0, 829 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e30" ) == fromEndfReactionNumber( proton, Fe56_e0, 830 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e31" ) == fromEndfReactionNumber( proton, Fe56_e0, 831 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e32" ) == fromEndfReactionNumber( proton, Fe56_e0, 832 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e33" ) == fromEndfReactionNumber( proton, Fe56_e0, 833 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e34" ) == fromEndfReactionNumber( proton, Fe56_e0, 834 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e35" ) == fromEndfReactionNumber( proton, Fe56_e0, 835 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e36" ) == fromEndfReactionNumber( proton, Fe56_e0, 836 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e37" ) == fromEndfReactionNumber( proton, Fe56_e0, 837 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e38" ) == fromEndfReactionNumber( proton, Fe56_e0, 838 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e39" ) == fromEndfReactionNumber( proton, Fe56_e0, 839 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e40" ) == fromEndfReactionNumber( proton, Fe56_e0, 840 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e41" ) == fromEndfReactionNumber( proton, Fe56_e0, 841 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e42" ) == fromEndfReactionNumber( proton, Fe56_e0, 842 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e43" ) == fromEndfReactionNumber( proton, Fe56_e0, 843 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e44" ) == fromEndfReactionNumber( proton, Fe56_e0, 844 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e45" ) == fromEndfReactionNumber( proton, Fe56_e0, 845 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e46" ) == fromEndfReactionNumber( proton, Fe56_e0, 846 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e47" ) == fromEndfReactionNumber( proton, Fe56_e0, 847 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53_e48" ) == fromEndfReactionNumber( proton, Fe56_e0, 848 ) );
      CHECK( ReactionID( "p,Fe56->he4,Mn53[continuum]" ) == fromEndfReactionNumber( proton, Fe56_e0, 849 ) );
      CHECK( ReactionID( "p,Fe56->n,n,Co55" ) == fromEndfReactionNumber( proton, Fe56_e0, 875 ) );
      CHECK( ReactionID( "p,Fe56->n,n,Co55_e1" ) == fromEndfReactionNumber( proton, Fe56_e0, 876 ) );
      CHECK( ReactionID( "p,Fe56->n,n,Co55_e2" ) == fromEndfReactionNumber( proton, Fe56_e0, 877 ) );
      CHECK( ReactionID( "p,Fe56->n,n,Co55_e3" ) == fromEndfReactionNumber( proton, Fe56_e0, 878 ) );
      CHECK( ReactionID( "p,Fe56->n,n,Co55_e4" ) == fromEndfReactionNumber( proton, Fe56_e0, 879 ) );
      CHECK( ReactionID( "p,Fe56->n,n,Co55_e5" ) == fromEndfReactionNumber( proton, Fe56_e0, 880 ) );
      CHECK( ReactionID( "p,Fe56->n,n,Co55_e6" ) == fromEndfReactionNumber( proton, Fe56_e0, 881 ) );
      CHECK( ReactionID( "p,Fe56->n,n,Co55_e7" ) == fromEndfReactionNumber( proton, Fe56_e0, 882 ) );
      CHECK( ReactionID( "p,Fe56->n,n,Co55_e8" ) == fromEndfReactionNumber( proton, Fe56_e0, 883 ) );
      CHECK( ReactionID( "p,Fe56->n,n,Co55_e9" ) == fromEndfReactionNumber( proton, Fe56_e0, 884 ) );
      CHECK( ReactionID( "p,Fe56->n,n,Co55_e10" ) == fromEndfReactionNumber( proton, Fe56_e0, 885 ) );
      CHECK( ReactionID( "p,Fe56->n,n,Co55_e11" ) == fromEndfReactionNumber( proton, Fe56_e0, 886 ) );
      CHECK( ReactionID( "p,Fe56->n,n,Co55_e12" ) == fromEndfReactionNumber( proton, Fe56_e0, 887 ) );
      CHECK( ReactionID( "p,Fe56->n,n,Co55_e13" ) == fromEndfReactionNumber( proton, Fe56_e0, 888 ) );
      CHECK( ReactionID( "p,Fe56->n,n,Co55_e14" ) == fromEndfReactionNumber( proton, Fe56_e0, 889 ) );
      CHECK( ReactionID( "p,Fe56->n,n,Co55_e15" ) == fromEndfReactionNumber( proton, Fe56_e0, 890 ) );
      CHECK( ReactionID( "p,Fe56->n,n,Co55[continuum]" ) == fromEndfReactionNumber( proton, Fe56_e0, 891 ) );
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
