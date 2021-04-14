#ifndef NJOY_ELEMENTARY_SPECIALDATAID
#define NJOY_ELEMENTARY_SPECIALDATAID

// system includes
#include <string>

// other includes
#include "utility/split.hpp"
#include "elementary/Identifier.hpp"
#include "elementary/ParticleID.hpp"
#include "elementary/ParticlePairID.hpp"
#include "elementary/SpecialDataType.hpp"

namespace njoy {
namespace elementary {

  /**
   *  @class
   *  @brief The identifier for special data
   *
   *  The special data identifier is an identifier for things that cannot be
   *  considered reactions in their own right. An example of this would be
   *  nubar, which is not the fission reaction but the fission neutron
   *  multiplicity. ENDF rules cloud this distinction while GNDS does not.
   *
   *  The symbol of the special data identifier consists of a valid particle
   *  pair identifier and the special data type symbol separated by an arrow.
   *  For example:
   *    - "n,U235->nubar,total" for U235 total neutron induced fission nubar
   *    - "n,U235->qfission" for U235 fission energy release data
   *    - "n,Be9->xp" for the total proton production cross section on Be9
   *
   *  Comparison operators are provided using the logical order given by the
   *  symbol. A hash function and override for std::hash is also provided.
   */
  class SpecialDataID : public Identifier< SpecialDataID > {

    friend Identifier< SpecialDataID >;

    /* fields */

    /* auxiliary functions */
    static std::string name() { return "special data"; }

  public:

    /* constructor */
    #include "elementary/SpecialDataID/src/ctor.hpp"

    /* methods */
    #include "elementary/SpecialDataID/src/validate.hpp"

    /**
     *  @brief Return the incident particle pair identifier for the reaction
     */
    ParticlePairID incident() const noexcept {

      return ParticlePairID(
                 utility::split( this->symbol(), "->" ).front(), false );
    }

    using Identifier::hash;
    using Identifier::symbol;
    using Identifier::operator<;
    using Identifier::operator<=;
    using Identifier::operator>;
    using Identifier::operator>=;
    using Identifier::operator==;
    using Identifier::operator!=;
  };
} // elementary namespace
} // njoy namespace

namespace std {

  // std::hash override for the SpecialDataID class
  template <>
  struct hash< njoy::elementary::SpecialDataID > {

    size_t operator()( const njoy::elementary::SpecialDataID& key ) const {

      return key.hash();
    }
  };

} // namespace std

#endif
