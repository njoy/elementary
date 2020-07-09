/**
 *  @brief Constructor
 *
 *  @param[in] id1           a first particle identifier
 *  @param[in] id2           a second particle identifier
 *  @param[in] identifiers   additional particle identifiers (optional)
 */
 template< typename... IDs,
           typename = std::enable_if_t<
                        std::conjunction_v<
                          std::is_same< ParticleID,
                                        typename std::decay< IDs >::type>... > > >
ParticleTupleID( const ParticleID& id1, const ParticleID& id2,
                 IDs... identifiers ) :
  JoinedIdentifier(
    generate( std::vector< ParticleID >{ id1, id2, identifiers... } ), false ) {}

/**
 *  @brief Constructor
 *
 *  @param[in] identifiers   a vector of particle identifiers
 */
ParticleTupleID( const std::vector< ParticleID >& identifiers ) :
  JoinedIdentifier( generate( identifiers ), false ) {}
