protected:

/**
 *  @brief Private constructor
 */
NuclideID( IsotopeID&& isotope, int l ) :
  isotope_( std::move( isotope ) ), level_( l ) {}

private:

/**
 *  @brief Private constructor
 */
NuclideID( const std::pair< std::string, int >&& pair ) :
  NuclideID( IsotopeID( pair.first ), pair.second ) {}

public:

//! @todo pybind11 variant needs default constructor workaround
#ifdef PYBIND11
/**
 *  @brief Default constructor - only enabled for pybind11
 */
NuclideID() = default;
#endif

/**
 *  @brief Constructor
 *
 *  This function throws an invalid_argument exception if invalid data is
 *  used.
 *
 *  @param[in] z   the element number
 *  @param[in] a   the mass number
 *  @param[in] l   the level number
 */
NuclideID( int z, int a, int l ) : NuclideID( IsotopeID( z, a ), l ) {}

/**
 *  @brief Constructor
 *
 *  This function throws an invalid_argument exception if invalid data is
 *  used.
 *
 *  @param[in] za   the za number
 *  @param[in] l    the level number
 */
NuclideID( int za, int l ) : NuclideID( IsotopeID( za ), l ) {}

/**
 *  @brief Constructor
 *
 *  This function throws an invalid_argument exception if invalid data is
 *  used.
 *
 *  @param[in] string   the string representation of the nuclide
 */
NuclideID( const std::string& string ) :
  NuclideID( matchIdentifier( string ) ) {}
