#ifndef NJOY_ELEMENTARY_PARTICLETUPLEID
#define NJOY_ELEMENTARY_PARTICLETUPLEID

// system includes
#include <string>
#include <vector>

// other includes
#include "utility/join.hpp"
#include "utility/split.hpp"
#include "elementary/Identifier.hpp"
#include "elementary/ParticleID.hpp"
#include "elementary/ParticlePairID.hpp"
#include "elementary/ReactionType.hpp"

namespace njoy {
namespace elementary {

  /**
   *  @class
   *  @brief The identifier for a tuple of particles
   *
   *  A particle tuple represents an n-body exit reaction channel. The tuple
   *  consists of a number of "small" particles (e.g. a neutron, photon, alpha,
   *  etc.) and a "larger" residual nucleus (e.g. H1, He4, U235, etc.).
   *
   *  The symbol of the particle identifier consists of at least two valid
   *  particle identifiers separated by a comma. For example:
   *    - "n,Fe56" for a neutron and the Fe56 nuclide
   *    - "n,p,he4" for a neutron, proton and an alpha particle
   *
   *  The order in which these are given is important. The last one is
   *  considered the "residual", all others are considered "particles".
   *
   *  Comparison operators are provided using the logical order given by the
   *  symbol. A hash function and override for std::hash is also provided.
   */
  class ParticleTupleID : public Identifier< ParticleTupleID > {

    friend Identifier< ParticleTupleID >;

    /* fields */

    /* auxiliary functions */
    static std::string name() { return "a tuple of particles"; }
    #include "elementary/ParticleTupleID/src/generate.hpp"

  public:

    /* constructor */
    #include "elementary/ParticleTupleID/src/ctor.hpp"

    /* methods */
    #include "elementary/ParticleTupleID/src/validate.hpp"
    #include "elementary/ParticleTupleID/src/particles.hpp"

    /**
     *  @brief Return the particle identifier for the residual in the tuple
     */
    ParticleID residual() const noexcept {

      return ParticleID( utility::split( this->symbol(), "," ).back() );
    }

    using Identifier::symbol;
    using Identifier::operator<;
    using Identifier::operator==;
    using Identifier::operator!=;
  };
} // elementary namespace
} // njoy namespace

namespace std {

  // std::hash override for the ParticleTupleID class
  template <>
  struct hash< njoy::elementary::ParticleTupleID > {

    size_t operator()( const njoy::elementary::ParticleTupleID& key ) const {

      return key.hash();
    }
  };

} // namespace std

#endif
