//! @todo pybind11 variant needs default constructor workaround
#ifdef PYBIND11
/**
 *  @brief Default constructor - only enabled for pybind11
 */
SpecialDataID() = default;
#endif

/**
 *  @brief Constructor
 *
 *  @param[in] incident    the incident particle
 *  @param[in] target      the target
 *  @param[in] type        the special data type
 */
SpecialDataID( const ParticleID& incident, const ParticleID& target,
               const SpecialDataType& type ) :
  Identifier( ParticlePairID( incident, target ).symbol() + "->" + type.symbol(),
              false ) {}

/**
 *  @brief Constructor
 *
 *  @param[in] string   the identifier string
 */
SpecialDataID( const std::string& string ) : Identifier( string ) {}
