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
    ParticleID g( "photon" );

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
      { 90, ReactionNumber::Entry{ 90, "z,n40", { "n,n'(40)", "n,n40", "z,n'(40)" }, { n }, 40 } },
      //{ 91, ReactionNumber::Entry{ "mt": 91, "z,nc", { "n,n'(c)", "n,nc", "z,n'(c)" }, { n } } },
      { 102, ReactionNumber::Entry{ 102, "capture", { "n,g", "n,gamma", "z,g", "z,gamma" }, { g } } },
      { 103, ReactionNumber::Entry{ 103, "z,p", { "n,p", "n,proton", "z,proton" }, { p } } },
      { 104, ReactionNumber::Entry{ 104, "z,d", { "n,d", "n,deuteron", "z,deuteron" }, { d } } },
      { 105, ReactionNumber::Entry{ 105, "z,t", { "n,t", "n,triton", "z,triton" }, { t } } },
      { 106, ReactionNumber::Entry{ 106, "z,h", { "n,3he", "n,h", "n,he3", "n,helion", "z,3he", "z,he3", "z,helion" }, { h } } },
      { 107, ReactionNumber::Entry{ 107, "z,a", { "n,a", "n,alpha", "z,alpha" }, { a } } },
      { 108, ReactionNumber::Entry{ 108, "z,2a", { "n,2a" }, { a, a } } },
      { 109, ReactionNumber::Entry{ 109, "z,3a", { "n,3a" }, { a, a, a } } },
      { 111, ReactionNumber::Entry{ 111, "z,2p", { "n,2p" }, { p, p } } },
      { 112, ReactionNumber::Entry{ 112, "z,pa", { "n,pa" }, { p, a } } },
      { 113, ReactionNumber::Entry{ 113, "z,t2a", { "n,t2a" }, { t, a, a } } },
      { 114, ReactionNumber::Entry{ 114, "z,d2a", { "n,d2a" }, { d, a, a } } },
      { 115, ReactionNumber::Entry{ 115, "z,pd", { "n,pd" }, { p, d } } },
      { 116, ReactionNumber::Entry{ 116, "z,pt", { "n,pt" }, { p, t } } },
      { 117, ReactionNumber::Entry{ 117, "z,da", { "n,da" }, { d, a } } },
      { 152, ReactionNumber::Entry{ 152, "z,5n", { "n,5n" }, { n, n, n, n, n } } },
      { 153, ReactionNumber::Entry{ 153, "z,6n", { "n,6n" }, { n, n, n, n, n, n } } },
      { 154, ReactionNumber::Entry{ 154, "z,2nt", { "n,2nt" }, { n, n, t } } },
      { 155, ReactionNumber::Entry{ 155, "z,ta", { "n,ta" }, { t, a } } },
      { 156, ReactionNumber::Entry{ 156, "z,4np", { "n,4np" }, { n, n, n, n, p } } },
      { 157, ReactionNumber::Entry{ 157, "z,3nd", { "n,3nd" }, { n, n, n, d } } },
      { 158, ReactionNumber::Entry{ 158, "z,nda", { "n,nda" }, { n, d, a } } },
      { 159, ReactionNumber::Entry{ 159, "z,2npa", { "n,2npa" }, { n, n, p, a } } },
      { 160, ReactionNumber::Entry{ 160, "z,7n", { "n,7n" }, { n, n, n, n, n, n, n } } },
      { 161, ReactionNumber::Entry{ 161, "z,8n", { "n,8n" }, { n, n, n, n, n, n, n, n } } },
      { 162, ReactionNumber::Entry{ 162, "z,5np", { "n,5np" }, { n, n, n, n, n, p } } },
      { 163, ReactionNumber::Entry{ 163, "z,6np", { "n,6np" }, { n, n, n, n, n, n, p } } },
      { 164, ReactionNumber::Entry{ 164, "z,7np", { "n,7np" }, { n, n, n, n, n, n, n, p } } },
      { 165, ReactionNumber::Entry{ 165, "z,4na", { "n,4na" }, { n, n, n, n, a } } },
      { 166, ReactionNumber::Entry{ 166, "z,5na", { "n,5na" }, { n, n, n, n, n, a } } },
      { 167, ReactionNumber::Entry{ 167, "z,6na", { "n,6na" }, { n, n, n, n, n, n, a } } },
      { 168, ReactionNumber::Entry{ 168, "z,7na", { "n,7na" }, { n, n, n, n, n, n, n, a } } },
      { 169, ReactionNumber::Entry{ 169, "z,4nd", { "n,4nd" }, { n, n, n, n, d } } },
      { 170, ReactionNumber::Entry{ 170, "z,5nd", { "n,5nd" }, { n, n, n, n, n, d } } },
      { 171, ReactionNumber::Entry{ 171, "z,6nd", { "n,6nd" }, { n, n, n, n, n, n, d } } },
      { 172, ReactionNumber::Entry{ 172, "z,3nt", { "n,3nt" }, { n, n, n, t } } },
      { 173, ReactionNumber::Entry{ 173, "z,4nt", { "n,4nt" }, { n, n, n, n, t } } },
      { 174, ReactionNumber::Entry{ 174, "z,5nt", { "n,5nt" }, { n, n, n, n, n, t } } },
      { 175, ReactionNumber::Entry{ 175, "z,6nt", { "n,6nt" }, { n, n, n, n, n, n, t } } },
      { 176, ReactionNumber::Entry{ 176, "z,2nh", { "n,2n3he", "n,2nh", "n,2nhe3", "z,2n3he", "z,2nhe3" }, { n, n, h } } },
      { 177, ReactionNumber::Entry{ 177, "z,3nh", { "n,3n3he", "n,3nh", "n,3nhe3", "z,3n3he", "z,3nhe3" }, { n, n, n, h } } },
      { 178, ReactionNumber::Entry{ 178, "z,4nh", { "n,4n3he", "n,4nh", "n,4nhe3", "z,4n3he", "z,4nhe3" }, { n, n, n, n, h } } },
      { 179, ReactionNumber::Entry{ 179, "z,3n2p", { "n,3n2p" }, { n, n, n, p, p } } },
      { 180, ReactionNumber::Entry{ 180, "z,3n2a", { "n,3n2a" }, { n, n, n, a, a } } },
      { 181, ReactionNumber::Entry{ 181, "z,3npa", { "n,3npa" }, { n, n, n, p, a } } },
      { 182, ReactionNumber::Entry{ 182, "z,dt", { "n,dt" }, { d, t } } },
      { 183, ReactionNumber::Entry{ 183, "z,npd", { "n,npd" }, { n, p, d } } },
      { 184, ReactionNumber::Entry{ 184, "z,npt", { "n,npt" }, { n, p, t } } },
      { 185, ReactionNumber::Entry{ 185, "z,ndt", { "n,ndt" }, { n, d, t } } },
      { 186, ReactionNumber::Entry{ 186, "z,nph", { "n,np3he", "n,nph", "n,nphe3", "z,np3he", "z,nphe3" }, { n, p, h } } },
      { 187, ReactionNumber::Entry{ 187, "z,ndh", { "n,nd3he", "n,ndh", "n,ndhe3", "z,nd3he", "z,ndhe3" }, { n, d, h } } },
      { 188, ReactionNumber::Entry{ 188, "z,nth", { "n,nt3he", "n,nth", "n,nthe3", "z,nt3he", "z,nthe3" }, { n, t, h } } },
      { 189, ReactionNumber::Entry{ 189, "z,nta", { "n,nta" }, { n, t, a } } },
      { 190, ReactionNumber::Entry{ 190, "z,2n2p", { "n,2n2p" }, { n, n, p, p } } },
      { 191, ReactionNumber::Entry{ 191, "z,ph", { "n,p3he", "n,ph", "n,phe3", "z,p3he", "z,phe3" }, { p, h } } },
      { 192, ReactionNumber::Entry{ 192, "z,dh", { "n,d3he", "n,dh", "n,dhe3", "z,d3he", "z,dhe3" }, { d, h } } },
      { 193, ReactionNumber::Entry{ 193, "z,ha", { "n,3hea", "n,ha", "n,he3a", "z,3hea", "z,he3a" }, { h, a } } },
      { 194, ReactionNumber::Entry{ 194, "z,4n2p", { "n,4n2p" }, { n, n, n, n, p, p } } },
      { 195, ReactionNumber::Entry{ 195, "z,4n2a", { "n,4n2a" }, { n, n, n, n, a, a } } },
      { 196, ReactionNumber::Entry{ 196, "z,4npa", { "n,4npa" }, { n, n, n, n, p, a } } },
      { 197, ReactionNumber::Entry{ 197, "z,3p", { "n,3p" }, { p, p, p } } },
      { 198, ReactionNumber::Entry{ 198, "z,n3p", { "n,n3p" }, { n, p, p, p } } },
      { 199, ReactionNumber::Entry{ 199, "z,3n2pa", { "n,3n2pa" }, { n, n, n, p, p, a } } },
      { 200, ReactionNumber::Entry{ 200, "z,5n2p", { "n,5n2p" }, { n, n, n, n, n, p, p } } }
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
