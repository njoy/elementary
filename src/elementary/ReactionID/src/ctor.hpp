/**
 *  @brief Constructor
 *
 *  @param[in] id1           the incoming particle pair
 *  @param[in] id2           the outgoing particles
 */
ReactionID( const ParticleID& incident, const ParticleID& target,
            const ReactionType& type ) :
  Identifier( fromReactionType( incident, target, type ), false ) {}

/**
 *  @brief Constructor
 *
 *  @param[in] id1           the incoming particle pair
 *  @param[in] id2           the outgoing particles
 */
ReactionID( const ParticlePairID& in, const ParticlePairID& out ) :
  Identifier( in.symbol() + "->" + out.symbol(), false ) {}

/**
 *  @brief Constructor
 *
 *  @param[in] id1           the incoming particle pair
 *  @param[in] id2           the outgoing particles
 */
ReactionID( const ParticlePairID& in, const ParticleTupleID& out ) :
  Identifier( in.symbol() + "->" + out.symbol(), false ) {}

/**
 *  @brief Constructor
 *
 *  @param[in] string   the identifier string
 */
ReactionID( const std::string& string ) : Identifier( string ) {}
