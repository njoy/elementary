#ifndef NJOY_ELEMENTARY_EMIT
#define NJOY_ELEMENTARY_EMIT

// system includes

// other includes
#include "elementary/IsotopeID.hpp"

namespace njoy {
namespace elementary {

  /**
   *  @brief Return the isotope identifier when a compound emits a particle
   *
   *  @param[in] compound   the compound identifier (fundamental particle,
   *                        isotope, nucleus, nuclide or the general particle)
   *  @param[in] particle   the emitted particle identifier (fundamental
   *                        particle, isotope, nucleus, nuclide or the general
   *                        particle)
   *
   *  @throws invalid_argument   the particle cannot be emitted
   */
  template < typename Compound, typename Particle >
  inline IsotopeID emit( const Compound& compound, const Particle& particle ) {

    try {

      return IsotopeID( compound.za() - particle.za() );
    }
    catch ( const std::invalid_argument& ) {

      throw std::invalid_argument(
                "The compound '" + compound.symbol() + "' cannot emit "
                "the particle '" + particle.symbol() + "'" );
    }
  }
} // elementary namespace
} // njoy namespace

#endif
