#ifndef NJOY_ELEMENTARY_NUCLEUSID
#define NJOY_ELEMENTARY_NUCLEUSID

// system includes
#include <string>

// other includes
#include "elementary/src/tolower.hpp"
#include "elementary/NuclideID.hpp"

namespace njoy {
namespace elementary {

  /**
   *  @class
   *  @brief The nucleus identifier, with associated name - e.g. fe56_e0.
   *
   *  This identifier is the same as the nuclide identifier, except that the
   *  name is complete lower case.
   */
  class NucleusID : protected NuclideID {

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
    NucleusID( int z, int a, int l ) : NuclideID( z, a, l ) {}

    /* methods */

    using NuclideID::isotope;
    using NuclideID::element;
    using NuclideID::mass;
    using NuclideID::level;

    /**
     *  @brief return the nucleus symbol
     */
    std::string symbol() const noexcept {

      return tolower( NuclideID::symbol() );
    }

    /**
     *  @brief return the nucleus name
     */
    std::string name() const noexcept {

      return this->symbol();
    }

    using NuclideID::hash;

    /**
     *  @brief operator<()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator<( const NucleusID& right ) const noexcept {

      return this->hash() < right.hash();
    }

    /**
     *  @brief operator==()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator==( const NucleusID& right ) const noexcept {

      return this->hash() == right.hash();
    }

    /**
     *  @brief operator!=()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator!=( const NucleusID& right ) const noexcept {

      return this->hash() != right.hash();
    }
  };
} // elementary namespace
} // njoy namespace

#endif
