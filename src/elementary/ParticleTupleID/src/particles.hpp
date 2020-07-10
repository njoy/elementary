/**
 *  @brief Return the particle identifiers for the particles in the tuple
 *         (this excludes the residual)
 */
 std::vector< ParticleID > particles() const noexcept {

  std::vector< ParticleID > particles;

  auto strings = split( this->symbol(), "," );
  auto begin = strings.begin();
  auto end = strings.end();
  std::transform( begin, --end, std::back_inserter( particles ),
                  [] ( const auto& id ) { return ParticleID( id ); } );

  return particles;
}
