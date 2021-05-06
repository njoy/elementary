//! @todo this could be initialised using a json property file

// register the mt numbers, names, etc.
static inline const std::map< Name, Entry >
name_dictionary{

  [] () {

    std::vector< Entry > data = {
      Entry{ 151, "resonances", { "n,res" } },
      Entry{ 201, "xn", { "z,xn", "n,xn" } },
      Entry{ 202, "xg", { "z,xg", "n,xg" } },
      Entry{ 203, "xp", { "z,xp", "n,xp" } },
      Entry{ 204, "xd", { "z,xd", "n,xd" } },
      Entry{ 205, "xt", { "z,xt", "n,xt" } },
      Entry{ 206, "xh", { "z,xh", "z,x3he", "z,xhe3",
                          "n,xh", "n,x3he", "n,xhe3" } },
      Entry{ 207, "xa", { "z,xa", "n,xa" } },
      Entry{ 208, "xpi+", { "z,xpi+", "n,xpi+" } },
      Entry{ 209, "xpi0", { "z,pi0", "n,pi0" } },
      Entry{ 210, "xpi-", { "z,xpi-", "n,xpi-" } },
      Entry{ 211, "xmu+", { "z,xmu+", "n,xmu+" } },
      Entry{ 212, "xmu-", { "z,xmu-", "n,xmu-" } },
      Entry{ 213, "xk+", { "z,xk+", "n,xk+" } },
      Entry{ 214, "xk0long", { "z,xk0long", "n,xk0long" } },
      Entry{ 215, "xk0short", { "z,xk0short", "n,xk0short" } },
      Entry{ 216, "xk-", { "z,xk-", "n,xk-" } },
      Entry{ 217, "xp-", { "z,xp-", "n,xp-" } },
      Entry{ 218, "xn-", { "z,xn-", "n,xn-" } },
      Entry{ 251, "mubar", {} },
      Entry{ 451, "heading", {} },
      Entry{ 452, "nubar,total", {} },
      Entry{ 454, "ify", {} },
      Entry{ 455, "nubar,delayed", {} },
      Entry{ 456, "nubar,prompt", {} },
      Entry{ 457, "decay", {} },
      Entry{ 458, "qfission", {} },
      Entry{ 459, "cfy", {} },
      Entry{ 460, "photons,delayed", {} } };

      //! @todo determine which ones are reactions, which ones are special data
      //! @todo add mt 252 (xi), 253 (gamma), 301-450 (kerma), 500-502, 504-506
      //! @todo add mt 515-517, 522-523, 526-528, 533-572

    std::map< Name, Entry > map;
    for ( auto&& entry : data ) {

      map.insert( { entry.name(), std::move( entry ) } );
    }
    return map;
  }()
};

// register the alternatives (stored in lower case)
static inline const std::map< std::string, Name >
name_conversion_dictionary = [] ( const auto& dictionary ) {

  std::map< std::string, Name > conversion;
  for ( const auto& [ name, entry ] : dictionary ) {

    conversion[ utility::tolower( entry.name() ) ] = name;
    for ( const auto& alternative : entry.alternatives() ) {

      conversion[ utility::tolower( alternative ) ] = name;
    }
  }
  return conversion;
}( name_dictionary );

// register the mt numbers
static inline const std::map< Number, Name >
mt_conversion_dictionary = [] ( const auto& dictionary ) {

  std::map< Number, Name > conversion;
  for ( const auto& [ name, entry ] : dictionary ) {

    auto mt = entry.number();
    if ( mt ) {

      conversion[ mt ] = name;
    }
  }
  return conversion;
}( name_dictionary );
