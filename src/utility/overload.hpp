#ifndef NJOY_UTILITY_OVERLOAD
#define NJOY_UTILITY_OVERLOAD

// system includes

// other includes

namespace njoy {
namespace utility {

  template < class... Types > struct overload : Types... {

    using Types::operator()...;
  };
  template < class... Types > overload( Types... ) -> overload< Types... >;

} // elementary namespace
} // utility namespace

#endif
