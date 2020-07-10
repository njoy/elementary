/**
 *  @brief Constructor
 *
 *  @param[in] id1           a first particle identifier
 *  @param[in] id2           a second particle identifier
 */
ParticlePairID( const ParticleID& id1, const ParticleID& id2 ) :
  ParticleTupleID( id1, id2 ) {}

/**
 *  @brief Constructor
 *
 *  @param[in] string   the identifier string
 */
ParticlePairID( const std::string& string ) :
  ParticleTupleID( string ) {}
