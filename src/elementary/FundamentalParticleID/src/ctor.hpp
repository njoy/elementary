//! @todo pybind11 variant needs default constructor workaround
#ifdef PYBIND11
/**
 *  @brief Default constructor - only enabled for pybind11
 */
FundamentalParticleID() = default;
#endif

/**
 *  @brief String based constructor
 *
 *  This function throws an invalid_argument exception if the string is not
 *  a registered symbol, name or alternative.
 *
 *  @param[in] string   the symbol, name or alternative name of the particle
 *                      (case insensitive)
 */
FundamentalParticleID( const std::string& string ) : hash_( lookup( string ) ) {}
