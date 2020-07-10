#ifndef NJOY_ELEMENTARY_JOIN
#define NJOY_ELEMENTARY_JOIN

// system includes
#include <numeric>
#include <string>

// other includes

namespace njoy {
namespace elementary {

  /**
   *  @brief Join a list of string to a single string using a given separator
   *         string
   *
   *  @param[in] strings   the string to be converted to lower case
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
} // elementary namespace
} // njoy namespace

#endif
