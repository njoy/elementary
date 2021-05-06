#ifndef NJOY_ELEMENTARY_ABSORB
#define NJOY_ELEMENTARY_ABSORB

// system includes

// other includes
#include "elementary/IsotopeID.hpp"

namespace njoy {
namespace elementary {

  /**
   *  @brief Return the isotope identifier when a compound absorbs a particle
   *
   *  @param[in] compound   the compound identifier (fundamental particle,
   *                        isotope, nucleus, nuclide or the general particle)
   *  @param[in] particle   the absorbed particle identifier (fundamental
   *                        particle, isotope, nucleus, nuclide or the general
   *                        particle)
   */
  template < typename Compound, typename Particle >
  inline IsotopeID absorb( const Compound& compound, const Particle& particle ) {

    try {

      return IsotopeID( compound.za() + particle.za() );
    }
    catch ( const std::invalid_argument& ) {

      throw std::invalid_argument(
                "The compound '" + compound.symbol() + "' cannot absorb "
                "the particle '" + particle.symbol() + "'" );
    }
  }
} // elementary namespace
} // njoy namespace

#endif
