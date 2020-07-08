private:

/**
 *  @brief Private constructor
 */
NucleusID( const std::pair< std::string, int >&& pair ) :
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
NucleusID( int z, int a, int l ) : NuclideID( z, a, l ) {}

/**
 *  @brief Constructor
 *
 *  This function throws an invalid_argument exception if invalid data is
 *  used.
 *
 *  @param[in] string   the string representation of the nucleus
 */
NucleusID( const std::string& string ) :
  NucleusID( matchIdentifier( string ) ) {}
