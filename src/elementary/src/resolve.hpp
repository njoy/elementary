#ifndef NJOY_ELEMENTARY_RESOLVE
#define NJOY_ELEMENTARY_RESOLVE

// system includes

// other includes
#include "elementary/ParticleID.hpp"
#include "elementary/ReactionType.hpp"
#include "elementary/src/absorb.hpp"
#include "elementary/src/emit.hpp"

namespace njoy {
namespace elementary {

  /**
   *  @brief Return the particle identifier for the residual particle
   *
   *  @param[in] incident   the incident particle identifier
   *  @param[in] target     the target particle identifier
   *  @param[in] type       the reaction type
   */
  ParticleID resolve( const ParticleID& incident, const ParticleID& target,
                      const ReactionType& type ) {

    if ( type.name() == "elastic" ) {

      return target;
    }
    else if ( type.isSpecial() ) {

      throw std::invalid_argument(
                "The daughter nuclide cannot be determined for the special "
                "reaction '" + incident.symbol() + "," + target.symbol() + "->"
                + type.name() + "'" );
    }
    else {

      // get the emitted particles
      std::vector< ParticleID > particles = type.particles();

      // produce the residual
      try {

        auto isotope = absorb( target, incident );
        for ( const auto& particle : particles ) {

          isotope = emit( isotope, particle );
        }

        return target.isNuclide()
                   ? ParticleID( NuclideID( isotope.za(), type.level() ) )
                   : ParticleID( NucleusID( isotope.za(), type.level() ) );
      }
      catch ( const std::invalid_argument& ) {

        throw std::invalid_argument(
                  "The daughter nuclide cannot be determined for the reaction "
                  "type '" + type.name() + "' for '" + incident.symbol() + ","
                  + target.symbol() + "' because the reaction is impossible" );
      }
    }
  }
} // elementary namespace
} // njoy namespace

#endif
