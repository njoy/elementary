#ifndef NJOY_ELEMENTARY_FUNDAMENTALPARTICLEID
#define NJOY_ELEMENTARY_FUNDAMENTALPARTICLEID

// system includes
#include <string>

// other includes
#include "elementary/src/tolower.hpp"

namespace njoy {
namespace elementary {

  /**
   *  @class
   *  @brief The fundamental particle identifier, with associated symbol and
   *         name
   */
  class FundamentalParticleID {

    /* type aliases */
    using Hash = short;

    /* helper class */
    #include "elementary/FundamentalParticleID/Entry.hpp"

    /* static fields */
    #include "elementary/FundamentalParticleID/src/register.hpp"

    /* fields */
    Hash hash_;

    /* auxiliary functions */
    #include "elementary/FundamentalParticleID/src/lookup.hpp"

  public:

    /* constructor */
    #include "elementary/FundamentalParticleID/src/ctor.hpp"

    /* methods */

    /**
     *  @brief return the fundamental particle za value
     */
    int za() const noexcept { return this->hash_; }

    /**
     *  @brief return the fundamental particle hash value
     */
    int hash() const noexcept { return this->za(); }

    /**
     *  @brief return the fundamental particle symbol
     */
    auto symbol() const noexcept {

      return
      FundamentalParticleID::particle_dictionary.at( this->hash() ).symbol();
    }

    /**
     *  @brief return the fundamental particle name
     */
    const std::string& name() const noexcept {

      return
      FundamentalParticleID::particle_dictionary.at( this->hash() ).name();
    }

    /**
     *  @brief operator<()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator<( const FundamentalParticleID& right ) const noexcept {

      return this->hash() < right.hash();
    }

    /**
     *  @brief operator==()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator==( const FundamentalParticleID& right ) const noexcept {

      return this->hash() == right.hash();
    }

    /**
     *  @brief operator!=()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator!=( const FundamentalParticleID& right ) const noexcept {

      return  this->hash() != right.hash();
    }
  };
} // elementary namespace
} // njoy namespace

#endif
