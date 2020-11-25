#ifndef NJOY_ELEMENTARY_IDENTIFIER
#define NJOY_ELEMENTARY_IDENTIFIER

// system includes
#include <functional>
#include <stdexcept>
#include <string>

// other includes

namespace njoy {
namespace elementary {

  /** @class
   *  @brief The generic string identifier
   *
   *  A generic identifier in which a string is the underlying identifier type
   *  with an associated hash value, implemented as a CRTP.
   *
   *  Comparison operators are provided using the logical order given by the
   *  string. A hash function is also provided. An override for std::hash
   *  should be provided for each derived identifier separately.
   */
  template < typename Derived > class Identifier {

    /* fields */
    std::string id_;
    std::size_t hash_;

    /* auxialiary functions */
    #include "elementary/Identifier/src/validate.hpp"

  protected:

    /* constructor */
    #include "elementary/Identifier/src/ctor.hpp"

  public:

    /* methods */

    /**
     *  @brief return the identifier string
     */
    const std::string& symbol() const noexcept { return this->id_; }

    /**
     *  @brief return the hash value
     */
    std::size_t hash() const noexcept { return this->hash_; }

    /**
     *  @brief operator<()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator<( const Identifier& right ) const noexcept {

      return this->symbol() < right.symbol();
    }

    /**
     *  @brief operator<()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator<( const std::string& right ) const noexcept {

      return this->symbol() < right;
    }

    /**
     *  @brief operator==()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator==( const Identifier& right ) const noexcept {

      return this->symbol() == right.symbol();
    }

    /**
     *  @brief operator==()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator==( const std::string& right ) const noexcept {

      return this->symbol() == right;
    }

    /**
     *  @brief operator!=()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator!=( const Identifier& right ) const noexcept {

      return  this->symbol() != right.symbol();
    }

    /**
     *  @brief operator!=()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator!=( const std::string& right ) const noexcept {

      return  this->symbol() != right;
    }
  };
} // elementary namespace
} // njoy namespace

#endif
