/**
 *  @brief Private helper function to generate the id string.
 */
std::string generate( std::vector< std::string >&& strings ) const {

  auto seperator = static_cast< const Derived* >( this )->seperator();
  return std::accumulate( strings.begin(), strings.end(), std::string( "" ),
                          [&] ( auto&& result, const auto& append )
                              { return std::move( result ) +
                                       seperator + append; } );
}
