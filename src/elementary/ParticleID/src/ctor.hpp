//! @todo pybind11 variant needs default constructor workaround
#ifdef PYBIND11
/**
 *  @brief Default constructor - only enabled for pybind11
 */
ParticleID() = default;
#endif

/**
 *  @brief Constructor
 *
 *  @param[in] identifier   a fundamental particle, nucleus or nuclide
 *                          identifier
 */
ParticleID( IdentifierVariant&& identifier ) :
  identifier_( std::move( identifier ) ) {}

/**
 *  @brief Constructor
 *
 *  This function throws an invalid_argument exception if invalid data is
 *  used.
 *
 *  @param[in] string   the string representation of the particle
 */
ParticleID( const std::string& string ) :
  identifier_( matchIdentifier( string ) ) {}
