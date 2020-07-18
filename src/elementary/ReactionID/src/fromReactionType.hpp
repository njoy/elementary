static std::string fromReactionType( const ParticleID& incident,
                                     const ParticleID& target,
                                     const ReactionType& type ) {

  // generate the incident pair
  ParticlePairID incidentPair( incident, target );

  // special cases: no particles given
  std::vector< ParticleID > particles = type.particles();
  if ( not particles.size() ) {

    if ( type.name() == "elastic" ) {

      return incidentPair.symbol() + "->" + incidentPair.symbol();
    }
    else {

      return incidentPair.symbol() + "->" + type.name();
    }
  }
  else {

    // produce the residual
    auto isotope = absorb( target, incident );
    for ( const auto& particle : particles ) {

      isotope = emit( isotope, particle );
    }
    ParticleID residual( NuclideID( isotope.za(), type.level() ) );

    // create the outgoing particle tuple
    particles.push_back( residual );
    ParticleTupleID outgoingTuple( particles );

    return incidentPair.symbol() + "->" + outgoingTuple.symbol();
  }
}
