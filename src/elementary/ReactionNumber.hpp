#ifndef NJOY_ELEMENTARY_REACTIONNUMBER
#define NJOY_ELEMENTARY_REACTIONNUMBER

// system includes
#include <stdexcept>
#include <string>

// other includes
#include "elementary/src/tolower.hpp"
#include "elementary/ParticleID.hpp"

namespace njoy {
namespace elementary {

  /**
   *  @class
   *  @brief The element identifier, with associated element symbol and name
   */
  class ReactionNumber {

    /* type aliases */
    using Number = unsigned short;
    using LevelNumber = unsigned char;

    /* helper class */
    #include "elementary/ReactionNumber/Entry.hpp"

    /* static fields */
    static const std::map< Number, Entry > mt_dictionary;
    static const std::map< std::string, Number > conversion_dictionary;

    /* fields */
    Number mt_;

    /* auxiliary functions */
    #include "elementary/ReactionNumber/src/lookup.hpp"

  public:

    /* constructor */
    #include "elementary/ReactionNumber/src/ctor.hpp"

    /* methods */

    /**
     *  @brief return the mt number
     */
    auto mt() const noexcept {

      return this->mt_;
    }

    /**
     *  @brief return the element name
     */
    const std::string& name() const noexcept {

      return ReactionNumber::mt_dictionary.at( this->mt() ).name();
    }

    /**
     *  @brief return the outgoing particles
     */
    const std::vector< ParticleID >& particles() const noexcept {

      return ReactionNumber::mt_dictionary.at( this->mt() ).particles();
    }
  };

  // register the element numbers, symbols, names and alternatives
  #include "elementary/ReactionNumber/src/register.hpp"
} // elementary namespace
} // njoy namespace

#endif
