#ifndef NJOY_ELEMENTARY_REACTIONTYPE
#define NJOY_ELEMENTARY_REACTIONTYPE

// system includes
#include <stdexcept>
#include <string>

// other includes
#include "elementary/src/tolower.hpp"
#include "elementary/Level.hpp"
#include "elementary/ParticleID.hpp"

namespace njoy {
namespace elementary {

  /**
   *  @class
   *  @brief The ENDF reaction number, with associated information
   */
  class ReactionType {

    /* type aliases */
    using Name = std::string;
    using Number = unsigned short;
    using LevelNumber = unsigned char;

    /* helper class */
    #include "elementary/ReactionType/Entry.hpp"

    /* static fields */
    static const std::map< Name, Entry > name_dictionary;
    static const std::map< std::string, Name > name_conversion_dictionary;
    static const std::map< Number, Name > mt_conversion_dictionary;

    /* fields */
    Name name_;

    /* auxiliary functions */
    #include "elementary/ReactionType/src/lookup.hpp"

  public:

    /* constructor */
    #include "elementary/ReactionType/src/ctor.hpp"

    /* methods */

    /**
     *  @brief Verify if a given string is registered as a reaction
     *
     *  @param[in] string   the name or alternative name of the reaction
     *                      (case insensitive)
     */
    static bool isRegistered( const std::string& string ) {

      return ReactionType::name_conversion_dictionary.find( tolower( string ) )
             != ReactionType::name_conversion_dictionary.end();
    }

    /**
     *  @brief Verify if a given string is registered as a reaction
     *
     *  @param[in] number   the mt number
     */
    static bool isRegistered( int number ) {

      return ReactionType::mt_conversion_dictionary.find( number )
             != ReactionType::mt_conversion_dictionary.end();
    }

    /**
     *  @brief return the element name
     */
    const Name& name() const noexcept {

      return this->name_;
    }

    /**
     *  @brief return the mt number
     */
    auto mt() const noexcept {

      return ReactionType::name_dictionary.at( this->name() ).number();
    }

    /**
     *  @brief return the outgoing particles
     */
    const std::vector< ParticleID >& particles() const noexcept {

      return ReactionType::name_dictionary.at( this->name() ).particles();
    }

    /**
     *  @brief return the excited level number of the outgoing residual
     */
    auto level() const noexcept {

      return ReactionType::name_dictionary.at( this->name() ).level();
    }

    /**
     *  @brief operator<()
     *
     *  @param[in] right   the type on the right hand side
     */
    bool operator<( const ReactionType& right ) const noexcept {

      return this->name() < right.name();
    }

    /**
     *  @brief operator==()
     *
     *  @param[in] right   the type on the right hand side
     */
    bool operator==( const ReactionType& right ) const noexcept {

      return this->name() == right.name();
    }

    /**
     *  @brief operator!=()
     *
     *  @param[in] right   the type on the right hand side
     */
    bool operator!=( const ReactionType& right ) const noexcept {

      return  this->name() != right.name();
    }
  };

  // register the reaction type names, mt numbers and alternatives
  #include "elementary/ReactionType/src/register.hpp"
} // elementary namespace
} // njoy namespace

#endif
