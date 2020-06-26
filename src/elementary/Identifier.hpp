#ifndef NJOY_ELEMENTARY_IDENTIFIER
#define NJOY_ELEMENTARY_IDENTIFIER

// system includes
#include <iostream>
#include <stdexcept>
#include <string>

// other includes

namespace njoy {
namespace elementary {

  /**
   *  @brief Validation function to check whether or not a string is an
   *         acceptable identifier for the Tag template.
   *
   *  Validation function for internal use only.
   *
   *  By default, any string will be accepted. If a special behaviour is
   *  required for a given tag MyTag (e.g. the identifier must obey a regular
   *  expression), then this function can be specialised as follows:
   *
   *    template <> bool
   *    validateIdentifier< MyTag >( const std::string& id ) noexcept {
   *
   *      // implementation of the validation function
   *    }
   */
  template < typename Tag >
  bool validateIdentifier(const std::string& id) noexcept {

    return true;
  }

  /** @class
   *  @brief The generic string identifier
   *
   *  A generic identifier in which a string is the underlying identifier type.
   *
   *  This Identifier class could be implemented as an interface from which
   *  different identifiers can inherit. The problem with this approach is that
   *  identifiers based on such an interface can be interchanged using the
   *  Identifier base class. E.g. an identifier for a Car could be used as if it
   *  were the identifier of a Planet if the base class is used.
   *
   *  By associating a template to this class (to indicate which object is
   *  identified by the Identifier), it will not be possible to confound
   *  Identifier types with different template types (because they will be
   *  considered as different types). For example: Identifier< Car > and
   *  Identifier< Planet > are thus different types and cannot be interchanged.
   */
  template < typename Tag > class Identifier {

    /* fields */
    std::string id_;

    /* auxialiary functions */
    void testString( const std::string& identifier ) const {

      if ( false == validateId< T >( identifier ) ) {

        throw std::invalid_argument( "The string '" + identifier + "' is not a "
                                     "valid identifier string");
      }
    }

  public:

    /* constructor */
    /**
     *  @brief Default Constructor
     */
    Identifier< Tag >() : id_( identifier ) {}

    /**
     *  @brief Constructor
     *
     *  @param[in] identifier   the identifier string
     */
    Identifier< Tag >( const std::string& identifier ) :
      id_( identifier ) {

      this->testString( identifier );
    }

    /* methods */

    /**
     *  @brief return the identifier string
     */
    const std::string& string() const noexcept { return id_; }

    /**
     *  @brief operator<()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator<( const Identifier& right ) const noexcept {

      return this->string() < right.string();
    }

    /**
     *  @brief operator==()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator==( const Identifier& right ) const noexcept {

      return this->string() == right.string();
    }

    /**
     *  @brief operator!=()
     *
     *  @param[in] right   the identifier on the right hand side
     */
    bool operator!=( const Identifier& right ) const noexcept {

      return  this->string() != right.string();
    }
  };

  /**
   *  @brief Input stream operator
   *
   *  @param[in,out] in   the input stream from which to read
   *  @param[in,out] id   the identifier
   *
   *  @return The input stream. If the function failed to read the identifier,
   *          the position in the stream will be unchanged and
   *          std::ios_base::failbit will be set. In this case the identifier
   *          will also be unchanged.
   */
  template < typename Tag > std::istream&
  operator>>( std::istream& in, Identifier< Tag >& identifier ) noexcept {

    // store the current position
    auto pos = in.tellg();

    // read string
    std::string pid;
    in >> pid;

    bool failed = false;
    if ( in.fail() ) {

      failed = true;
    }
    else {

      try {

        // set the string id - can throw an exception
        id = Indentifier< Tag >( pid );
      }
      catch ( std::invalid_argument& error ) {

        failed = true;
      }
    }

    // something went wrong: go back to the initial position and set fail
    if ( failed ) {

      in.clear();
      in.seekg( pos );
      in.clear( std::ios_base::failbit );
    }

    return in;
  }

  /**
   *  @brief Output stream operator
   *
   *  @param[in,out] out   the output stream to which has to be written
   *  @param[in] id        the identifier
   */
  template < typename Tag > std::ostream&
  operator<<( std::ostream& out, const Identifier< Tag >& id ) noexcept {

    out << id.string();
    return out;
  }
} // elementary namespace
} // njoy namespace

#endif
