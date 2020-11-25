#ifndef NJOY_ELEMENTARY_NUCLIDEID
#define NJOY_ELEMENTARY_NUCLIDEID

// system includes
#include <regex>
#include <stdexcept>
#include <string>

// other includes
#include "elementary/ElementID.hpp"
#include "elementary/IsotopeID.hpp"
#include "elementary/Level.hpp"

namespace njoy {
namespace elementary {

  /**
   *  @class
   *  @brief The nuclide identifier, with associated name - e.g. Fe56_e0
   *
   *  Aliases like Am242m = Am242_e2 will be handled by a factory function
   *  that uses a static map for aliasing.
   *
   *  Comparison operators are provided using the logical order given by the
   *  element, mass and excited state number. A hash function and override for
   *  std::hash is also provided.
   */
  class NuclideID {

    /* regex */
    static inline const std::regex regex{ "^([A-Z][a-z]?\\d{1,3})"
                                          "((_e(\\d+))|(\\[continuum\\]))?$" };

    /* fields */
    IsotopeID isotope_;
    Level level_;

    /* auxiliary functions */
    #include "elementary/NuclideID/src/matchIdentifier.hpp"

  public:

    /* constructor */
    #include "elementary/NuclideID/src/ctor.hpp"

    /* methods */

    /**
     *  @brief return the isotope identifier
     */
    const IsotopeID& isotope() const noexcept {

      return this->isotope_;
    }

    /**
     *  @brief return the element identifier
     */
    const ElementID& element() const noexcept {

      return this->isotope().element();
    }

    /**
     *  @brief return the mass number
     */
    auto mass() const noexcept { return this->isotope().mass(); }

    /**
     *  @brief return the energy level number
     */
    auto level() const noexcept { return this->level_; }

    /**
     *  @brief return the nuclide symbol
     */
    std::string symbol() const noexcept {

      return this->isotope().name() + this->level().symbol();
    }

    /**
     *  @brief return the nuclide name
     */
    std::string name() const noexcept {

      return this->symbol();
    }

    /**
     *  @brief return the nuclide za value
     */
    int za() const noexcept {

      return this->isotope_.za();
    }

    /**
     *  @brief return the nuclide hash value
     */
    int hash() const noexcept {

      return this->za() * 1000 + this->level_.number();
    }

    /**
     *  @brief operator<()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator<( const NuclideID& right ) const noexcept {

      return this->hash() < right.hash();
    }

    /**
     *  @brief operator==()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator==( const NuclideID& right ) const noexcept {

      return this->hash() == right.hash();
    }

    /**
     *  @brief operator!=()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator!=( const NuclideID& right ) const noexcept {

      return this->hash() != right.hash();
    }
  };
} // elementary namespace
} // njoy namespace

namespace std {

  // std::hash override for the NuclideID class
  template <>
  struct hash< njoy::elementary::NuclideID > {

    size_t operator()( const njoy::elementary::NuclideID& key ) const {

      return key.hash();
    }
  };

} // namespace std

#endif
