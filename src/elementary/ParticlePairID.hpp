#ifndef NJOY_ELEMENTARY_PARTICLEPAIRID
#define NJOY_ELEMENTARY_PARTICLEPAIRID

// system includes
#include <string>

// other includes
#include "elementary/src/split.hpp"
#include "elementary/ParticleID.hpp"
#include "elementary/Identifier.hpp"

namespace njoy {
namespace elementary {

  /**
   *  @class
   *  @brief The identifier for the special case of a particle pair
   *
   *  A particle pair represents the two particles involved in a entrance
   *  reaction channel or two body exit reaction channel. The pair consists of
   *  a "small" incident or outgoing particle (e.g. a neutron, photon, alpha,
   *  etc.) and a "larger" target or residual nucleus (e.g. H1, He4, U235,
   *  etc.).
   *
   *  The symbol of the particle identifier consists of two valid particle
   *  identifiers separated by a comma. For example:
   *    - "n,Fe56" for a neutron and the Fe56 nuclide
   *    - "n,he4" for a neutron and an alpha particle
   *    - "h3,h2" for a triton and a deuteron particle
   *
   *  The order in which these are given determines which particle is
   *  considered the "particle" and which is the "residual".
   */
  class ParticlePairID : public Identifier< ParticlePairID > {

    friend Identifier< ParticlePairID >;

    /* fields */

    /* auxiliary functions */
    static std::string name() { return "a particle pair"; }

  public:

    /* constructor */
    #include "elementary/ParticlePairID/src/ctor.hpp"

    /* methods */
    #include "elementary/ParticlePairID/src/validate.hpp"

    /**
     *  @brief Return the particle identifier for the particle in the pair
     */
    ParticleID particle() const noexcept {

      return ParticleID( split( this->symbol(), "," ).front() );
    }

    /**
     *  @brief Return the particle identifier for the residual in the pair
     */
    ParticleID residual() const noexcept {

      return ParticleID( split( this->symbol(), "," ).back() );
    }

    using Identifier::symbol;
    using Identifier::operator<;
    using Identifier::operator==;
    using Identifier::operator!=;
  };
} // elementary namespace
} // njoy namespace

#endif
