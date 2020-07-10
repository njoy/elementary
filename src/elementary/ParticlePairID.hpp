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

    using Identifier::symbol;
    using Identifier::operator<;
    using Identifier::operator==;
    using Identifier::operator!=;
  };
} // elementary namespace
} // njoy namespace

#endif
