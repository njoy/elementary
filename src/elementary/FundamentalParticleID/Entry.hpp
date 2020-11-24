/**
 *  @class
 *  @brief Private helper class to retrieve symbols, names and alternatives
 */
class Entry {

  /* fields */
  int hash_;
  std::string symbol_;
  std::string name_;
  std::vector< std::string > alternatives_;

public:

  /* constructor */
  Entry( short hash, std::string&& symbol, std::string&& name,
         std::vector< std::string >&& alternatives ) :
    hash_( hash ), symbol_( std::move( symbol ) ), name_( std::move( name ) ),
    alternatives_( std::move( alternatives ) ) {}

  /* methods */
  auto hash() const { return this->hash_; }
  const std::string& symbol() const { return this->symbol_; }
  const std::string& name() const { return this->name_; }
  const std::vector< std::string >& alternatives() const { return this->alternatives_; }
};
