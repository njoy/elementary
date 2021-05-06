#ifndef NJOY_ELEMENTARY_ELEMENTID
#define NJOY_ELEMENTARY_ELEMENTID

// system includes
#include <stdexcept>
#include <string>

// other includes
#include "utility/tolower.hpp"

namespace njoy {
namespace elementary {

  /**
   *  @class
   *  @brief The element identifier, with associated element symbol and name
   *
   *  Comparison operators are provided using the logical order given by the
   *  element number. A hash function and override for std::hash is also
   *  provided.
   */
  class ElementID {

    /* type aliases */
    using Number = unsigned char;

    /* helper class */
    #include "elementary/ElementID/Entry.hpp"

    /* static fields */
    #include "elementary/ElementID/src/register.hpp"

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
     *  @brief return the hash value
     */
    auto hash() const noexcept { return this->number(); }

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
} // elementary namespace
} // njoy namespace

namespace std {

  // std::hash override for the ElementID class
  template <>
  struct hash< njoy::elementary::ElementID > {

    size_t operator()( const njoy::elementary::ElementID& key ) const {

      return key.hash();
    }
  };

} // namespace std

#endif
