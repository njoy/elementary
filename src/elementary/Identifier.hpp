#ifndef NJOY_ELEMENTARY_IDENTIFIER
#define NJOY_ELEMENTARY_IDENTIFIER

// system includes
#include <iostream>
#include <stdexcept>
#include <string>

// other includes

namespace njoy {
namespace elementary {

  /** @class
   *  @brief The generic string identifier
   *
   *  A generic identifier in which a string is the underlying identifier type,
   *  implemented as a CRTP.
   */
  template < typename Derived > class Identifier {

    /* fields */
    std::string id_;

    /* auxialiary functions */

  public:

    /* constructor */
    /**
     *  @brief Constructor
     *
     *  @param[in] identifier   the identifier string
     */
    Identifier( const std::string& identifier ) :
      id_( identifier ) {

      if ( not static_cast< const Derived* >( this )->validate( this->id_ ) ) {

        auto name = static_cast< const Derived* >( this )->name();
        throw std::invalid_argument( "The string '" + this->id_ + "' is not a "
                                     "valid identifier string for a " +
                                     name );
      }
    }

    /* methods */

    /**
     *  @brief return the identifier string
     */
    const std::string& symbol() const noexcept { return this->id_; }

    /**
     *  @brief operator<()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator<( const Identifier& right ) const noexcept {

      return this->symbol() < right.symbol();
    }

    /**
     *  @brief operator<()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator<( const std::string& right ) const noexcept {

      return this->symbol() < right;
    }

    /**
     *  @brief operator==()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator==( const Identifier& right ) const noexcept {

      return this->symbol() == right.symbol();
    }

    /**
     *  @brief operator==()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator==( const std::string& right ) const noexcept {

      return this->symbol() == right;
    }

    /**
     *  @brief operator!=()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator!=( const Identifier& right ) const noexcept {

      return  this->symbol() != right.symbol();
    }

    /**
     *  @brief operator!=()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator!=( const std::string& right ) const noexcept {

      return  this->symbol() != right;
    }
  };
} // elementary namespace
} // njoy namespace

#endif
