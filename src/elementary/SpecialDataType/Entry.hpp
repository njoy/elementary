/**
 *  @class
 *  @brief Private helper class to retrieve mt numbers, names and alternatives
 */
class Entry {

  /* fields */
  Number mt_;
  std::string name_;
  std::vector< std::string > alternatives_;

public:

  /* constructor */
  Entry( Number number, std::string&& name,
         std::vector< std::string >&& alternatives ) :
    mt_( number ), name_( std::move( name ) ),
    alternatives_( std::move( alternatives ) ) {}

  /* methods */
  Number number() const { return this->mt_; }
  const std::string& name() const { return this->name_; }
  const std::vector< std::string >& alternatives() const { return this->alternatives_; }
};
