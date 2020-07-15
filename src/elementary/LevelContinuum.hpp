#ifndef NJOY_ELEMENTARY_LEVELCONTINUUM
#define NJOY_ELEMENTARY_LEVELCONTINUUM

// system includes
#include <regex>
#include <stdexcept>
#include <string>

// other includes
#include "elementary/LevelNumber.hpp"

namespace njoy {
namespace elementary {

  /**
   *  @class
   *  @brief The nuclear level continuum
   */
  class LevelContinuum {

    /* regex */
    static const std::regex regex;

    /* fields */
    LevelNumber lower_;
    LevelNumber upper_;

    /* auxiliary functions */
    #include "elementary/LevelContinuum/src/matchContinuum.hpp"
    #include "elementary/LevelContinuum/src/verifyLevels.hpp"

  public:

    /* constructor */
    #include "elementary/LevelContinuum/src/ctor.hpp"

    /* methods */

    /**
     *  @brief return the lower level number
     */
    auto lower() const noexcept {

      return this->lower_;
    }

    /**
     *  @brief return the upper level number
     */
    auto upper() const noexcept {

      return this->upper_;
    }

    /**
     *  @brief return the level symbol
     */
    std::string symbol() const noexcept {

      return this->lower() == this->upper()
               ? "[continuum]"
               : "[continuum:" + this->lower().name() + "-"
                               + this->upper().name() + "]";
    }

    /**
     *  @brief return the level name
     */
    std::string name() const noexcept {

      return this->symbol();
    }
  };

  // register the regex
  #include "elementary/LevelContinuum/src/register.hpp"
} // elementary namespace
} // njoy namespace

#endif
