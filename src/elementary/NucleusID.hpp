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

    /* regex */
    static const std::regex regex;

    /* auxiliary functions */
    #include "elementary/NucleusID/src/matchIdentifier.hpp"

  public:

    /* constructor */
    #include "elementary/NucleusID/src/ctor.hpp"

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

    using NuclideID::za;
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

  // register the regex
  #include "elementary/NucleusID/src/register.hpp"
} // elementary namespace
} // njoy namespace

#endif
