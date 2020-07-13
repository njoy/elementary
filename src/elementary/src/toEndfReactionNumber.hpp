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

    // treat special cases

    // other cases

    // get the incident and outgoing particle information
    const auto incident = identifier.incident();
    const auto outgoing = identifier.outgoing();
//    const auto incidentParticle = incident.particle();
    const auto incidentResidual = incident.residual();
    const auto outgoingParticles = outgoing.particles();
    const auto outgoingResidual = outgoing.residual();

    // elastic scattering
    if ( incidentResidual == outgoingResidual ) {

      return 2;
    }

    return 0;
  }
} // elementary namespace
} // njoy namespace

#endif
