#ifndef NJOY_ELEMENTARY_SPECIALDATATYPE
#define NJOY_ELEMENTARY_SPECIALDATATYPE

// system includes
#include <stdexcept>
#include <string>

// other includes
#include "elementary/src/tolower.hpp"

namespace njoy {
namespace elementary {

  /**
   *  @class
   *  @brief A predefined special data type, with associated information
   *         (including MT numbers)
   *
   *  This SpecialDataType is used for special data that cannot be considered
   *  reactions, like nubar, total particle production cross sections, etc.
   *  Reactions have their own predefined ReactionType
   */
  class SpecialDataType {

    /* type aliases */
    using Name = std::string;
    using Number = unsigned short;

    /* helper class */
    #include "elementary/SpecialDataType/Entry.hpp"

    /* static fields */
    #include "elementary/SpecialDataType/src/register.hpp"

    /* fields */
    Name name_;

    /* auxiliary functions */
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

      return SpecialDataType::name_conversion_dictionary.find( tolower( string ) )
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
     *  @brief return the special data type name
     */
    const Name& name() const noexcept {

      return this->name_;
    }

    /**
     *  @brief return the mt number
     */
    auto mt() const noexcept {

      return SpecialDataType::name_dictionary.at( this->name() ).number();
    }

    /**
     *  @brief operator<()
     *
     *  @param[in] right   the type on the right hand side
     */
    bool operator<( const SpecialDataType& right ) const noexcept {

      return this->name() < right.name();
    }

    /**
     *  @brief operator==()
     *
     *  @param[in] right   the type on the right hand side
     */
    bool operator==( const SpecialDataType& right ) const noexcept {

      return this->name() == right.name();
    }

    /**
     *  @brief operator!=()
     *
     *  @param[in] right   the type on the right hand side
     */
    bool operator!=( const SpecialDataType& right ) const noexcept {

      return  this->name() != right.name();
    }
  };
} // elementary namespace
} // njoy namespace

#endif
