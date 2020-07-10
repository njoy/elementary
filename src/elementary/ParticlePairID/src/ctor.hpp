/**
 *  @brief Constructor
 *
 *  @param[in] id1           a particle identifier for the particle
 *  @param[in] id2           a particle identifier for the residual
 */
ParticlePairID( const ParticleID& id1, const ParticleID& id2 ) :
  Identifier( id1.symbol() + "," + id2.symbol(), false ) {}

/**
 *  @brief Constructor
 *
 *  @param[in] string   the identifier string
 */
ParticlePairID( const std::string& string ) : Identifier( string ) {}
