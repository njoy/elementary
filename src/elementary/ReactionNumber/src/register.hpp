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
      { 200, ReactionNumber::Entry{ 200, "z,5n2p", { "n,5n2p" }, { n, n, n, n, n, p, p } } },
      { 600, ReactionNumber::Entry{ 600, "z,p0", { "n,p0" }, { p }, 0 } },
      { 601, ReactionNumber::Entry{ 601, "z,p1", { "n,p1" }, { p }, 1 } },
      { 602, ReactionNumber::Entry{ 602, "z,p2", { "n,p2" }, { p }, 2 } },
      { 603, ReactionNumber::Entry{ 603, "z,p3", { "n,p3" }, { p }, 3 } },
      { 604, ReactionNumber::Entry{ 604, "z,p4", { "n,p4" }, { p }, 4 } },
      { 605, ReactionNumber::Entry{ 605, "z,p5", { "n,p5" }, { p }, 5 } },
      { 606, ReactionNumber::Entry{ 606, "z,p6", { "n,p6" }, { p }, 6 } },
      { 607, ReactionNumber::Entry{ 607, "z,p7", { "n,p7" }, { p }, 7 } },
      { 608, ReactionNumber::Entry{ 608, "z,p8", { "n,p8" }, { p }, 8 } },
      { 609, ReactionNumber::Entry{ 609, "z,p9", { "n,p9" }, { p }, 9 } },
      { 610, ReactionNumber::Entry{ 610, "z,p10", { "n,p10" }, { p }, 10 } },
      { 611, ReactionNumber::Entry{ 611, "z,p11", { "n,p11" }, { p }, 11 } },
      { 612, ReactionNumber::Entry{ 612, "z,p12", { "n,p12" }, { p }, 12 } },
      { 613, ReactionNumber::Entry{ 613, "z,p13", { "n,p13" }, { p }, 13 } },
      { 614, ReactionNumber::Entry{ 614, "z,p14", { "n,p14" }, { p }, 14 } },
      { 615, ReactionNumber::Entry{ 615, "z,p15", { "n,p15" }, { p }, 15 } },
      { 616, ReactionNumber::Entry{ 616, "z,p16", { "n,p16" }, { p }, 16 } },
      { 617, ReactionNumber::Entry{ 617, "z,p17", { "n,p17" }, { p }, 17 } },
      { 618, ReactionNumber::Entry{ 618, "z,p18", { "n,p18" }, { p }, 18 } },
      { 619, ReactionNumber::Entry{ 619, "z,p19", { "n,p19" }, { p }, 19 } },
      { 620, ReactionNumber::Entry{ 620, "z,p20", { "n,p20" }, { p }, 20 } },
      { 621, ReactionNumber::Entry{ 621, "z,p21", { "n,p21" }, { p }, 21 } },
      { 622, ReactionNumber::Entry{ 622, "z,p22", { "n,p22" }, { p }, 22 } },
      { 623, ReactionNumber::Entry{ 623, "z,p23", { "n,p23" }, { p }, 23 } },
      { 624, ReactionNumber::Entry{ 624, "z,p24", { "n,p24" }, { p }, 24 } },
      { 625, ReactionNumber::Entry{ 625, "z,p25", { "n,p25" }, { p }, 25 } },
      { 626, ReactionNumber::Entry{ 626, "z,p26", { "n,p26" }, { p }, 26 } },
      { 627, ReactionNumber::Entry{ 627, "z,p27", { "n,p27" }, { p }, 27 } },
      { 628, ReactionNumber::Entry{ 628, "z,p28", { "n,p28" }, { p }, 28 } },
      { 629, ReactionNumber::Entry{ 629, "z,p29", { "n,p29" }, { p }, 29 } },
      { 630, ReactionNumber::Entry{ 630, "z,p30", { "n,p30" }, { p }, 30 } },
      { 631, ReactionNumber::Entry{ 631, "z,p31", { "n,p31" }, { p }, 31 } },
      { 632, ReactionNumber::Entry{ 632, "z,p32", { "n,p32" }, { p }, 32 } },
      { 633, ReactionNumber::Entry{ 633, "z,p33", { "n,p33" }, { p }, 33 } },
      { 634, ReactionNumber::Entry{ 634, "z,p34", { "n,p34" }, { p }, 34 } },
      { 635, ReactionNumber::Entry{ 635, "z,p35", { "n,p35" }, { p }, 35 } },
      { 636, ReactionNumber::Entry{ 636, "z,p36", { "n,p36" }, { p }, 36 } },
      { 637, ReactionNumber::Entry{ 637, "z,p37", { "n,p37" }, { p }, 37 } },
      { 638, ReactionNumber::Entry{ 638, "z,p38", { "n,p38" }, { p }, 38 } },
      { 639, ReactionNumber::Entry{ 639, "z,p39", { "n,p39" }, { p }, 39 } },
      { 640, ReactionNumber::Entry{ 640, "z,p40", { "n,p40" }, { p }, 40 } },
      { 641, ReactionNumber::Entry{ 641, "z,p41", { "n,p41" }, { p }, 41 } },
      { 642, ReactionNumber::Entry{ 642, "z,p42", { "n,p42" }, { p }, 42 } },
      { 643, ReactionNumber::Entry{ 643, "z,p43", { "n,p43" }, { p }, 43 } },
      { 644, ReactionNumber::Entry{ 644, "z,p44", { "n,p44" }, { p }, 44 } },
      { 645, ReactionNumber::Entry{ 645, "z,p45", { "n,p45" }, { p }, 45 } },
      { 646, ReactionNumber::Entry{ 646, "z,p46", { "n,p46" }, { p }, 46 } },
      { 647, ReactionNumber::Entry{ 647, "z,p47", { "n,p47" }, { p }, 47 } },
      { 648, ReactionNumber::Entry{ 648, "z,p48", { "n,p48" }, { p }, 48 } },
      //{ 649, ReactionNumber::Entry{ 649, "z,pc", { "n,pc" }, { p } } },
      { 650, ReactionNumber::Entry{ 650, "z,d0", { "n,d0" }, { d }, 0 } },
      { 651, ReactionNumber::Entry{ 651, "z,d1", { "n,d1" }, { d }, 1 } },
      { 652, ReactionNumber::Entry{ 652, "z,d2", { "n,d2" }, { d }, 2 } },
      { 653, ReactionNumber::Entry{ 653, "z,d3", { "n,d3" }, { d }, 3 } },
      { 654, ReactionNumber::Entry{ 654, "z,d4", { "n,d4" }, { d }, 4 } },
      { 655, ReactionNumber::Entry{ 655, "z,d5", { "n,d5" }, { d }, 5 } },
      { 656, ReactionNumber::Entry{ 656, "z,d6", { "n,d6" }, { d }, 6 } },
      { 657, ReactionNumber::Entry{ 657, "z,d7", { "n,d7" }, { d }, 7 } },
      { 658, ReactionNumber::Entry{ 658, "z,d8", { "n,d8" }, { d }, 8 } },
      { 659, ReactionNumber::Entry{ 659, "z,d9", { "n,d9" }, { d }, 9 } },
      { 660, ReactionNumber::Entry{ 660, "z,d10", { "n,d10" }, { d }, 10 } },
      { 661, ReactionNumber::Entry{ 661, "z,d11", { "n,d11" }, { d }, 11 } },
      { 662, ReactionNumber::Entry{ 662, "z,d12", { "n,d12" }, { d }, 12 } },
      { 663, ReactionNumber::Entry{ 663, "z,d13", { "n,d13" }, { d }, 13 } },
      { 664, ReactionNumber::Entry{ 664, "z,d14", { "n,d14" }, { d }, 14 } },
      { 665, ReactionNumber::Entry{ 665, "z,d15", { "n,d15" }, { d }, 15 } },
      { 666, ReactionNumber::Entry{ 666, "z,d16", { "n,d16" }, { d }, 16 } },
      { 667, ReactionNumber::Entry{ 667, "z,d17", { "n,d17" }, { d }, 17 } },
      { 668, ReactionNumber::Entry{ 668, "z,d18", { "n,d18" }, { d }, 18 } },
      { 669, ReactionNumber::Entry{ 669, "z,d19", { "n,d19" }, { d }, 19 } },
      { 670, ReactionNumber::Entry{ 670, "z,d20", { "n,d20" }, { d }, 20 } },
      { 671, ReactionNumber::Entry{ 671, "z,d21", { "n,d21" }, { d }, 21 } },
      { 672, ReactionNumber::Entry{ 672, "z,d22", { "n,d22" }, { d }, 22 } },
      { 673, ReactionNumber::Entry{ 673, "z,d23", { "n,d23" }, { d }, 23 } },
      { 674, ReactionNumber::Entry{ 674, "z,d24", { "n,d24" }, { d }, 24 } },
      { 675, ReactionNumber::Entry{ 675, "z,d25", { "n,d25" }, { d }, 25 } },
      { 676, ReactionNumber::Entry{ 676, "z,d26", { "n,d26" }, { d }, 26 } },
      { 677, ReactionNumber::Entry{ 677, "z,d27", { "n,d27" }, { d }, 27 } },
      { 678, ReactionNumber::Entry{ 678, "z,d28", { "n,d28" }, { d }, 28 } },
      { 679, ReactionNumber::Entry{ 679, "z,d29", { "n,d29" }, { d }, 29 } },
      { 680, ReactionNumber::Entry{ 680, "z,d30", { "n,d30" }, { d }, 30 } },
      { 681, ReactionNumber::Entry{ 681, "z,d31", { "n,d31" }, { d }, 31 } },
      { 682, ReactionNumber::Entry{ 682, "z,d32", { "n,d32" }, { d }, 32 } },
      { 683, ReactionNumber::Entry{ 683, "z,d33", { "n,d33" }, { d }, 33 } },
      { 684, ReactionNumber::Entry{ 684, "z,d34", { "n,d34" }, { d }, 34 } },
      { 685, ReactionNumber::Entry{ 685, "z,d35", { "n,d35" }, { d }, 35 } },
      { 686, ReactionNumber::Entry{ 686, "z,d36", { "n,d36" }, { d }, 36 } },
      { 687, ReactionNumber::Entry{ 687, "z,d37", { "n,d37" }, { d }, 37 } },
      { 688, ReactionNumber::Entry{ 688, "z,d38", { "n,d38" }, { d }, 38 } },
      { 689, ReactionNumber::Entry{ 689, "z,d39", { "n,d39" }, { d }, 39 } },
      { 690, ReactionNumber::Entry{ 650, "z,d40", { "n,d40" }, { d }, 40 } },
      { 691, ReactionNumber::Entry{ 651, "z,d41", { "n,d41" }, { d }, 41 } },
      { 692, ReactionNumber::Entry{ 652, "z,d42", { "n,d42" }, { d }, 42 } },
      { 693, ReactionNumber::Entry{ 653, "z,d43", { "n,d43" }, { d }, 43 } },
      { 694, ReactionNumber::Entry{ 654, "z,d44", { "n,d44" }, { d }, 44 } },
      { 695, ReactionNumber::Entry{ 655, "z,d45", { "n,d45" }, { d }, 45 } },
      { 696, ReactionNumber::Entry{ 656, "z,d46", { "n,d46" }, { d }, 46 } },
      { 697, ReactionNumber::Entry{ 657, "z,d47", { "n,d47" }, { d }, 47 } },
      { 698, ReactionNumber::Entry{ 658, "z,d48", { "n,d48" }, { d }, 48 } },
      //{ 699, ReactionNumber::Entry{ 699, "z,dc", { "n,dc" }, { d } } },
      { 700, ReactionNumber::Entry{ 700, "z,t0", { "n,t0" }, { t }, 0 } },
      { 701, ReactionNumber::Entry{ 701, "z,t1", { "n,t1" }, { t }, 1 } },
      { 702, ReactionNumber::Entry{ 702, "z,t2", { "n,t2" }, { t }, 2 } },
      { 703, ReactionNumber::Entry{ 703, "z,t3", { "n,t3" }, { t }, 3 } },
      { 704, ReactionNumber::Entry{ 704, "z,t4", { "n,t4" }, { t }, 4 } },
      { 705, ReactionNumber::Entry{ 705, "z,t5", { "n,t5" }, { t }, 5 } },
      { 706, ReactionNumber::Entry{ 706, "z,t6", { "n,t6" }, { t }, 6 } },
      { 707, ReactionNumber::Entry{ 707, "z,t7", { "n,t7" }, { t }, 7 } },
      { 708, ReactionNumber::Entry{ 708, "z,t8", { "n,t8" }, { t }, 8 } },
      { 709, ReactionNumber::Entry{ 709, "z,t9", { "n,t9" }, { t }, 9 } },
      { 710, ReactionNumber::Entry{ 710, "z,t10", { "n,t10" }, { t }, 10 } },
      { 711, ReactionNumber::Entry{ 711, "z,t11", { "n,t11" }, { t }, 11 } },
      { 712, ReactionNumber::Entry{ 712, "z,t12", { "n,t12" }, { t }, 12 } },
      { 713, ReactionNumber::Entry{ 713, "z,t13", { "n,t13" }, { t }, 13 } },
      { 714, ReactionNumber::Entry{ 714, "z,t14", { "n,t14" }, { t }, 14 } },
      { 715, ReactionNumber::Entry{ 715, "z,t15", { "n,t15" }, { t }, 15 } },
      { 716, ReactionNumber::Entry{ 716, "z,t16", { "n,t16" }, { t }, 16 } },
      { 717, ReactionNumber::Entry{ 717, "z,t17", { "n,t17" }, { t }, 17 } },
      { 718, ReactionNumber::Entry{ 718, "z,t18", { "n,t18" }, { t }, 18 } },
      { 719, ReactionNumber::Entry{ 719, "z,t19", { "n,t19" }, { t }, 19 } },
      { 720, ReactionNumber::Entry{ 720, "z,t20", { "n,t20" }, { t }, 20 } },
      { 721, ReactionNumber::Entry{ 721, "z,t21", { "n,t21" }, { t }, 21 } },
      { 722, ReactionNumber::Entry{ 722, "z,t22", { "n,t22" }, { t }, 22 } },
      { 723, ReactionNumber::Entry{ 723, "z,t23", { "n,t23" }, { t }, 23 } },
      { 724, ReactionNumber::Entry{ 724, "z,t24", { "n,t24" }, { t }, 24 } },
      { 725, ReactionNumber::Entry{ 725, "z,t25", { "n,t25" }, { t }, 25 } },
      { 726, ReactionNumber::Entry{ 726, "z,t26", { "n,t26" }, { t }, 26 } },
      { 727, ReactionNumber::Entry{ 727, "z,t27", { "n,t27" }, { t }, 27 } },
      { 728, ReactionNumber::Entry{ 728, "z,t28", { "n,t28" }, { t }, 28 } },
      { 729, ReactionNumber::Entry{ 729, "z,t29", { "n,t29" }, { t }, 29 } },
      { 730, ReactionNumber::Entry{ 730, "z,t30", { "n,t30" }, { t }, 30 } },
      { 731, ReactionNumber::Entry{ 731, "z,t31", { "n,t31" }, { t }, 31 } },
      { 732, ReactionNumber::Entry{ 732, "z,t32", { "n,t32" }, { t }, 32 } },
      { 733, ReactionNumber::Entry{ 733, "z,t33", { "n,t33" }, { t }, 33 } },
      { 734, ReactionNumber::Entry{ 734, "z,t34", { "n,t34" }, { t }, 34 } },
      { 735, ReactionNumber::Entry{ 735, "z,t35", { "n,t35" }, { t }, 35 } },
      { 736, ReactionNumber::Entry{ 736, "z,t36", { "n,t36" }, { t }, 36 } },
      { 737, ReactionNumber::Entry{ 737, "z,t37", { "n,t37" }, { t }, 37 } },
      { 738, ReactionNumber::Entry{ 738, "z,t38", { "n,t38" }, { t }, 38 } },
      { 739, ReactionNumber::Entry{ 739, "z,t39", { "n,t39" }, { t }, 39 } },
      { 740, ReactionNumber::Entry{ 740, "z,t40", { "n,t40" }, { t }, 40 } },
      { 741, ReactionNumber::Entry{ 741, "z,t41", { "n,t41" }, { t }, 41 } },
      { 742, ReactionNumber::Entry{ 742, "z,t42", { "n,t42" }, { t }, 42 } },
      { 743, ReactionNumber::Entry{ 743, "z,t43", { "n,t43" }, { t }, 43 } },
      { 744, ReactionNumber::Entry{ 744, "z,t44", { "n,t44" }, { t }, 44 } },
      { 745, ReactionNumber::Entry{ 745, "z,t45", { "n,t45" }, { t }, 45 } },
      { 746, ReactionNumber::Entry{ 746, "z,t46", { "n,t46" }, { t }, 46 } },
      { 747, ReactionNumber::Entry{ 747, "z,t47", { "n,t47" }, { t }, 47 } },
      { 748, ReactionNumber::Entry{ 748, "z,t48", { "n,t48" }, { t }, 48 } },
      //{ 749, ReactionNumber::Entry{ 749, "z,tc", { "n,tc" }, { t } } },
      { 750, ReactionNumber::Entry{ 750, "z,h0", { "n,h0" }, { h }, 0 } },
      { 751, ReactionNumber::Entry{ 751, "z,h1", { "n,h1" }, { h }, 1 } },
      { 752, ReactionNumber::Entry{ 752, "z,h2", { "n,h2" }, { h }, 2 } },
      { 753, ReactionNumber::Entry{ 753, "z,h3", { "n,h3" }, { h }, 3 } },
      { 754, ReactionNumber::Entry{ 754, "z,h4", { "n,h4" }, { h }, 4 } },
      { 755, ReactionNumber::Entry{ 755, "z,h5", { "n,h5" }, { h }, 5 } },
      { 756, ReactionNumber::Entry{ 756, "z,h6", { "n,h6" }, { h }, 6 } },
      { 757, ReactionNumber::Entry{ 757, "z,h7", { "n,h7" }, { h }, 7 } },
      { 758, ReactionNumber::Entry{ 758, "z,h8", { "n,h8" }, { h }, 8 } },
      { 759, ReactionNumber::Entry{ 759, "z,h9", { "n,h9" }, { h }, 9 } },
      { 760, ReactionNumber::Entry{ 760, "z,h10", { "n,h10" }, { h }, 10 } },
      { 761, ReactionNumber::Entry{ 761, "z,h11", { "n,h11" }, { h }, 11 } },
      { 762, ReactionNumber::Entry{ 762, "z,h12", { "n,h12" }, { h }, 12 } },
      { 763, ReactionNumber::Entry{ 763, "z,h13", { "n,h13" }, { h }, 13 } },
      { 764, ReactionNumber::Entry{ 764, "z,h14", { "n,h14" }, { h }, 14 } },
      { 765, ReactionNumber::Entry{ 765, "z,h15", { "n,h15" }, { h }, 15 } },
      { 766, ReactionNumber::Entry{ 766, "z,h16", { "n,h16" }, { h }, 16 } },
      { 767, ReactionNumber::Entry{ 767, "z,h17", { "n,h17" }, { h }, 17 } },
      { 768, ReactionNumber::Entry{ 768, "z,h18", { "n,h18" }, { h }, 18 } },
      { 769, ReactionNumber::Entry{ 769, "z,h19", { "n,h19" }, { h }, 19 } },
      { 770, ReactionNumber::Entry{ 770, "z,h20", { "n,h20" }, { h }, 20 } },
      { 771, ReactionNumber::Entry{ 771, "z,h21", { "n,h21" }, { h }, 21 } },
      { 772, ReactionNumber::Entry{ 772, "z,h22", { "n,h22" }, { h }, 22 } },
      { 773, ReactionNumber::Entry{ 773, "z,h23", { "n,h23" }, { h }, 23 } },
      { 774, ReactionNumber::Entry{ 774, "z,h24", { "n,h24" }, { h }, 24 } },
      { 775, ReactionNumber::Entry{ 775, "z,h25", { "n,h25" }, { h }, 25 } },
      { 776, ReactionNumber::Entry{ 776, "z,h26", { "n,h26" }, { h }, 26 } },
      { 777, ReactionNumber::Entry{ 777, "z,h27", { "n,h27" }, { h }, 27 } },
      { 778, ReactionNumber::Entry{ 778, "z,h28", { "n,h28" }, { h }, 28 } },
      { 779, ReactionNumber::Entry{ 779, "z,h29", { "n,h29" }, { h }, 29 } },
      { 780, ReactionNumber::Entry{ 780, "z,h30", { "n,h30" }, { h }, 30 } },
      { 781, ReactionNumber::Entry{ 781, "z,h31", { "n,h31" }, { h }, 31 } },
      { 782, ReactionNumber::Entry{ 782, "z,h32", { "n,h32" }, { h }, 32 } },
      { 783, ReactionNumber::Entry{ 783, "z,h33", { "n,h33" }, { h }, 33 } },
      { 784, ReactionNumber::Entry{ 784, "z,h34", { "n,h34" }, { h }, 34 } },
      { 785, ReactionNumber::Entry{ 785, "z,h35", { "n,h35" }, { h }, 35 } },
      { 786, ReactionNumber::Entry{ 786, "z,h36", { "n,h36" }, { h }, 36 } },
      { 787, ReactionNumber::Entry{ 787, "z,h37", { "n,h37" }, { h }, 37 } },
      { 788, ReactionNumber::Entry{ 788, "z,h38", { "n,h38" }, { h }, 38 } },
      { 789, ReactionNumber::Entry{ 789, "z,h39", { "n,h39" }, { h }, 39 } },
      { 790, ReactionNumber::Entry{ 750, "z,h40", { "n,h40" }, { h }, 40 } },
      { 791, ReactionNumber::Entry{ 751, "z,h41", { "n,h41" }, { h }, 41 } },
      { 792, ReactionNumber::Entry{ 752, "z,h42", { "n,h42" }, { h }, 42 } },
      { 793, ReactionNumber::Entry{ 753, "z,h43", { "n,h43" }, { h }, 43 } },
      { 794, ReactionNumber::Entry{ 754, "z,h44", { "n,h44" }, { h }, 44 } },
      { 795, ReactionNumber::Entry{ 755, "z,h45", { "n,h45" }, { h }, 45 } },
      { 796, ReactionNumber::Entry{ 756, "z,h46", { "n,h46" }, { h }, 46 } },
      { 797, ReactionNumber::Entry{ 757, "z,h47", { "n,h47" }, { h }, 47 } },
      { 798, ReactionNumber::Entry{ 758, "z,h48", { "n,h48" }, { h }, 48 } },
      //{ 799, ReactionNumber::Entry{ 799, "z,hc", { "n,hc" }, { h } } },
      { 800, ReactionNumber::Entry{ 800, "z,a0", { "n,a0" }, { a }, 0 } },
      { 801, ReactionNumber::Entry{ 801, "z,a1", { "n,a1" }, { a }, 1 } },
      { 802, ReactionNumber::Entry{ 802, "z,a2", { "n,a2" }, { a }, 2 } },
      { 803, ReactionNumber::Entry{ 803, "z,a3", { "n,a3" }, { a }, 3 } },
      { 804, ReactionNumber::Entry{ 804, "z,a4", { "n,a4" }, { a }, 4 } },
      { 805, ReactionNumber::Entry{ 805, "z,a5", { "n,a5" }, { a }, 5 } },
      { 806, ReactionNumber::Entry{ 806, "z,a6", { "n,a6" }, { a }, 6 } },
      { 807, ReactionNumber::Entry{ 807, "z,a7", { "n,a7" }, { a }, 7 } },
      { 808, ReactionNumber::Entry{ 808, "z,a8", { "n,a8" }, { a }, 8 } },
      { 809, ReactionNumber::Entry{ 809, "z,a9", { "n,a9" }, { a }, 9 } },
      { 810, ReactionNumber::Entry{ 810, "z,a10", { "n,a10" }, { a }, 10 } },
      { 811, ReactionNumber::Entry{ 811, "z,a11", { "n,a11" }, { a }, 11 } },
      { 812, ReactionNumber::Entry{ 812, "z,a12", { "n,a12" }, { a }, 12 } },
      { 813, ReactionNumber::Entry{ 813, "z,a13", { "n,a13" }, { a }, 13 } },
      { 814, ReactionNumber::Entry{ 814, "z,a14", { "n,a14" }, { a }, 14 } },
      { 815, ReactionNumber::Entry{ 815, "z,a15", { "n,a15" }, { a }, 15 } },
      { 816, ReactionNumber::Entry{ 816, "z,a16", { "n,a16" }, { a }, 16 } },
      { 817, ReactionNumber::Entry{ 817, "z,a17", { "n,a17" }, { a }, 17 } },
      { 818, ReactionNumber::Entry{ 818, "z,a18", { "n,a18" }, { a }, 18 } },
      { 819, ReactionNumber::Entry{ 819, "z,a19", { "n,a19" }, { a }, 19 } },
      { 820, ReactionNumber::Entry{ 820, "z,a20", { "n,a20" }, { a }, 20 } },
      { 821, ReactionNumber::Entry{ 821, "z,a21", { "n,a21" }, { a }, 21 } },
      { 822, ReactionNumber::Entry{ 822, "z,a22", { "n,a22" }, { a }, 22 } },
      { 823, ReactionNumber::Entry{ 823, "z,a23", { "n,a23" }, { a }, 23 } },
      { 824, ReactionNumber::Entry{ 824, "z,a24", { "n,a24" }, { a }, 24 } },
      { 825, ReactionNumber::Entry{ 825, "z,a25", { "n,a25" }, { a }, 25 } },
      { 826, ReactionNumber::Entry{ 826, "z,a26", { "n,a26" }, { a }, 26 } },
      { 827, ReactionNumber::Entry{ 827, "z,a27", { "n,a27" }, { a }, 27 } },
      { 828, ReactionNumber::Entry{ 828, "z,a28", { "n,a28" }, { a }, 28 } },
      { 829, ReactionNumber::Entry{ 829, "z,a29", { "n,a29" }, { a }, 29 } },
      { 830, ReactionNumber::Entry{ 830, "z,a30", { "n,a30" }, { a }, 30 } },
      { 831, ReactionNumber::Entry{ 831, "z,a31", { "n,a31" }, { a }, 31 } },
      { 832, ReactionNumber::Entry{ 832, "z,a32", { "n,a32" }, { a }, 32 } },
      { 833, ReactionNumber::Entry{ 833, "z,a33", { "n,a33" }, { a }, 33 } },
      { 834, ReactionNumber::Entry{ 834, "z,a34", { "n,a34" }, { a }, 34 } },
      { 835, ReactionNumber::Entry{ 835, "z,a35", { "n,a35" }, { a }, 35 } },
      { 836, ReactionNumber::Entry{ 836, "z,a36", { "n,a36" }, { a }, 36 } },
      { 837, ReactionNumber::Entry{ 837, "z,a37", { "n,a37" }, { a }, 37 } },
      { 838, ReactionNumber::Entry{ 838, "z,a38", { "n,a38" }, { a }, 38 } },
      { 839, ReactionNumber::Entry{ 839, "z,a39", { "n,a39" }, { a }, 39 } },
      { 840, ReactionNumber::Entry{ 840, "z,a40", { "n,a40" }, { a }, 40 } },
      { 841, ReactionNumber::Entry{ 841, "z,a41", { "n,a41" }, { a }, 41 } },
      { 842, ReactionNumber::Entry{ 842, "z,a42", { "n,a42" }, { a }, 42 } },
      { 843, ReactionNumber::Entry{ 843, "z,a43", { "n,a43" }, { a }, 43 } },
      { 844, ReactionNumber::Entry{ 844, "z,a44", { "n,a44" }, { a }, 44 } },
      { 845, ReactionNumber::Entry{ 845, "z,a45", { "n,a45" }, { a }, 45 } },
      { 846, ReactionNumber::Entry{ 846, "z,a46", { "n,a46" }, { a }, 46 } },
      { 847, ReactionNumber::Entry{ 847, "z,a47", { "n,a47" }, { a }, 47 } },
      { 848, ReactionNumber::Entry{ 848, "z,a48", { "n,a48" }, { a }, 48 } },
      //{ 849, ReactionNumber::Entry{ 849, "z,ac", { "n,ac" }, { a } } },
      { 875, ReactionNumber::Entry{ 875, "z,2n0", { "n,2n0" }, { n, n }, 0 } },
      { 876, ReactionNumber::Entry{ 876, "z,2n1", { "n,2n1" }, { n, n }, 1 } },
      { 877, ReactionNumber::Entry{ 877, "z,2n2", { "n,2n2" }, { n, n }, 2 } },
      { 878, ReactionNumber::Entry{ 878, "z,2n3", { "n,2n3" }, { n, n }, 3 } },
      { 879, ReactionNumber::Entry{ 879, "z,2n4", { "n,2n4" }, { n, n }, 4 } },
      { 880, ReactionNumber::Entry{ 880, "z,2n5", { "n,2n5" }, { n, n }, 5 } },
      { 881, ReactionNumber::Entry{ 881, "z,2n6", { "n,2n6" }, { n, n }, 6 } },
      { 882, ReactionNumber::Entry{ 882, "z,2n7", { "n,2n7" }, { n, n }, 7 } },
      { 883, ReactionNumber::Entry{ 883, "z,2n8", { "n,2n8" }, { n, n }, 8 } },
      { 884, ReactionNumber::Entry{ 884, "z,2n9", { "n,2n9" }, { n, n }, 9 } },
      { 885, ReactionNumber::Entry{ 885, "z,2n10", { "n,2n10" }, { n, n }, 10 } },
      { 886, ReactionNumber::Entry{ 886, "z,2n11", { "n,2n11" }, { n, n }, 11 } },
      { 887, ReactionNumber::Entry{ 887, "z,2n12", { "n,2n12" }, { n, n }, 12 } },
      { 888, ReactionNumber::Entry{ 888, "z,2n13", { "n,2n13" }, { n, n }, 13 } },
      { 889, ReactionNumber::Entry{ 889, "z,2n14", { "n,2n14" }, { n, n }, 14 } },
      { 890, ReactionNumber::Entry{ 890, "z,2n15", { "n,2n15" }, { n, n }, 15 } }//,
      //{ 891, ReactionNumber::Entry{ 891, "z,2nc", { "n,2nc" }, { n, n } } }
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
