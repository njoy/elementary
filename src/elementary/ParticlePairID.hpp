#ifndef NJOY_ELEMENTARY_PARTICLEPAIRID
#define NJOY_ELEMENTARY_PARTICLEPAIRID

// system includes
#include <string>

// other includes
#include "elementary/ParticleTupleID.hpp"

namespace njoy {
namespace elementary {

  /**
   *  @class
   *  @brief The identifier for the special case of a particle pair
   */
  class ParticlePairID : public ParticleTupleID {

    friend Identifier< ParticleTupleID >;

    /* fields */

    /* auxiliary functions */
    static std::string name() { return "particle pair"; }

  public:

    /* constructor */
    #include "elementary/ParticlePairID/src/ctor.hpp"

    /* methods */
    #include "elementary/ParticlePairID/src/validate.hpp"

    using ParticleTupleID::symbol;
    using ParticleTupleID::operator<;
    using ParticleTupleID::operator==;
    using ParticleTupleID::operator!=;
  };
} // elementary namespace
} // njoy namespace

#endif
