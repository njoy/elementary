#ifndef NJOY_ELEMENTARY_SPECIALDATATYPE
#define NJOY_ELEMENTARY_SPECIALDATATYPE

// system includes
#include <stdexcept>
#include <string>

// other includes
#include "utility/tolower.hpp"
#include "elementary/Identifier.hpp"

namespace njoy {
namespace elementary {

  /**
   *  @class
   *  @brief A predefined special data type, with associated information such
   *         as a symbol, aliases or optional ENDF reaction numbers
   *
   *  This SpecialDataType is used for special data that cannot be considered
   *  reactions, like nubar, total particle production cross sections, etc.
   *  Reactions have their own predefined ReactionType
   */
  class SpecialDataType : public Identifier< SpecialDataType > {

    friend Identifier< SpecialDataType >;

    /* type aliases */
    using Name = std::string;
    using Number = unsigned short;

    /* helper class */
    #include "elementary/SpecialDataType/Entry.hpp"

    /* static fields */
    #include "elementary/SpecialDataType/src/register.hpp"

    /* fields */

    /* auxiliary functions */
    static std::string name() { return "a special data type"; }
    #include "elementary/SpecialDataType/src/lookup.hpp"

  public:

    /* constructor */
    #include "elementary/SpecialDataType/src/ctor.hpp"

    /* methods */

    /**
     *  @brief Verify if a given string is registered as a special data type
     *
     *  @param[in] string   the name or alternative name of the data type
     *                      (case insensitive)
     */
    static bool isRegistered( const std::string& string ) {

      return SpecialDataType::name_conversion_dictionary.find(
                 utility::tolower( string ) )
             != SpecialDataType::name_conversion_dictionary.end();
    }

    /**
     *  @brief Verify if a given string is registered as a special data type
     *
     *  @param[in] number   the mt number
     */
    static bool isRegistered( int number ) {

      return SpecialDataType::mt_conversion_dictionary.find( number )
             != SpecialDataType::mt_conversion_dictionary.end();
    }

    /**
     *  @brief return the mt number
     */
    auto mt() const noexcept {

      return SpecialDataType::name_dictionary.at( this->symbol() ).number();
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
  struct hash< njoy::elementary::SpecialDataType > {

    size_t operator()( const njoy::elementary::SpecialDataType& key ) const {

      return key.hash();
    }
  };

} // namespace std

#endif
