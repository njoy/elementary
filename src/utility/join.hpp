#ifndef NJOY_UTILITY_JOIN
#define NJOY_UTILITY_JOIN

// system includes
#include <numeric>
#include <string>

// other includes

namespace njoy {
namespace utility {

  /**
   *  @brief Join a list of string to a single string using a given separator
   *
   *  @param[in] strings     the strings to be joined together
   *  @param[in] separator   the separator to be used
   */
  std::string join( const std::vector< std::string >& strings,
                    const std::string& separator ) {

    if ( not strings.size() ) {

      return "";
    }

    auto iter = strings.begin();
    auto end = strings.end();
    std::string start = *iter++;
    return std::accumulate( iter, end, start,
                            [&] ( auto&& result, const auto& append )
                                { result += separator;
                                  result += append;
                                  return std::move( result ); } );
  }

  /**
   *  @brief Join a list of string to a single string (no separator)
   *
   *  @param[in] strings     the strings to be joined together
   */
  std::string join( const std::vector< std::string >& strings ) {

    return join( strings, "" );
  }
} // elementary namespace
} // utility namespace

#endif
