/**
 *  @brief Constructor
 *
 *  @param[in] incident    the incident particle
 *  @param[in] target      the target
 *  @param[in] type        the reaction type
 */
ReactionID( const ParticleID& incident, const ParticleID& target,
            const ReactionType& type ) :
  Identifier( fromReactionType( incident, target, type ), false ) {}

/**
 *  @brief Constructor
 *
 *  @param[in] in     the incoming particle pair
 *  @param[in] out    the outgoing particle pair
 */
ReactionID( const ParticlePairID& in, const ParticlePairID& out ) :
  Identifier( in.symbol() + "->" + out.symbol(), false ) {}

/**
 *  @brief Constructor
 *
 *  @param[in] in     the incoming particle pair
 *  @param[in] out    the outgoing particle tuple
 */
ReactionID( const ParticlePairID& in, const ParticleTupleID& out ) :
  Identifier( in.symbol() + "->" + out.symbol(), false ) {}

/**
 *  @brief Constructor
 *
 *  @param[in] string   the identifier string
 */
ReactionID( const std::string& string ) : Identifier( string ) {}
