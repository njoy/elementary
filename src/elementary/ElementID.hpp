#ifndef NJOY_ELEMENTARY_ELEMENTID
#define NJOY_ELEMENTARY_ELEMENTID

// system includes
#include <stdexcept>
#include <string>

// other includes
#include "elementary/src/tolower.hpp"

namespace njoy {
namespace elementary {

  /**
   *  @class
   *  @brief The element identifier, with associated element symbol and name
   */
  class ElementID {

    /* type aliases */
    using Number = unsigned char;

    /* helper class */
    #include "elementary/ElementID/Entry.hpp"

    /* static fields */
    static const std::map< Number, Entry > element_dictionary;
    static const std::map< std::string, Number > conversion_dictionary;

    /* fields */
    Number z_;

    /* auxiliary functions */
    #include "elementary/ElementID/src/lookup.hpp"

  public:

    /* constructor */
    #include "elementary/ElementID/src/ctor.hpp"

    /* methods */

    /**
     *  @brief return the element number
     */
    auto number() const noexcept {

      return this->z_;
    }

    /**
     *  @brief return the element symbol
     */
    const std::string& symbol() const noexcept {

      return ElementID::element_dictionary.at( this->number() ).symbol();
    }

    /**
     *  @brief return the element name
     */
    const std::string& name() const noexcept {

      return ElementID::element_dictionary.at( this->number() ).name();
    }

    /**
     *  @brief operator<()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator<( const ElementID& right ) const noexcept {

      return this->number() < right.number();
    }

    /**
     *  @brief operator==()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator==( const ElementID& right ) const noexcept {

      return this->number() == right.number();
    }

    /**
     *  @brief operator!=()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator!=( const ElementID& right ) const noexcept {

      return  this->number() != right.number();
    }
  };

  // register the element numbers, symbols, names and alternatives
  #include "elementary/ElementID/src/register.hpp"
} // elementary namespace
} // njoy namespace

#endif
