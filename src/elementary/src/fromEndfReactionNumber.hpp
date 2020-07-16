#ifndef NJOY_ELEMENTARY_FROMENDFREACTIONNUMBER
#define NJOY_ELEMENTARY_FROMENDFREACTIONNUMBER

// system includes

// other includes
#include "elementary/ParticleID.hpp"
#include "elementary/ParticlePairID.hpp"
#include "elementary/ParticleTupleID.hpp"
#include "elementary/ReactionType.hpp"
#include "elementary/ReactionID.hpp"
#include "elementary/src/absorb.hpp"
#include "elementary/src/emit.hpp"

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

      // get the MT number
      ReactionType endf( mt );

      // special cases: no particles given
      std::vector< ParticleID > particles = endf.particles();
      if ( not particles.size() ) {

        if ( endf.name() == "elastic" ) {

          return ReactionID( incidentPair, incidentPair );
        }
      }
      else {

        // produce the residual
        auto isotope = absorb( target, incident );
        for ( const auto& particle : particles ) {

          isotope = emit( isotope, particle );
        }
        ParticleID residual( NuclideID( isotope.za(), endf.level() ) );

        // create the outgoing particle tuple
        particles.push_back( residual );
        ParticleTupleID outgoingTuple( particles );

        return ReactionID( incidentPair, outgoingTuple );
      }
    }
    catch ( const std::invalid_argument& ) {

      throw std::invalid_argument(
                "The reaction identifier for '" + incidentPair.symbol() + "' "
                "and MT=" + std::to_string( mt ) + " could not be created" );
    }

    // throw exception if we get to this point
    throw std::invalid_argument(
              "The reaction identifier for '" + incidentPair.symbol() + "' "
              "and MT=" + std::to_string( mt ) + " could not be created" );
  }
} // elementary namespace
} // njoy namespace

#endif
