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
    static std::string name() { return "tuple of particles"; }
    static std::string separator() { return ","; }
    #include "elementary/ParticleTupleID/src/generate.hpp"

  public:

    /* constructor */
    #include "elementary/ParticleTupleID/src/ctor.hpp"

    /* methods */
    /**
     *  @brief Verify if a string is a valid ParticleTupleID
     *
     *  @param[in] string   the string to be valdiated
     */
    static bool validate( const std::string& ) {

      return true;
    }

    using JoinedIdentifier::symbol;
    using JoinedIdentifier::operator<;
    using JoinedIdentifier::operator==;
    using JoinedIdentifier::operator!=;
  };
} // elementary namespace
} // njoy namespace

#endif
