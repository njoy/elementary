#ifndef NJOY_ELEMENTARY_LEVELNUMBER
#define NJOY_ELEMENTARY_LEVELNUMBER

// system includes
#include <regex>
#include <stdexcept>
#include <string>

// other includes

namespace njoy {
namespace elementary {

  /**
   *  @class
   *  @brief The nuclear level number
   */
  class LevelNumber {

    /* type aliases */
    using Number = unsigned char;

    /* regex */
    static const std::regex regex;

    /* fields */
    Number level_;

    /* auxiliary functions */
    #include "elementary/LevelNumber/src/verifyLevel.hpp"
    #include "elementary/LevelNumber/src/matchLevel.hpp"

  public:

    /* constructor */
    #include "elementary/LevelNumber/src/ctor.hpp"

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

      return this->number() ? "_e" + std::to_string( this->number() ) : "";
    }

    /**
     *  @brief return the level name
     */
    std::string name() const noexcept {

      return "e" + std::to_string( this->number() );
    }

    /**
     *  @brief operator<()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator<( const LevelNumber& right ) const noexcept {

      return this->number() < right.number();
    }

    /**
     *  @brief operator==()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator==( const LevelNumber& right ) const noexcept {

      return this->number() == right.number();
    }

    /**
     *  @brief operator!=()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator!=( const LevelNumber& right ) const noexcept {

      return  this->number() != right.number();
    }
  };
} // elementary namespace
} // njoy namespace

#endif
