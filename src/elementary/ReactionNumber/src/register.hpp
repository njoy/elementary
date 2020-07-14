//! @todo this could be initialised using a json property file

// register the mt numbers, names, etc.
const std::map< ReactionNumber::Number, ReactionNumber::Entry >
ReactionNumber::mt_dictionary{

  [] () {

    ParticleID n( "n" );
    ParticleID p( "p" );
    ParticleID d( "h2" );
    ParticleID t( "h3" );
    ParticleID h( "he3" );
    ParticleID a( "he4" );

    return
    std::map< ReactionNumber::Number, ReactionNumber::Entry > {
      { 1, ReactionNumber::Entry{ 1, "total", { "n,total" } } },
      { 2, ReactionNumber::Entry{ 2, "elastic", { "z,z0" } } },
      //{ 4, ReactionNumber::Entry{ 4, "inelastic", { "z,n", "n,n'", "z,n'" },
      //                            { n } } },
      { 11, ReactionNumber::Entry{ 11, "z,2nd", { "n,2nd" }, { n, n, d } } },
      { 16, ReactionNumber::Entry{ 16, "z,2n", { "n,2n" }, { n, n } } },
      { 17, ReactionNumber::Entry{ 17, "z,3n", { "n,3n" }, { n, n, n } } },
      //{ 18, ReactionNumber::Entry{ 18, "fission", { "n,fission", "z,fission" } } },
      //{ 19, ReactionNumber::Entry{ 19, "fission1", { "n,f", "z,f" } } },
      //{ 20, ReactionNumber::Entry{ 20, "fission2", { "n,nf", "z,nf" } } },
      //{ 21, ReactionNumber::Entry{ 21, "fission3", { "n,2nf", "z,2nf" } } },
      { 22, ReactionNumber::Entry{ 22, "z,na", { "n,na" }, { n, a } } },
      { 23, ReactionNumber::Entry{ 23, "z,n3a", { "n,n3a" }, { n, a, a, a } } },
      { 24, ReactionNumber::Entry{ 24, "z,2na", { "n,2na" }, { n, n, a } } },
      { 25, ReactionNumber::Entry{ 25, "z,3na", { "n,3na" }, { n, n, n, a } } },
      { 28, ReactionNumber::Entry{ 28, "z,np", { "n,np" }, { n, p } } },
      { 29, ReactionNumber::Entry{ 29, "z,n2a", { "n,n2a" }, { n, a, a } } },
      { 30, ReactionNumber::Entry{ 30, "z,2n2a", { "n,2n2a" }, { n, n, a, a } } },
      { 32, ReactionNumber::Entry{ 32, "z,nd", { "n,nd" }, { n, d } } },
      { 33, ReactionNumber::Entry{ 33, "z,nt", { "n,nt" }, { n, t } } },
      { 34, ReactionNumber::Entry{ 34, "z,nh", { "n,n3he", "n,nh", "n,nhe3", "z,n3he", "z,nhe3" }, { n, h } } },
      { 35, ReactionNumber::Entry{ 35, "z,nd2a", { "n,nd2a" }, { n, d, a, a } } },
      { 36, ReactionNumber::Entry{ 36, "z,nt2a", { "n,nt2a" }, { n, t, a, a } } },
      { 37, ReactionNumber::Entry{ 37, "z,4n", { "n,4n" }, { n, n, n, n } } },
      //{ 38, ReactionNumber::Entry{ 38, "fission4", { "n,3nf" } } },
      { 41, ReactionNumber::Entry{ 41, "z,2np", { "n,2np" }, { n, n, p } } },
      { 42, ReactionNumber::Entry{ 42, "z,3np", { "n,3np" }, { n, n, n, p } } },
      { 44, ReactionNumber::Entry{ 44, "z,n2p", { "n,n2p" }, { n, p, p } } },
      { 45, ReactionNumber::Entry{ 45, "z,npa", { "n,npa" }, { n, p, a } } },
      { 51, ReactionNumber::Entry{ 51, "z,n1", { "n,n'(1)", "n,n1", "z,n'(1)" }, { n }, 1 } },
      { 52, ReactionNumber::Entry{ 52, "z,n2", { "n,n'(2)", "n,n2", "z,n'(2)" }, { n }, 2 } },
      { 53, ReactionNumber::Entry{ 53, "z,n3", { "n,n'(3)", "n,n3", "z,n'(3)" }, { n }, 3 } },
      { 54, ReactionNumber::Entry{ 54, "z,n4", { "n,n'(4)", "n,n4", "z,n'(4)" }, { n }, 4 } },
      { 55, ReactionNumber::Entry{ 55, "z,n5", { "n,n'(5)", "n,n5", "z,n'(5)" }, { n }, 5 } },
      { 56, ReactionNumber::Entry{ 56, "z,n6", { "n,n'(6)", "n,n6", "z,n'(6)" }, { n }, 6 } },
      { 57, ReactionNumber::Entry{ 57, "z,n7", { "n,n'(7)", "n,n7", "z,n'(7)" }, { n }, 7 } },
      { 58, ReactionNumber::Entry{ 58, "z,n8", { "n,n'(8)", "n,n8", "z,n'(8)" }, { n }, 8 } },
      { 59, ReactionNumber::Entry{ 59, "z,n9", { "n,n'(9)", "n,n9", "z,n'(9)" }, { n }, 9 } },
      { 60, ReactionNumber::Entry{ 60, "z,n10", { "n,n'(10)", "n,n10", "z,n'(10)" }, { n }, 10 } },
      { 61, ReactionNumber::Entry{ 61, "z,n11", { "n,n'(11)", "n,n11", "z,n'(11)" }, { n }, 11 } },
      { 62, ReactionNumber::Entry{ 62, "z,n12", { "n,n'(12)", "n,n12", "z,n'(12)" }, { n }, 12 } },
      { 63, ReactionNumber::Entry{ 63, "z,n13", { "n,n'(13)", "n,n13", "z,n'(13)" }, { n }, 13 } },
      { 64, ReactionNumber::Entry{ 64, "z,n14", { "n,n'(14)", "n,n14", "z,n'(14)" }, { n }, 14 } },
      { 65, ReactionNumber::Entry{ 65, "z,n15", { "n,n'(15)", "n,n15", "z,n'(15)" }, { n }, 15 } },
      { 66, ReactionNumber::Entry{ 66, "z,n16", { "n,n'(16)", "n,n16", "z,n'(16)" }, { n }, 16 } },
      { 67, ReactionNumber::Entry{ 67, "z,n17", { "n,n'(17)", "n,n17", "z,n'(17)" }, { n }, 17 } },
      { 68, ReactionNumber::Entry{ 68, "z,n18", { "n,n'(18)", "n,n18", "z,n'(18)" }, { n }, 18 } },
      { 69, ReactionNumber::Entry{ 69, "z,n19", { "n,n'(19)", "n,n19", "z,n'(19)" }, { n }, 19 } },
      { 70, ReactionNumber::Entry{ 70, "z,n20", { "n,n'(20)", "n,n20", "z,n'(20)" }, { n }, 20 } },
      { 71, ReactionNumber::Entry{ 71, "z,n21", { "n,n'(21)", "n,n21", "z,n'(21)" }, { n }, 21 } },
      { 72, ReactionNumber::Entry{ 72, "z,n22", { "n,n'(22)", "n,n22", "z,n'(22)" }, { n }, 22 } },
      { 73, ReactionNumber::Entry{ 73, "z,n23", { "n,n'(23)", "n,n23", "z,n'(23)" }, { n }, 23 } },
      { 74, ReactionNumber::Entry{ 74, "z,n24", { "n,n'(24)", "n,n24", "z,n'(24)" }, { n }, 24 } },
      { 75, ReactionNumber::Entry{ 75, "z,n25", { "n,n'(25)", "n,n25", "z,n'(25)" }, { n }, 25 } },
      { 76, ReactionNumber::Entry{ 76, "z,n26", { "n,n'(26)", "n,n26", "z,n'(26)" }, { n }, 26 } },
      { 77, ReactionNumber::Entry{ 77, "z,n27", { "n,n'(27)", "n,n27", "z,n'(27)" }, { n }, 27 } },
      { 78, ReactionNumber::Entry{ 78, "z,n28", { "n,n'(28)", "n,n28", "z,n'(28)" }, { n }, 28 } },
      { 79, ReactionNumber::Entry{ 79, "z,n29", { "n,n'(29)", "n,n29", "z,n'(29)" }, { n }, 29 } },
      { 80, ReactionNumber::Entry{ 80, "z,n30", { "n,n'(30)", "n,n30", "z,n'(30)" }, { n }, 30 } },
      { 81, ReactionNumber::Entry{ 81, "z,n31", { "n,n'(31)", "n,n31", "z,n'(31)" }, { n }, 31 } },
      { 82, ReactionNumber::Entry{ 82, "z,n32", { "n,n'(32)", "n,n32", "z,n'(32)" }, { n }, 32 } },
      { 83, ReactionNumber::Entry{ 83, "z,n33", { "n,n'(33)", "n,n33", "z,n'(33)" }, { n }, 33 } },
      { 84, ReactionNumber::Entry{ 84, "z,n34", { "n,n'(34)", "n,n34", "z,n'(34)" }, { n }, 34 } },
      { 85, ReactionNumber::Entry{ 85, "z,n35", { "n,n'(35)", "n,n35", "z,n'(35)" }, { n }, 35 } },
      { 86, ReactionNumber::Entry{ 86, "z,n36", { "n,n'(36)", "n,n36", "z,n'(36)" }, { n }, 36 } },
      { 87, ReactionNumber::Entry{ 87, "z,n37", { "n,n'(37)", "n,n37", "z,n'(37)" }, { n }, 37 } },
      { 88, ReactionNumber::Entry{ 88, "z,n38", { "n,n'(38)", "n,n38", "z,n'(38)" }, { n }, 38 } },
      { 89, ReactionNumber::Entry{ 89, "z,n39", { "n,n'(39)", "n,n39", "z,n'(39)" }, { n }, 39 } },
      { 90, ReactionNumber::Entry{ 90, "z,n40", { "n,n'(40)", "n,n40", "z,n'(40)" }, { n }, 40 } }
     }; }()
};

// register the alternatives (stored in lower case)
const std::map< std::string, ReactionNumber::Number >
ReactionNumber::conversion_dictionary = [] ( const auto& dictionary ) {

  std::map< std::string, ReactionNumber::Number > conversion;
  for ( const auto& [ number, entry ] : dictionary ) {

    conversion[ tolower( entry.name() ) ] = number;
    for ( const auto& alternative : entry.alternatives() ) {

      conversion[ tolower( alternative ) ] = number;
    }
  }
  return conversion;
}( ReactionNumber::mt_dictionary );
