#ifndef NJOY_ELEMENTARY_PARTICLEID
#define NJOY_ELEMENTARY_PARTICLEID

// system includes
#include <string>
#include <variant>

// other includes
#include "elementary/src/overload.hpp"
#include "elementary/FundamentalParticleID.hpp"
#include "elementary/NucleusID.hpp"
#include "elementary/NuclideID.hpp"

namespace njoy {
namespace elementary {

  /**
   *  @class
   *  @brief The particle identifier, either a fundamental particle, a nucleus
   *         or nuclide identifier
   */
  class ParticleID {

    /* type aliases */
    using IdentifierVariant = std::variant< FundamentalParticleID, NucleusID, NuclideID >;

    /* fields */
    IdentifierVariant identifier_;

    /* auxiliary functions */

  public:

    /* constructor */
    #include "elementary/ParticleID/src/ctor.hpp"

    /* methods */

    /**
     *  @brief return the particle symbol
     */
    std::string symbol() const noexcept {

      return std::visit( [] ( const auto& identifier )
                            { return identifier.symbol(); },
                         this->identifier_ );
    }

    /**
     *  @brief return the nuclide name
     */
    std::string name() const noexcept {

      return std::visit( [] ( const auto& identifier )
                            { return identifier.name(); },
                         this->identifier_ );
    }

    /**
     *  @brief return the nuclide hash value
     */
    int hash() const noexcept {

      return std::visit(
               overload{ [] ( const FundamentalParticleID& identifier )
                            { return identifier.hash(); },
                         [] ( const NucleusID& identifier )
                            { return identifier.hash() * 10; },
                         [] ( const NuclideID& identifier )
                            { return identifier.hash() * 10 + 1; } },
               this->identifier_ );
    }

    /**
     *  @brief operator<()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator<( const ParticleID& right ) const noexcept {

      return this->hash() < right.hash();
    }

    /**
     *  @brief operator==()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator==( const ParticleID& right ) const noexcept {

      return this->hash() == right.hash();
    }

    /**
     *  @brief operator!=()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator!=( const ParticleID& right ) const noexcept {

      return this->hash() != right.hash();
    }
  };
} // elementary namespace
} // njoy namespace

#endif
