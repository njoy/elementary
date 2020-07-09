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
    bool validate( const std::string& ) const { return true; }
    std::string name() const { return "tuple of particles"; }

  public:

    /* constructor */
    ParticleTupleID( const std::string& identifier ) : JoinedIdentifier( identifier ) {};

    /* methods */
    using JoinedIdentifier::symbol;
    using JoinedIdentifier::operator<;
    using JoinedIdentifier::operator==;
    using JoinedIdentifier::operator!=;
  };
} // elementary namespace
} // njoy namespace

#endif
