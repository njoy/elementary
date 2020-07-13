#ifndef NJOY_ELEMENTARY_PARTICLETUPLEID
#define NJOY_ELEMENTARY_PARTICLETUPLEID

// system includes
#include <string>
#include <vector>

// other includes
#include "elementary/src/join.hpp"
#include "elementary/src/split.hpp"
#include "elementary/Identifier.hpp"
#include "elementary/ParticleID.hpp"
#include "elementary/ParticlePairID.hpp"

namespace njoy {
namespace elementary {

  /**
   *  @class
   *  @brief The identifier for a tuple of particles (a particle pair being a
   *         special case)
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

    using Identifier::symbol;
    using Identifier::operator<;
    using Identifier::operator==;
    using Identifier::operator!=;
  };
} // elementary namespace
} // njoy namespace

#endif
