#ifndef NJOY_ELEMENTARY_TOLOWER
#define NJOY_ELEMENTARY_TOLOWER

// system includes
#include <algorithm>
#include <cctype>
#include <string>

// other includes

namespace njoy {
namespace elementary {

  /**
   *  @brief Return the lower case version of a string
   *
   *  @todo this can probably be moved elsewhere
   *
   *  @param[in] string   the string to be converted to lower case
   */
  std::string tolower( const std::string& string ) {

    std::string lower;
    std::transform( string.begin(), string.end(), std::back_inserter( lower ),
                    [] ( const auto& c ) { return std::tolower( c ); } );
    return lower;
  }
} // elementary namespace
} // njoy namespace

#endif
