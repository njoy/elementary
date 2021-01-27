#ifndef NJOY_ELEMENTARY_PARTICLEID
#define NJOY_ELEMENTARY_PARTICLEID

// system includes
#include <string>
#include <variant>

// other includes
#include "utility/overload.hpp"
#include "elementary/FundamentalParticleID.hpp"
#include "elementary/NucleusID.hpp"
#include "elementary/NuclideID.hpp"

namespace njoy {
namespace elementary {

  /**
   *  @class
   *  @brief The particle identifier, either a fundamental particle, a nucleus
   *         or nuclide identifier
   *
   *  Comparison operators are provided using the logical order given by the
   *  symbol. A hash function and override for std::hash is also provided.
   */
  class ParticleID {

    /* type aliases */
    using IdentifierVariant = std::variant< FundamentalParticleID,
                                            NucleusID,
                                            NuclideID >;

    /* fields */
    IdentifierVariant identifier_;

    /* auxiliary functions */
    #include "elementary/ParticleID/src/matchIdentifier.hpp"

  public:

    /* constructor */
    #include "elementary/ParticleID/src/ctor.hpp"

    /* methods */

    /**
     *  @brief return whether or not the particle is a fundamental particle
     */
    bool isFundamentalParticle() const noexcept {

      return this->identifier_.index() == 0;
    }

    /**
     *  @brief return whether or not the particle is a nucleus
     */
    bool isNucleus() const noexcept {

      return this->identifier_.index() == 1;
    }

    /**
     *  @brief return whether or not the particle is a nuclide
     */
    bool isNuclide() const noexcept {

      return this->identifier_.index() == 2;
    }

    /**
     *  @brief return the particle symbol
     */
    std::string symbol() const noexcept {

      return std::visit( [] ( const auto& identifier )
                            { return identifier.symbol(); },
                         this->identifier_ );
    }

    /**
     *  @brief return the particle name
     */
    std::string name() const noexcept {

      return std::visit( [] ( const auto& identifier )
                            { return identifier.name(); },
                         this->identifier_ );
    }

    /**
     *  @brief return the particle za value
     */
    int za() const noexcept {

      return std::visit( [] ( const auto& identifier )
                            { return identifier.za(); },
                         this->identifier_ );
    }

    /**
     *  @brief return the particle excited state number
     */
    Level level() const noexcept {

      return std::visit(
               utility::overload{ [] ( const FundamentalParticleID& )
                                     { return Level( 0 ); },
                                  [] ( const NucleusID& identifier )
                                     { return identifier.level(); },
                                  [] ( const NuclideID& identifier )
                                     { return identifier.level(); } },
               this->identifier_ );
    }

    /**
     *  @brief return the nuclide hash value
     */
    int hash() const noexcept {

      return std::visit(
               utility::overload{ [] ( const FundamentalParticleID& identifier )
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

namespace std {

  // std::hash override for the ParticleID class
  template <>
  struct hash< njoy::elementary::ParticleID > {

    size_t operator()( const njoy::elementary::ParticleID& key ) const {

      return key.hash();
    }
  };

} // namespace std

#endif
