#ifndef NJOY_ELEMENTARY_PARTICLEREACTION
#define NJOY_ELEMENTARY_PARTICLEREACTION

// system includes
#include <string>

// other includes
#include "elementary/src/split.hpp"
#include "elementary/Identifier.hpp"
#include "elementary/ParticlePairID.hpp"
#include "elementary/ParticleTupleID.hpp"

namespace njoy {
namespace elementary {

  /**
   *  @class
   *  @brief The identifier for a reaction
   */
  class ReactionID : public Identifier< ReactionID > {

    friend Identifier< ReactionID >;

    /* fields */

    /* auxiliary functions */
    static std::string name() { return "a reaction"; }

  public:

    /* constructor */
    #include "elementary/ReactionID/src/ctor.hpp"

    /* methods */
    #include "elementary/ReactionID/src/validate.hpp"

    using Identifier::symbol;
    using Identifier::operator<;
    using Identifier::operator==;
    using Identifier::operator!=;
  };
} // elementary namespace
} // njoy namespace

#endif
