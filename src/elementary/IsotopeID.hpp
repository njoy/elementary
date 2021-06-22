#ifndef NJOY_ELEMENTARY_ISOTOPEID
#define NJOY_ELEMENTARY_ISOTOPEID

// system includes
#include <regex>
#include <stdexcept>
#include <string>

// other includes
#include "elementary/ElementID.hpp"

namespace njoy {
namespace elementary {

  /**
   *  @class
   *  @brief The isotope identifier, with associated name - e.g. Fe56 or Fe
   *
   *  Comparison operators are provided using the logical order given by the
   *  element and mass number. A hash function and override for std::hash is
   *  also provided.
   */
  class IsotopeID {

    /* type aliases */
    using MassNumber = unsigned short;

    /* regex */
    static inline const std::regex regex{ "([A-Za-z]{1,2})(\\d{1,3})?" };

    /* fields */
    ElementID element_;
    MassNumber mass_;

    /* auxiliary functions */
    #include "elementary/IsotopeID/src/verifyMass.hpp"
    #include "elementary/IsotopeID/src/matchIdentifier.hpp"

  public:

    /* constructor */
    #include "elementary/IsotopeID/src/ctor.hpp"

    /* methods */

    /**
     *  @brief return the element identifier
     */
    const ElementID& element() const noexcept { return this->element_; }

    /**
     *  @brief return the mass number
     */
    auto mass() const noexcept { return this->mass_; }

    /**
     *  @brief return the isotope symbol, e.g. Fe56 for the isotope or Fe0 for
     *         the elemental isotope
     */
    std::string symbol() const noexcept {

      return this->element().symbol() + std::to_string( this->mass() );
    }

    /**
     *  @brief return the isotope name, e.g. Fe56 for the isotope or Fe0 for the
     *         elemental isotope
     */
    std::string name() const noexcept {

      return this->symbol();
    }

    /**
     *  @brief Return the za value associated to the isotope
     */
    int za() const noexcept {

      return this->element_.number() * 1000 + this->mass_;
    }

    /**
     *  @brief Return the hash value associated to the isotope
     */
    auto hash() const noexcept {

      return this->za();
    }

    /**
     *  @brief operator<()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator<( const IsotopeID& right ) const noexcept {

      return this->za() < right.za();
    }

    /**
     *  @brief operator<=()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator<=( const IsotopeID& right ) const noexcept {

      return this->za() <= right.za();
    }

    /**
     *  @brief operator>()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator>( const IsotopeID& right ) const noexcept {

      return this->za() > right.za();
    }

    /**
     *  @brief operator>=()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator>=( const IsotopeID& right ) const noexcept {

      return this->za() >= right.za();
    }

    /**
     *  @brief operator==()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator==( const IsotopeID& right ) const noexcept {

      return this->za() == right.za();
    }

    /**
     *  @brief operator!=()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator!=( const IsotopeID& right ) const noexcept {

      return this->za() != right.za();
    }
  };
} // elementary namespace
} // njoy namespace

namespace std {

  // std::hash override for the ElementID class
  template <>
  struct hash< njoy::elementary::IsotopeID > {

    size_t operator()( const njoy::elementary::IsotopeID& key ) const {

      return key.hash();
    }
  };

} // namespace std

#endif
