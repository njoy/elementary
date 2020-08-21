static std::string fromReactionType( const ParticleID& incident,
                                     const ParticleID& target,
                                     const ReactionType& type ) {

  // generate the incident pair
  ParticlePairID incidentPair( incident, target );

  // cases: elastic, special and anything else
  if ( type.name() == "capture" ) {

    return incidentPair.symbol() + "->capture";
  }
  else if ( type.name() == "elastic" ) {

    if ( target.level() == 0 ) {

      return incidentPair.symbol() + "->" + incidentPair.symbol();
    }
    else {

      ParticleID residual = target.isNucleus()
                            ? ParticleID( NucleusID( target.za(), 0 ) )
                            : ParticleID( NuclideID( target.za(), 0 ) );
      return incidentPair.symbol() + "->" +
             ParticlePairID( incident, residual ).symbol();
    }
  }
  else if ( type.isSpecial() ) {

    return incidentPair.symbol() + "->" + type.name();
  }
  else {

    // add the residual to the reaction's particles
    std::vector< ParticleID > particles = type.particles();
    particles.push_back( resolve( incident, target, type ) );

    // return the identifier
    return incidentPair.symbol() + "->" + ParticleTupleID( particles ).symbol();
  }
}
