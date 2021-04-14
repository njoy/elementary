#ifndef NJOY_ELEMENTARY_REACTIONTYPE
#define NJOY_ELEMENTARY_REACTIONTYPE

// system includes
#include <stdexcept>
#include <string>

// other includes
#include "utility/tolower.hpp"
#include "elementary/Identifier.hpp"
#include "elementary/ParticleID.hpp"

namespace njoy {
namespace elementary {

  /**
   *  @class
   *  @brief A predefined reaction type, with associated information such as a
   *         symbol, aliases or optional ENDF reaction numbers
   *
   *  This ReactionType is used for actual reactions (including summation
   *  reactions). Special data types like nubar, etc. are not considered
   *  reactions and have their own predefined DataType.
   */
  class ReactionType : public Identifier< ReactionType > {

    friend Identifier< ReactionType >;

    /* type aliases */
    using Name = std::string;
    using Number = unsigned short;
    using LevelNumber = unsigned char;

    /* helper class */
    #include "elementary/ReactionType/Entry.hpp"

    /* static fields */
    #include "elementary/ReactionType/src/register.hpp"

    /* fields */

    /* auxiliary functions */
    static std::string name() { return "a reaction type"; }
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

      return ReactionType::name_conversion_dictionary.find(
                 utility::tolower( string ) )
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
     *  @brief return the mt number
     */
    auto mt() const noexcept {

      return ReactionType::name_dictionary.at( this->symbol() ).number();
    }

    /**
     *  @brief return the outgoing particles
     */
    const std::vector< ParticleID >& particles() const noexcept {

      return ReactionType::name_dictionary.at( this->symbol() ).particles();
    }

    /**
     *  @brief return the excited level number of the outgoing residual
     */
    auto level() const noexcept {

      return ReactionType::name_dictionary.at( this->symbol() ).level();
    }

    /**
     *  @brief return whether or not the reaction is a special reaction
     *         (i.e. a reaction for which no outgoing particles are registered,
     *         except for elastic)
     */
    bool isSpecial() const noexcept {

      if ( this->symbol() == "elastic" ) {

        return false;
      }
      return this->particles().size() == 0;
    }

    /**
     *  @brief Verify if a string is a valid ReactionID
     *
     *  @param[in] string   the string to be validated
     */
    static bool validate( const std::string& string ) {

      return isRegistered( string );
    }

    using Identifier::hash;
    using Identifier::symbol;
    using Identifier::operator<;
    using Identifier::operator<=;
    using Identifier::operator>;
    using Identifier::operator>=;
    using Identifier::operator==;
    using Identifier::operator!=;
  };
} // elementary namespace
} // njoy namespace

namespace std {

  // std::hash override for the ReactionID class
  template <>
  struct hash< njoy::elementary::ReactionType > {

    size_t operator()( const njoy::elementary::ReactionType& key ) const {

      return key.hash();
    }
  };

} // namespace std

#endif
