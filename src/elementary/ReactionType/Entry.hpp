/**
 *  @class
 *  @brief Private helper class to retrieve mt numbers, names, alternatives and
 *         particles
 */
class Entry {

  /* fields */
  Number mt_;
  std::string name_;
  std::vector< std::string > alternatives_;
  std::vector< ParticleID > particles_;
  LevelNumber level_ = 0;

public:

  /* constructor */
  Entry( Number number, std::string&& name,
         std::vector< std::string >&& alternatives,
         std::vector< ParticleID >&& particles ) :
    mt_( number ), name_( std::move( name ) ),
    alternatives_( std::move( alternatives ) ),
    particles_( std::move( particles ) ) {}

  Entry( Number number, std::string&& name,
         std::vector< std::string >&& alternatives,
         std::vector< ParticleID >&& particles,
         LevelNumber level ) :
    mt_( number ), name_( std::move( name ) ),
    alternatives_( std::move( alternatives ) ),
    particles_( std::move( particles ) ),
    level_( level ) {}

  /* methods */
  Number number() const { return this->mt_; }
  const std::string& name() const { return this->name_; }
  const std::vector< std::string >& alternatives() const { return this->alternatives_; }
  const std::vector< ParticleID >& particles() const { return this->particles_; }
  LevelNumber level() const { return this->level_; }
};
