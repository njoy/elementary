#ifndef NJOY_ELEMENTARY_FUNDAMENTALPARTICLEID
#define NJOY_ELEMENTARY_FUNDAMENTALPARTICLEID

// system includes
#include <string>

// other includes
#include <map>
#include <unordered_map>
#include "elementary/src/tolower.hpp"

namespace njoy {
namespace elementary {

  /**
   *  @class
   *  @brief The fundamental particle identifier, with associated symbol and
   *         name
   *
   *  Comparison operators are provided using a unique hash for each registered
   *  fundamental particle type. A hash function and override for std::hash is
   *  also provided.
   */
  class FundamentalParticleID {

    /* type aliases */
    using Hash = short;

    /* helper class */
    #include "elementary/FundamentalParticleID/Entry.hpp"

    /* static fields */
    static const std::map< Hash, Entry > particle_dictionary;
    static const std::map< std::string, Hash > conversion_dictionary;

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

  // register the element numbers, symbols, names and alternatives
  #include "elementary/FundamentalParticleID/src/register.hpp"
} // elementary namespace
} // njoy namespace

namespace std {

  // std::hash override for the FundamentalParticleID class
  template <>
  struct hash< njoy::elementary::FundamentalParticleID > {

    size_t operator()( const njoy::elementary::FundamentalParticleID& key ) const {

      return key.hash();
    }
  };

} // namespace std

#endif
