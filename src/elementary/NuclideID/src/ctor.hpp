protected:

/**
 *  @brief Private constructor
 */
NuclideID( IsotopeID&& isotope, int l ) :
  isotope_( std::move( isotope ) ), level_( verifyLevel( l ) ) {}

private:

/**
 *  @brief Private constructor
 */
NuclideID( const std::pair< std::string, int >&& pair ) :
  NuclideID( IsotopeID( pair.first ), pair.second ) {}

public:

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
 *  @param[in] string   the string representation of the isotope
 */
NuclideID( const std::string& string ) :
  NuclideID( matchIdentifier( string ) ) {}
