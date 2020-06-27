#ifndef NJOY_ELEMENTARY_NUCLIDEID
#define NJOY_ELEMENTARY_NUCLIDEID

// system includes
#include <stdexcept>
#include <string>

// other includes
#include "elementary/ElementID.hpp"

namespace njoy {
namespace elementary {

  /**
   *  @class
   *  @brief The nuclide identifier, with associated name - e.g. Fe56_e0
   *
   *  Aliases like Am242m = Am242_e2 will be handled by a factory function
   *  that uses a static map for aliasing.
   */
  class NuclideID {

    /* type aliases */
    using MassNumber = unsigned short;
    using LevelNumber = unsigned char;

    /* fields */
    ElementID element_;
    MassNumber mass_;
    LevelNumber level_;

    /* auxiliary functions */
    #include "elementary/NuclideID/src/verifyMass.hpp"
    #include "elementary/NuclideID/src/verifyLevel.hpp"

    /**
     *  @brief Private helper function used in comparison
     */
    int zal() const noexcept {

      return this->element_.number() * 10000 + this->mass_ * 10 + this->level_;
    }

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
     *  @param[in] l   the level number
     */
    NuclideID( int z, int a, int l ) :
      element_( z ), mass_( verifyMass( a ) ), level_( verifyLevel( l ) ) {}

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
     *  @brief return the energy level
     */
    auto level() const noexcept { return this->level_; }

    /**
     *  @brief return the nuclide name
     */
    std::string name() const noexcept {

      return this->element().symbol()
             + std::to_string( this->mass() )
             + "_e" + std::to_string( this->level() );
    }

    /**
     *  @brief operator<()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator<( const NuclideID& right ) const noexcept {

      return this->zal() < right.zal();
    }

    /**
     *  @brief operator==()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator==( const NuclideID& right ) const noexcept {

      return this->zal() == right.zal();
    }

    /**
     *  @brief operator!=()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator!=( const NuclideID& right ) const noexcept {

      return this->zal() != right.zal();
    }
  };
} // elementary namespace
} // njoy namespace

#endif
