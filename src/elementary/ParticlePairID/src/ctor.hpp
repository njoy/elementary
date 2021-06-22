//! @todo pybind11 variant needs default constructor workaround
#ifdef PYBIND11
/**
 *  @brief Default constructor - only enabled for pybind11
 */
ParticlePairID() = default;
#endif

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
 *  @param[in] validate     the optional flag to switch off validation
 */
ParticlePairID( const std::string& string, bool validate = true ) :
  Identifier( string, validate ) {}
