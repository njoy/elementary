#ifndef NJOY_ELEMENTARY_FROMENDFREACTIONNUMBER
#define NJOY_ELEMENTARY_FROMENDFREACTIONNUMBER

// system includes

// other includes
#include "elementary/ParticleID.hpp"
#include "elementary/ReactionType.hpp"
#include "elementary/ReactionID.hpp"

namespace njoy {
namespace elementary {

  /**
   *  @brief Return a reaction identifier corresponding to the given MT number
   *
   *  @param[in] incident   the incident particle identifier
   *  @param[in] target     the target particle identifier
   *  @param[in] mt         the MT number
   */
  ReactionID fromEndfReactionNumber( const ParticleID& incident,
                                     const ParticleID& target,
                                     int mt ) {

    // generate the incident pair
    ParticlePairID incidentPair( incident, target );

    try {

      return ReactionID( incident, target, ReactionType( mt ) );
    }
    catch ( const std::invalid_argument& ) {

      throw std::invalid_argument(
                "The reaction identifier for '" + incidentPair.symbol() + "' "
                "and MT=" + std::to_string( mt ) + " could not be created" );
    }
  }
} // elementary namespace
} // njoy namespace

#endif
