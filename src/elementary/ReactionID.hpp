#ifndef NJOY_ELEMENTARY_REACTIONID
#define NJOY_ELEMENTARY_REACTIONID

// system includes
#include <string>

// other includes
#include "elementary/src/split.hpp"
#include "elementary/Identifier.hpp"
#include "elementary/ParticleID.hpp"
#include "elementary/ReactionType.hpp"
#include "elementary/ParticlePairID.hpp"
#include "elementary/ParticleTupleID.hpp"
#include "elementary/src/absorb.hpp"
#include "elementary/src/emit.hpp"

namespace njoy {
namespace elementary {

  /**
   *  @class
   *  @brief The identifier for a reaction
   *
   *  A reaction is represented by an two body entrance reaction channel and
   *  an n-body exit reaction channel.
   *
   *  The symbol of the reaction identifier consists of two valid particle
   *  tuple identifiers separated by an arrow. For example:
   *    - "n,Fe56->n,Fe56" for elastic neutron scattering on Fe56
   *    - "n,he4->h2,h3" for a neutron on alpha resulting in a deuteron and
   *      triton
   */
  class ReactionID : public Identifier< ReactionID > {

    friend Identifier< ReactionID >;

    /* fields */

    /* auxiliary functions */
    static std::string name() { return "a reaction"; }
    #include "elementary/ReactionID/src/fromReactionType.hpp"

  public:

    /* constructor */
    #include "elementary/ReactionID/src/ctor.hpp"

    /* methods */
    #include "elementary/ReactionID/src/validate.hpp"

    /**
     *  @brief Return the incident particle pair identifier for the reaction
     */
    ParticlePairID incident() const noexcept {

      return ParticlePairID( split( this->symbol(), "->" ).front(), false );
    }

    /**
     *  @brief Return the exit particle tuple identifier for the reaction
     */
    ParticleTupleID outgoing() const noexcept {

      return ParticleTupleID( split( this->symbol(), "->" ).back(), false );
    }

    using Identifier::symbol;
    using Identifier::operator<;
    using Identifier::operator==;
    using Identifier::operator!=;
  };
} // elementary namespace
} // njoy namespace

#endif
