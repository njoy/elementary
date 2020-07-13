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
  Identifier( generate( std::vector< ParticleID >{ id1, id2,
                                                   identifiers... } ), false ) {}

/**
 *  @brief Constructor
 *
 *  @param[in] identifiers   a vector of particle identifiers
 */
ParticleTupleID( const std::vector< ParticleID >& identifiers ) :
  Identifier( generate( identifiers ), false ) {}

/**
 *  @brief Constructor
 *
 *  @param[in] string   the identifier string
 *  @param[in] validate     the optional flag to switch off validation
 */
ParticleTupleID( const std::string& string, bool validate = true ) :
  Identifier( string, validate ) {}

/**
 *  @brief Constructor
 *
 *  @param[in] pair   a particle pair identifier
 */
ParticleTupleID( const ParticlePairID& identifier ) :
  Identifier( identifier.symbol(), false ) {}
