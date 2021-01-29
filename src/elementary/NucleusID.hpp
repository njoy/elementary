#ifndef NJOY_ELEMENTARY_NUCLEUSID
#define NJOY_ELEMENTARY_NUCLEUSID

// system includes
#include <regex>
#include <stdexcept>
#include <string>

// other includes
#include "utility/tolower.hpp"
#include "elementary/NuclideID.hpp"

namespace njoy {
namespace elementary {

  /**
   *  @class
   *  @brief The nucleus identifier, with associated name - e.g. fe56_e0.
   *
   *  This identifier is the same as the nuclide identifier, except that the
   *  name is complete lower case.
   *
   *  Comparison operators are provided using the logical order given by the
   *  element, mass and excited state number. A hash function and override for
   *  std::hash is also provided.
   */
  class NucleusID : protected NuclideID {

    /* regex */
    static inline const std::regex regex{ "^([a-z]{1,2}?\\d{1,3})"
                                          "((_e(\\d+))|(\\[continuum\\]))?$" };

    /* auxiliary functions */
    #include "elementary/NucleusID/src/matchIdentifier.hpp"

  public:

    /* constructor */
    #include "elementary/NucleusID/src/ctor.hpp"

    /* methods */

    /**
     *  @brief return the isotope identifier
     */
    const IsotopeID& isotope() const noexcept { return NuclideID::isotope(); }

    /**
     *  @brief return the element identifier
     */
    const ElementID& element() const noexcept { return NuclideID::element(); }

    /**
     *  @brief return the mass number
     */
    auto mass() const noexcept { return NuclideID::mass(); }

    /**
     *  @brief return the energy level number
     */
    auto level() const noexcept { return NuclideID::level(); }

    /**
     *  @brief return the nucleus symbol
     */
    std::string symbol() const noexcept {

      return utility::tolower( NuclideID::symbol() );
    }

    /**
     *  @brief return the nucleus name
     */
    std::string name() const noexcept {

      return this->symbol();
    }

    /**
     *  @brief return the nuclide za value
     */
    int za() const noexcept { return NuclideID::za(); }

    /**
     *  @brief return the nuclide hash value
     */
    int hash() const noexcept { return NuclideID::hash(); }

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

namespace std {

  // std::hash override for the NucleusID class
  template <>
  struct hash< njoy::elementary::NucleusID > {

    size_t operator()( const njoy::elementary::NucleusID& key ) const {

      return key.hash();
    }
  };

} // namespace std

#endif
