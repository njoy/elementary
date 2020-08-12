#ifndef NJOY_ELEMENTARY_TOENDFREACTIONNUMBER
#define NJOY_ELEMENTARY_TOENDFREACTIONNUMBER

// system includes
#include <array>
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
      if ( ( incidentResidual.za() == outgoingResidual.za() ) and
           ( outgoingResidual.level() == 0 ) ) {

        return 2;
      }
      else {

        std::array< unsigned int, 6 > counts = {{ 0, 0, 0, 0, 0, 0 }};
        std::array< char, 6 > symbols = {{ 'n', 'p', 'd', 't', 'h', 'a' }};
        for ( const auto& particle : outgoingParticles ) {

          auto za = particle.za();
          if ( za == 1 ) { ++counts[ 0 ]; }
          else if ( za == 1001 ) { counts[ 1 ] += 1; }
          else if ( za == 1002 ) { counts[ 2 ] += 1; }
          else if ( za == 1003 ) { counts[ 3 ] += 1; }
          else if ( za == 2003 ) { counts[ 4 ] += 1; }
          else if ( za == 2004 ) { counts[ 5 ] += 1; }
          else {

            return 0;
          }
        }

        std::string p;
        for ( unsigned int i = 0; i < 6; ++i ) {

          auto number = counts[i];
          auto particle = symbols[i];
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
