#ifndef NJOY_ELEMENTARY_SPLIT
#define NJOY_ELEMENTARY_SPLIT

// system includes
#include <numeric>
#include <string>

// other includes

namespace njoy {
namespace elementary {

  /**
   *  @brief Split a string into a list of strings using a given separator
   *
   *  @param[in] string      the strings to be split
   *  @param[in] separator   the separator to be used
   */
  std::vector< std::string > split( const std::string& string,
                                    const std::string& separator ) {

    std::vector< std::string > strings;

    std::string::size_type position = 0;
    std::string::size_type last = position;
    const auto jump = separator.size();

    while ( ( position = string.find( separator, last ) ) < std::string::npos ) {

      strings.push_back( string.substr( last, position - last ) );
      last = position + jump;
    }
    strings.push_back( string.substr( last, string.size() - last ) );
    return strings;
   }
} // elementary namespace
} // njoy namespace

#endif
