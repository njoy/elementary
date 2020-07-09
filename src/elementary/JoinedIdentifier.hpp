#ifndef NJOY_ELEMENTARY_JOINEDIDENTIFIER
#define NJOY_ELEMENTARY_JOINEDIDENTIFIER

// system includes
#include <numeric>
#include <string>

// other includes
#include "elementary/Identifier.hpp"

namespace njoy {
namespace elementary {

  /** @class
   *  @brief The generic string identifier constructed from multiple strings
   */
  template < typename Derived >
  class JoinedIdentifier : public Identifier< Derived > {

    /* fields */

    /* auxialiary functions */
    #include "elementary/JoinedIdentifier/src/generate.hpp"

  protected:

    /* constructor */
    #include "elementary/JoinedIdentifier/src/ctor.hpp"

  public:

    /* methods */
    using Identifier< Derived >::symbol;
    using Identifier< Derived >::operator<;
    using Identifier< Derived >::operator==;
    using Identifier< Derived >::operator!=;
  };
} // elementary namespace
} // njoy namespace

#endif
