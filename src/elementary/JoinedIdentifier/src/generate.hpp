/**
 *  @brief Private helper function to generate the id string.
 */
std::string generate( std::vector< std::string >&& strings ) const {

  auto iter = strings.begin();
  auto end = strings.end();
  auto start = iter != strings.end() ? *iter++ : std::string( "" );
  auto separator = Derived::separator();
  return std::accumulate( iter, end, start,
                          [&] ( auto&& result, const auto& append )
                              { return std::move( result ) +
                                       separator + append; } );
}
