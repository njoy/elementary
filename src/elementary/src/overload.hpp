#ifndef NJOY_ELEMENTARY_OVERLOAD
#define NJOY_ELEMENTARY_OVERLOAD

// system includes

// other includes

namespace njoy {
namespace elementary {

  template < class... Types > struct overload : Types... {

    using Types::operator()...;
  };
  template < class... Types > overload( Types... ) -> overload< Types... >;

} // elementary namespace
} // njoy namespace

#endif
