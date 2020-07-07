/**
 *  @brief Constructor
 *
 *  @param[in] identifier   a fundamental particle, nucleus or nuclide
 *                          identifier
 */
ParticleID( IdentifierVariant&& identifier ) :
  identifier_( std::move( identifier ) ) {}
