#ifndef NJOY_ELEMENTARY_TOENDFREACTIONNUMBER
#define NJOY_ELEMENTARY_TOENDFREACTIONNUMBER

// system includes

// other includes
#include "elementary/src/split.hpp"
#include "elementary/ParticlePairID.hpp"
#include "elementary/ParticleTupleID.hpp"
#include "elementary/ReactionID.hpp"

namespace njoy {
namespace elementary {

  /**
   *  @brief Return the MT number for the reaction, if one can be derived
   *
   *  @param[in] identifier   the reaction identifier
   */
  int toEndfReactionNumber( const ReactionID& identifier ) {

    int mt = 0;

    auto tuples = split( identifier.symbol(), "->" );
    if ( tuples[0] == tuples[1] ) {

      return 2;
    }

    return mt;
  }
} // elementary namespace
} // njoy namespace

#endif
