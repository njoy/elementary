#ifndef NJOY_ELEMENTARY_LEVEL
#define NJOY_ELEMENTARY_LEVEL

// system includes
#include <regex>
#include <stdexcept>
#include <string>
#include <limits>

// other includes

namespace njoy {
namespace elementary {

  /**
   *  @class
   *  @brief The nuclear level number
   */
  class Level {

    /* type aliases */
    using Number = unsigned char;

    /* regex */
    static inline const std::regex regex{ "^(_?e(\\d+))|(\\[continuum\\])$" };

    /* fields */
    Number level_;

    /* auxiliary functions */
    #include "elementary/Level/src/verifyLevel.hpp"
    #include "elementary/Level/src/matchLevel.hpp"

  public:

    static constexpr Number continuum = std::numeric_limits< Number >::max();

    /* constructor */
    #include "elementary/Level/src/ctor.hpp"

    /* methods */

    /**
     *  @brief return the level number
     */
    auto number() const noexcept {

      return this->level_;
    }

    /**
     *  @brief return the level symbol
     */
    std::string symbol() const noexcept {

      return this->number() != continuum
               ? this->number()
                   ? "_e" + std::to_string( this->number() )
                   : ""
               : "[continuum]";
    }

    /**
     *  @brief return the level name
     */
    std::string name() const noexcept {

      return this->number() != continuum
               ? "e" + std::to_string( this->number() )
               : "[continuum]";
    }

    /**
     *  @brief Return the hash value associated to the level
     */
    auto hash() const noexcept {

      return this->number();
    }

    /**
     *  @brief operator<()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator<( const Level& right ) const noexcept {

      return this->number() < right.number();
    }

    /**
     *  @brief operator==()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator==( const Level& right ) const noexcept {

      return this->number() == right.number();
    }

    /**
     *  @brief operator!=()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator!=( const Level& right ) const noexcept {

      return  this->number() != right.number();
    }
  };
} // elementary namespace
} // njoy namespace

namespace std {

  // std::hash override for the Level class
  template <>
  struct hash< njoy::elementary::Level > {

    size_t operator()( const njoy::elementary::Level& key ) const {

      return key.hash();
    }
  };

} // namespace std

#endif
