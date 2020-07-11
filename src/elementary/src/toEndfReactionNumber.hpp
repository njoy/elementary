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

    // calculate the total za value of the secondary particles
    int za = 0;
    for ( const auto& id : outgoingParticles ) {

      za += id.za();
    }

    // elastic scattering
    if ( incidentResidual == outgoingResidual ) {

      return 2;
    }

    // lookup based on emitted particles
    switch ( za ) {

      // a single neutron - potential inelastic scattering
      case 1 : {

        const auto level = outgoingResidual.level();
        if ( level <= 50 ) { return 50 + level; }
        break;
      }
      case 2 : {

        const auto level = outgoingResidual.level();
        if ( level <= 15 ) { return 875 + level; }
        break;
      }
      case 3 : { return 17; }
      case 4 : { return 37; }
      default : { break; }
    }

    return 0;
  }
} // elementary namespace
} // njoy namespace

#endif
