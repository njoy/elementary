#ifndef NJOY_ELEMENTARY_PARTICLETUPLEID
#define NJOY_ELEMENTARY_PARTICLETUPLEID

// system includes
#include <string>

// other includes
#include "elementary/Identifier.hpp"
#include "elementary/JoinedIdentifier.hpp"
#include "elementary/ParticleID.hpp"

namespace njoy {
namespace elementary {

  /**
   *  @class
   *  @brief The identifier for a tuple of particles (a particle pair being a
   *         special case)
   */
  class ParticleTupleID : public JoinedIdentifier< ParticleTupleID > {

    friend Identifier< ParticleTupleID >;
    friend JoinedIdentifier< ParticleTupleID >;

    /* fields */

    /* auxiliary functions */
    static bool validate( const std::string& ) { return true; }
    static std::string name() { return "tuple of particles"; }
    static std::string separator() { return ","; }
    #include "elementary/ParticleTupleID/src/generate.hpp"

  public:

    /* constructor */
    #include "elementary/ParticleTupleID/src/ctor.hpp"

    /* methods */
    using JoinedIdentifier::symbol;
    using JoinedIdentifier::operator<;
    using JoinedIdentifier::operator==;
    using JoinedIdentifier::operator!=;
  };
} // elementary namespace
} // njoy namespace

#endif
