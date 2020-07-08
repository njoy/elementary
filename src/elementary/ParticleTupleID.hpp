#ifndef NJOY_ELEMENTARY_PARTICLETUPLEID
#define NJOY_ELEMENTARY_PARTICLETUPLEID

// system includes
#include <string>

// other includes
#include "elementary/Identifier.hpp"
#include "elementary/ParticleID.hpp"

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
    bool validate( const std::string& ) const { return true; }
    std::string name() const { return "tuple of particles"; }

  public:

    /* constructor */
    using Identifier::Identifier;

    /* methods */

  };
} // elementary namespace
} // njoy namespace

#endif
