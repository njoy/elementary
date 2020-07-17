#ifndef NJOY_ELEMENTARY_TOENDFREACTIONNUMBER
#define NJOY_ELEMENTARY_TOENDFREACTIONNUMBER

// system includes
#include <algorithm>

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

    if ( not identifier.isSpecial() ) {

      // get the incident and outgoing particle information
      const auto incident = identifier.incident();
      const auto outgoing = identifier.outgoing();
      const auto incidentResidual = incident.residual();
      const auto outgoingParticles = outgoing.particles();
      const auto outgoingResidual = outgoing.residual();

      // elastic scattering is a special case
      if ( incidentResidual == outgoingResidual ) {

        return 2;
      }
      else {

        std::map< char, unsigned int > counts;
        for ( const auto& particle : outgoingParticles ) {

          auto za = particle.za();
          if ( za == 1 ) { ++counts[ 'n' ]; }
          else if ( za == 1001 ) { ++counts[ 'p' ]; }
          else if ( za == 1002 ) { ++counts[ 'd' ]; }
          else if ( za == 1003 ) { ++counts[ 't' ]; }
          else if ( za == 2003 ) { ++counts[ 'h' ]; }
          else if ( za == 2004 ) { ++counts[ 'a' ]; }
          else {

            return 0;
          }
        }

        std::string p;
        for ( const auto& [ particle, number ] : counts ) {

          if ( number != 0 ) {

            p += number > 1 ? std::to_string( number ) : "";
            p += particle;
          }
        }
        auto level = outgoingResidual.level().number();
        std::string e = p + ( outgoingResidual.level() == Level::continuum
                                ? "(c)"
                                : "(" + std::to_string( level ) + ")" );

        if ( ReactionType::isRegistered( e ) ) {

          return ReactionType( e ).mt();
        }
        else if ( ReactionType::isRegistered( p ) ) {

          return ReactionType( p ).mt();
        }
      }
    }
    else {

      auto special = split( identifier.symbol(), "->" ).back();
      if ( ReactionType::isRegistered( special ) ) {

        return ReactionType( special ).mt();
      }
    }

    return 0;
  }
} // elementary namespace
} // njoy namespace

#endif
