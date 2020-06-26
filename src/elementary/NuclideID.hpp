#ifndef NJOY_ELEMENTARY_NUCLIDEID
#define NJOY_ELEMENTARY_NUCLIDEID

// system includes
#include <stdexcept>
#include <string>

// other includes
#include "elementary/src/ElementID.hpp"

namespace njoy {
namespace elementary {

  /**
   *  @class
   *  @brief The nuclide identifier, with associated name
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
    #include "elementary/ElementID/src/verifyMass.hpp"
    #include "elementary/ElementID/src/verifyLevel.hpp"

  public:

    /* constructor */

    /**
     *  @brief Constructor
     *
     *  This function throws an invalid_argument exception if invalid data is
     *  used.
     *
     *  @param[in] number   the element number
     */
    NuclideID( int z, int a, int l ) :
      element_( z ), mass_( verifyMass( a ) ), level_( verifyLevel( l ) ) {}

    /* methods */

    /**
     *  @brief return the element identifier
     */
    auto element() const noexcept { return this->element_; }

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

      return ( this->element() < right.element() ) and
             ( this->mass() < right.mass() ) and
             ( this->level() < right.level() );
    }

    /**
     *  @brief operator==()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator==( const NuclideID& right ) const noexcept {

      return ( this->element() == right.element() ) and
             ( this->mass() == right.mass() ) and
             ( this->level() == right.level() );
    }

    /**
     *  @brief operator!=()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator!=( const NuclideID& right ) const noexcept {

      return ( this->element() != right.element() ) and
             ( this->mass() != right.mass() ) and
             ( this->level() != right.level() );
    }
  };
} // elementary namespace
} // njoy namespace

#endif
