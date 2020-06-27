#ifndef NJOY_ELEMENTARY_ISOTOPEID
#define NJOY_ELEMENTARY_ISOTOPEID

// system includes
#include <stdexcept>
#include <string>

// other includes
#include "elementary/ElementID.hpp"

namespace njoy {
namespace elementary {

  /**
   *  @class
   *  @brief The isotope identifier, with associated name - e.g. Fe56 or Fe
   */
  class IsotopeID {

    /* type aliases */
    using MassNumber = unsigned short;

    /* fields */
    ElementID element_;
    MassNumber mass_;

    /* auxiliary functions */
    #include "elementary/IsotopeID/src/verifyMass.hpp"

  public:

    /* constructor */

    /**
     *  @brief Constructor
     *
     *  This function throws an invalid_argument exception if invalid data is
     *  used.
     *
     *  @param[in] z   the element number
     *  @param[in] a   the mass number
     */
    IsotopeID( int z, int a ) : element_( z ), mass_( verifyMass( a ) ) {}

    /**
     *  @brief Constructor
     *
     *  This function throws an invalid_argument exception if invalid data is
     *  used.
     *
     *  @param[in] za   the za number
     */
    IsotopeID( int za ) : IsotopeID( ( za - za%1000 ) / 1000, za%1000 ) {}

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
     *  @brief return the isotope name, e.g. Fe56 for the isotope or Fe for the
     *         elemental isotope
     */
    std::string name() const noexcept {

      return this->element().symbol()
             + ( this->mass() ? std::to_string( this->mass() ) : "" );
    }

    /**
     *  @brief Return the za value associated to the isotope
     */
    int za() const noexcept {

      return this->element_.number() * 1000 + this->mass_ * 10;
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

#endif
