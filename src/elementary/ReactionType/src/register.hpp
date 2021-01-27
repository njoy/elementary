//! @todo this could be initialised using a json property file

// register the mt numbers, names, etc.
static inline const std::map< Name, Entry >
name_dictionary{

  [] () {

    ParticleID g( "g" );
    ParticleID n( "n" );
    ParticleID p( "p" );
    ParticleID d( "h2" );
    ParticleID t( "h3" );
    ParticleID h( "he3" );
    ParticleID a( "he4" );
    auto continuum = Level::continuum;

    std::vector< Entry > data = {
      { Entry{   1, "total",          { "n,total" }, {} } },
      { Entry{   2, "elastic",        { "z,z0" }, {} } },
      { Entry{   3, "non-elastic",    { "z,nonelas" }, {} } },
      { Entry{   4, "inelastic",      { "z,n", "n,n'", "z,n'" }, {} } },
      { Entry{   5, "anything",       {}, {} } },
      { Entry{  18, "fission[total]", { "n,fission", "z,fission" }, {} } },
      { Entry{  19, "fission",        { "fission1", "n,f", "z,f" }, {} } },
      { Entry{  20, "fission[n]",     { "fission2", "n,nf", "z,nf" }, {} } },
      { Entry{  21, "fission[2n]",    { "fission3", "n,2nf", "z,2nf" }, {} } },
      { Entry{  38, "fission[3n]",    { "fission4", "n,3nf" }, {} } },
      { Entry{  27, "absorption",     { "n,absorption" }, {} } },
      { Entry{ 101, "disappearance",  { "n,disappearance" }, {} } },
      { Entry{ 102, "capture",        { "n,g", "n,gamma", "z,g", "z,gamma" }, { g } } },
      { Entry{  11, "2nd",            { "z,2nd", "n,2nd" }, { n, n, d } } },
      { Entry{  16, "2n(t)",          { "z,2n", "n,2n" }, { n, n } } },
      { Entry{  17, "3n",             { "z,3n", "n,3n" }, { n, n, n } } },
      { Entry{  22, "na",             { "z,na", "n,na" }, { n, a } } },
      { Entry{  23, "n3a",            { "z,n3a", "n,n3a" }, { n, a, a, a } } },
      { Entry{  24, "2na",            { "z,2na", "n,2na" }, { n, n, a } } },
      { Entry{  25, "3na",            { "z,3na", "n,3na" }, { n, n, n, a } } },
      { Entry{  28, "np",             { "z,np", "n,np" }, { n, p } } },
      { Entry{  29, "n2a",            { "z,n2a", "n,n2a" }, { n, a, a } } },
      { Entry{  30, "2n2a",           { "z,2n2a", "n,2n2a" }, { n, n, a, a } } },
      { Entry{  32, "nd",             { "z,nd", "n,nd" }, { n, d } } },
      { Entry{  33, "nt",             { "z,nt", "n,nt" }, { n, t } } },
      { Entry{  34, "nh",             { "z,nh", "n,n3he", "n,nh", "n,nhe3", "z,n3he", "z,nhe3" }, { n, h } } },
      { Entry{  35, "nd2a",           { "z,nd2a", "n,nd2a" }, { n, d, a, a } } },
      { Entry{  36, "nt2a",           { "z,nt2a", "n,nt2a" }, { n, t, a, a } } },
      { Entry{  37, "4n",             { "z,4n", "n,4n" }, { n, n, n, n } } },
      { Entry{  41, "2np",            { "z,2np", "n,2np" }, { n, n, p } } },
      { Entry{  42, "3np",            { "z,3np", "n,3np" }, { n, n, n, p } } },
      { Entry{  44, "n2p",            { "z,n2p", "n,n2p" }, { n, p, p } } },
      { Entry{  45, "npa",            { "z,npa", "n,npa" }, { n, p, a } } },
      { Entry{  50, "n(0)",           { "z,n0", "y,n0" }, { n } } },
      { Entry{  51, "n(1)",           { "z,n1", "n,n'(1)", "n,n1", "z,n'(1)" }, { n }, 1 } },
      { Entry{  52, "n(2)",           { "z,n2", "n,n'(2)", "n,n2", "z,n'(2)" }, { n }, 2 } },
      { Entry{  53, "n(3)",           { "z,n3", "n,n'(3)", "n,n3", "z,n'(3)" }, { n }, 3 } },
      { Entry{  54, "n(4)",           { "z,n4", "n,n'(4)", "n,n4", "z,n'(4)" }, { n }, 4 } },
      { Entry{  55, "n(5)",           { "z,n5", "n,n'(5)", "n,n5", "z,n'(5)" }, { n }, 5 } },
      { Entry{  56, "n(6)",           { "z,n6", "n,n'(6)", "n,n6", "z,n'(6)" }, { n }, 6 } },
      { Entry{  57, "n(7)",           { "z,n7", "n,n'(7)", "n,n7", "z,n'(7)" }, { n }, 7 } },
      { Entry{  58, "n(8)",           { "z,n8", "n,n'(8)", "n,n8", "z,n'(8)" }, { n }, 8 } },
      { Entry{  59, "n(9)",           { "z,n9", "n,n'(9)", "n,n9", "z,n'(9)" }, { n }, 9 } },
      { Entry{  60, "n(10)",          { "z,n10", "n,n'(10)", "n,n10", "z,n'(10)" }, { n }, 10 } },
      { Entry{  61, "n(11)",          { "z,n11", "n,n'(11)", "n,n11", "z,n'(11)" }, { n }, 11 } },
      { Entry{  62, "n(12)",          { "z,n12", "n,n'(12)", "n,n12", "z,n'(12)" }, { n }, 12 } },
      { Entry{  63, "n(13)",          { "z,n13", "n,n'(13)", "n,n13", "z,n'(13)" }, { n }, 13 } },
      { Entry{  64, "n(14)",          { "z,n14", "n,n'(14)", "n,n14", "z,n'(14)" }, { n }, 14 } },
      { Entry{  65, "n(15)",          { "z,n15", "n,n'(15)", "n,n15", "z,n'(15)" }, { n }, 15 } },
      { Entry{  66, "n(16)",          { "z,n16", "n,n'(16)", "n,n16", "z,n'(16)" }, { n }, 16 } },
      { Entry{  67, "n(17)",          { "z,n17", "n,n'(17)", "n,n17", "z,n'(17)" }, { n }, 17 } },
      { Entry{  68, "n(18)",          { "z,n18", "n,n'(18)", "n,n18", "z,n'(18)" }, { n }, 18 } },
      { Entry{  69, "n(19)",          { "z,n19", "n,n'(19)", "n,n19", "z,n'(19)" }, { n }, 19 } },
      { Entry{  70, "n(20)",          { "z,n20", "n,n'(20)", "n,n20", "z,n'(20)" }, { n }, 20 } },
      { Entry{  71, "n(21)",          { "z,n21", "n,n'(21)", "n,n21", "z,n'(21)" }, { n }, 21 } },
      { Entry{  72, "n(22)",          { "z,n22", "n,n'(22)", "n,n22", "z,n'(22)" }, { n }, 22 } },
      { Entry{  73, "n(23)",          { "z,n23", "n,n'(23)", "n,n23", "z,n'(23)" }, { n }, 23 } },
      { Entry{  74, "n(24)",          { "z,n24", "n,n'(24)", "n,n24", "z,n'(24)" }, { n }, 24 } },
      { Entry{  75, "n(25)",          { "z,n25", "n,n'(25)", "n,n25", "z,n'(25)" }, { n }, 25 } },
      { Entry{  76, "n(26)",          { "z,n26", "n,n'(26)", "n,n26", "z,n'(26)" }, { n }, 26 } },
      { Entry{  77, "n(27)",          { "z,n27", "n,n'(27)", "n,n27", "z,n'(27)" }, { n }, 27 } },
      { Entry{  78, "n(28)",          { "z,n28", "n,n'(28)", "n,n28", "z,n'(28)" }, { n }, 28 } },
      { Entry{  79, "n(29)",          { "z,n29", "n,n'(29)", "n,n29", "z,n'(29)" }, { n }, 29 } },
      { Entry{  80, "n(30)",          { "z,n30", "n,n'(30)", "n,n30", "z,n'(30)" }, { n }, 30 } },
      { Entry{  81, "n(31)",          { "z,n31", "n,n'(31)", "n,n31", "z,n'(31)" }, { n }, 31 } },
      { Entry{  82, "n(32)",          { "z,n32", "n,n'(32)", "n,n32", "z,n'(32)" }, { n }, 32 } },
      { Entry{  83, "n(33)",          { "z,n33", "n,n'(33)", "n,n33", "z,n'(33)" }, { n }, 33 } },
      { Entry{  84, "n(34)",          { "z,n34", "n,n'(34)", "n,n34", "z,n'(34)" }, { n }, 34 } },
      { Entry{  85, "n(35)",          { "z,n35", "n,n'(35)", "n,n35", "z,n'(35)" }, { n }, 35 } },
      { Entry{  86, "n(36)",          { "z,n36", "n,n'(36)", "n,n36", "z,n'(36)" }, { n }, 36 } },
      { Entry{  87, "n(37)",          { "z,n37", "n,n'(37)", "n,n37", "z,n'(37)" }, { n }, 37 } },
      { Entry{  88, "n(38)",          { "z,n38", "n,n'(38)", "n,n38", "z,n'(38)" }, { n }, 38 } },
      { Entry{  89, "n(39)",          { "z,n39", "n,n'(39)", "n,n39", "z,n'(39)" }, { n }, 39 } },
      { Entry{  90, "n(40)",          { "z,n40", "n,n'(40)", "n,n40", "z,n'(40)" }, { n }, 40 } },
      { Entry{  91, "n(c)",           { "z,nc", "n,n'(c)", "n,nc", "z,n'(c)" }, { n }, continuum } },
      { Entry{ 103, "p(t)",           { "z,p", "n,p", "n,proton", "z,proton" }, { p } } },
      { Entry{ 104, "d(t)",           { "z,d", "n,d", "n,deuteron", "z,deuteron" }, { d } } },
      { Entry{ 105, "t(t)",           { "z,t", "n,t", "n,triton", "z,triton" }, { t } } },
      { Entry{ 106, "h(t)",           { "z,h", "n,3he", "n,h", "n,he3", "n,helion", "z,3he", "z,he3", "z,helion" }, { h } } },
      { Entry{ 107, "a(t)",           { "z,a", "n,a", "n,alpha", "z,alpha" }, { a } } },
      { Entry{ 108, "2a",             { "z,2a", "n,2a" }, { a, a } } },
      { Entry{ 109, "3a",             { "z,3a", "n,3a" }, { a, a, a } } },
      { Entry{ 111, "2p",             { "z,2p", "n,2p" }, { p, p } } },
      { Entry{ 112, "pa",             { "z,pa", "n,pa" }, { p, a } } },
      { Entry{ 113, "t2a",            { "z,t2a", "n,t2a" }, { t, a, a } } },
      { Entry{ 114, "d2a",            { "z,d2a", "n,d2a" }, { d, a, a } } },
      { Entry{ 115, "pd",             { "z,pd", "n,pd" }, { p, d } } },
      { Entry{ 116, "pt",             { "z,pt", "n,pt" }, { p, t } } },
      { Entry{ 117, "da",             { "z,da", "n,da" }, { d, a } } },
      { Entry{ 152, "5n",             { "z,5n", "n,5n" }, { n, n, n, n, n } } },
      { Entry{ 153, "6n",             { "z,6n", "n,6n" }, { n, n, n, n, n, n } } },
      { Entry{ 154, "2nt",            { "z,2nt", "n,2nt" }, { n, n, t } } },
      { Entry{ 155, "ta",             { "z,ta", "n,ta" }, { t, a } } },
      { Entry{ 156, "4np",            { "z,4np", "n,4np" }, { n, n, n, n, p } } },
      { Entry{ 157, "3nd",            { "z,3nd", "n,3nd" }, { n, n, n, d } } },
      { Entry{ 158, "nda",            { "z,nda", "n,nda" }, { n, d, a } } },
      { Entry{ 159, "2npa",           { "z,2npa", "n,2npa" }, { n, n, p, a } } },
      { Entry{ 160, "7n",             { "z,7n", "n,7n" }, { n, n, n, n, n, n, n } } },
      { Entry{ 161, "8n",             { "z,8n", "n,8n" }, { n, n, n, n, n, n, n, n } } },
      { Entry{ 162, "5np",            { "z,5np", "n,5np" }, { n, n, n, n, n, p } } },
      { Entry{ 163, "6np",            { "z,6np", "n,6np" }, { n, n, n, n, n, n, p } } },
      { Entry{ 164, "7np",            { "z,7np", "n,7np" }, { n, n, n, n, n, n, n, p } } },
      { Entry{ 165, "4na",            { "z,4na", "n,4na" }, { n, n, n, n, a } } },
      { Entry{ 166, "5na",            { "z,5na", "n,5na" }, { n, n, n, n, n, a } } },
      { Entry{ 167, "6na",            { "z,6na", "n,6na" }, { n, n, n, n, n, n, a } } },
      { Entry{ 168, "7na",            { "z,7na", "n,7na" }, { n, n, n, n, n, n, n, a } } },
      { Entry{ 169, "4nd",            { "z,4nd", "n,4nd" }, { n, n, n, n, d } } },
      { Entry{ 170, "5nd",            { "z,5nd", "n,5nd" }, { n, n, n, n, n, d } } },
      { Entry{ 171, "6nd",            { "z,6nd", "n,6nd" }, { n, n, n, n, n, n, d } } },
      { Entry{ 172, "3nt",            { "z,3nt", "n,3nt" }, { n, n, n, t } } },
      { Entry{ 173, "4nt",            { "z,4nt", "n,4nt" }, { n, n, n, n, t } } },
      { Entry{ 174, "5nt",            { "z,5nt", "n,5nt" }, { n, n, n, n, n, t } } },
      { Entry{ 175, "6nt",            { "z,6nt", "n,6nt" }, { n, n, n, n, n, n, t } } },
      { Entry{ 176, "2nh",            { "z,2nh", "n,2n3he", "n,2nh", "n,2nhe3", "z,2n3he", "z,2nhe3" }, { n, n, h } } },
      { Entry{ 177, "3nh",            { "z,3nh", "n,3n3he", "n,3nh", "n,3nhe3", "z,3n3he", "z,3nhe3" }, { n, n, n, h } } },
      { Entry{ 178, "4nh",            { "z,4nh", "n,4n3he", "n,4nh", "n,4nhe3", "z,4n3he", "z,4nhe3" }, { n, n, n, n, h } } },
      { Entry{ 179, "3n2p",           { "z,3n2p", "n,3n2p" }, { n, n, n, p, p } } },
      { Entry{ 180, "3n2a",           { "z,3n2a", "n,3n2a" }, { n, n, n, a, a } } },
      { Entry{ 181, "3npa",           { "z,3npa", "n,3npa" }, { n, n, n, p, a } } },
      { Entry{ 182, "dt",             { "z,dt", "n,dt" }, { d, t } } },
      { Entry{ 183, "npd",            { "z,npd", "n,npd" }, { n, p, d } } },
      { Entry{ 184, "npt",            { "z,npt", "n,npt" }, { n, p, t } } },
      { Entry{ 185, "ndt",            { "z,ndt", "n,ndt" }, { n, d, t } } },
      { Entry{ 186, "nph",            { "z,nph", "n,np3he", "n,nph", "n,nphe3", "z,np3he", "z,nphe3" }, { n, p, h } } },
      { Entry{ 187, "ndh",            { "z,ndh", "n,nd3he", "n,ndh", "n,ndhe3", "z,nd3he", "z,ndhe3" }, { n, d, h } } },
      { Entry{ 188, "nth",            { "z,nth", "n,nt3he", "n,nth", "n,nthe3", "z,nt3he", "z,nthe3" }, { n, t, h } } },
      { Entry{ 189, "nta",            { "z,nta", "n,nta" }, { n, t, a } } },
      { Entry{ 190, "2n2p",           { "z,2n2p", "n,2n2p" }, { n, n, p, p } } },
      { Entry{ 191, "ph",             { "z,ph", "n,p3he", "n,ph", "n,phe3", "z,p3he", "z,phe3" }, { p, h } } },
      { Entry{ 192, "dh",             { "z,dh", "n,d3he", "n,dh", "n,dhe3", "z,d3he", "z,dhe3" }, { d, h } } },
      { Entry{ 193, "ha",             { "z,ha", "n,3hea", "n,ha", "n,he3a", "z,3hea", "z,he3a" }, { h, a } } },
      { Entry{ 194, "4n2p",           { "z,4n2p", "n,4n2p" }, { n, n, n, n, p, p } } },
      { Entry{ 195, "4n2a",           { "z,4n2a", "n,4n2a" }, { n, n, n, n, a, a } } },
      { Entry{ 196, "4npa",           { "z,4npa", "n,4npa" }, { n, n, n, n, p, a } } },
      { Entry{ 197, "3p",             { "z,3p", "n,3p" }, { p, p, p } } },
      { Entry{ 198, "n3p",            { "z,n3p", "n,n3p" }, { n, p, p, p } } },
      { Entry{ 199, "3n2pa",          { "z,3n2pa", "n,3n2pa" }, { n, n, n, p, p, a } } },
      { Entry{ 200, "5n2p",           { "z,5n2p", "n,5n2p" }, { n, n, n, n, n, p, p } } },
      { Entry{ 600, "p(0)",           { "z,p0", "n,p0" }, { p }, 0 } },
      { Entry{ 601, "p(1)",           { "z,p1", "n,p1" }, { p }, 1 } },
      { Entry{ 602, "p(2)",           { "z,p2", "n,p2" }, { p }, 2 } },
      { Entry{ 603, "p(3)",           { "z,p3", "n,p3" }, { p }, 3 } },
      { Entry{ 604, "p(4)",           { "z,p4", "n,p4" }, { p }, 4 } },
      { Entry{ 605, "p(5)",           { "z,p5", "n,p5" }, { p }, 5 } },
      { Entry{ 606, "p(6)",           { "z,p6", "n,p6" }, { p }, 6 } },
      { Entry{ 607, "p(7)",           { "z,p7", "n,p7" }, { p }, 7 } },
      { Entry{ 608, "p(8)",           { "z,p8", "n,p8" }, { p }, 8 } },
      { Entry{ 609, "p(9)",           { "z,p9", "n,p9" }, { p }, 9 } },
      { Entry{ 610, "p(10)",          { "z,p10", "n,p10" }, { p }, 10 } },
      { Entry{ 611, "p(11)",          { "z,p11", "n,p11" }, { p }, 11 } },
      { Entry{ 612, "p(12)",          { "z,p12", "n,p12" }, { p }, 12 } },
      { Entry{ 613, "p(13)",          { "z,p13", "n,p13" }, { p }, 13 } },
      { Entry{ 614, "p(14)",          { "z,p14", "n,p14" }, { p }, 14 } },
      { Entry{ 615, "p(15)",          { "z,p15", "n,p15" }, { p }, 15 } },
      { Entry{ 616, "p(16)",          { "z,p16", "n,p16" }, { p }, 16 } },
      { Entry{ 617, "p(17)",          { "z,p17", "n,p17" }, { p }, 17 } },
      { Entry{ 618, "p(18)",          { "z,p18", "n,p18" }, { p }, 18 } },
      { Entry{ 619, "p(19)",          { "z,p19", "n,p19" }, { p }, 19 } },
      { Entry{ 620, "p(20)",          { "z,p20", "n,p20" }, { p }, 20 } },
      { Entry{ 621, "p(21)",          { "z,p21", "n,p21" }, { p }, 21 } },
      { Entry{ 622, "p(22)",          { "z,p22", "n,p22" }, { p }, 22 } },
      { Entry{ 623, "p(23)",          { "z,p23", "n,p23" }, { p }, 23 } },
      { Entry{ 624, "p(24)",          { "z,p24", "n,p24" }, { p }, 24 } },
      { Entry{ 625, "p(25)",          { "z,p25", "n,p25" }, { p }, 25 } },
      { Entry{ 626, "p(26)",          { "z,p26", "n,p26" }, { p }, 26 } },
      { Entry{ 627, "p(27)",          { "z,p27", "n,p27" }, { p }, 27 } },
      { Entry{ 628, "p(28)",          { "z,p28", "n,p28" }, { p }, 28 } },
      { Entry{ 629, "p(29)",          { "z,p29", "n,p29" }, { p }, 29 } },
      { Entry{ 630, "p(30)",          { "z,p30", "n,p30" }, { p }, 30 } },
      { Entry{ 631, "p(31)",          { "z,p31", "n,p31" }, { p }, 31 } },
      { Entry{ 632, "p(32)",          { "z,p32", "n,p32" }, { p }, 32 } },
      { Entry{ 633, "p(33)",          { "z,p33", "n,p33" }, { p }, 33 } },
      { Entry{ 634, "p(34)",          { "z,p34", "n,p34" }, { p }, 34 } },
      { Entry{ 635, "p(35)",          { "z,p35", "n,p35" }, { p }, 35 } },
      { Entry{ 636, "p(36)",          { "z,p36", "n,p36" }, { p }, 36 } },
      { Entry{ 637, "p(37)",          { "z,p37", "n,p37" }, { p }, 37 } },
      { Entry{ 638, "p(38)",          { "z,p38", "n,p38" }, { p }, 38 } },
      { Entry{ 639, "p(39)",          { "z,p39", "n,p39" }, { p }, 39 } },
      { Entry{ 640, "p(40)",          { "z,p40", "n,p40" }, { p }, 40 } },
      { Entry{ 641, "p(41)",          { "z,p41", "n,p41" }, { p }, 41 } },
      { Entry{ 642, "p(42)",          { "z,p42", "n,p42" }, { p }, 42 } },
      { Entry{ 643, "p(43)",          { "z,p43", "n,p43" }, { p }, 43 } },
      { Entry{ 644, "p(44)",          { "z,p44", "n,p44" }, { p }, 44 } },
      { Entry{ 645, "p(45)",          { "z,p45", "n,p45" }, { p }, 45 } },
      { Entry{ 646, "p(46)",          { "z,p46", "n,p46" }, { p }, 46 } },
      { Entry{ 647, "p(47)",          { "z,p47", "n,p47" }, { p }, 47 } },
      { Entry{ 648, "p(48)",          { "z,p48", "n,p48" }, { p }, 48 } },
      { Entry{ 649, "p(c)",           { "z,pc", "n,pc" }, { p }, continuum } },
      { Entry{ 650, "d(0)",           { "z,d0", "n,d0" }, { d }, 0 } },
      { Entry{ 651, "d(1)",           { "z,d1", "n,d1" }, { d }, 1 } },
      { Entry{ 652, "d(2)",           { "z,d2", "n,d2" }, { d }, 2 } },
      { Entry{ 653, "d(3)",           { "z,d3", "n,d3" }, { d }, 3 } },
      { Entry{ 654, "d(4)",           { "z,d4", "n,d4" }, { d }, 4 } },
      { Entry{ 655, "d(5)",           { "z,d5", "n,d5" }, { d }, 5 } },
      { Entry{ 656, "d(6)",           { "z,d6", "n,d6" }, { d }, 6 } },
      { Entry{ 657, "d(7)",           { "z,d7", "n,d7" }, { d }, 7 } },
      { Entry{ 658, "d(8)",           { "z,d8", "n,d8" }, { d }, 8 } },
      { Entry{ 659, "d(9)",           { "z,d9", "n,d9" }, { d }, 9 } },
      { Entry{ 660, "d(10)",          { "z,d10", "n,d10" }, { d }, 10 } },
      { Entry{ 661, "d(11)",          { "z,d11", "n,d11" }, { d }, 11 } },
      { Entry{ 662, "d(12)",          { "z,d12", "n,d12" }, { d }, 12 } },
      { Entry{ 663, "d(13)",          { "z,d13", "n,d13" }, { d }, 13 } },
      { Entry{ 664, "d(14)",          { "z,d14", "n,d14" }, { d }, 14 } },
      { Entry{ 665, "d(15)",          { "z,d15", "n,d15" }, { d }, 15 } },
      { Entry{ 666, "d(16)",          { "z,d16", "n,d16" }, { d }, 16 } },
      { Entry{ 667, "d(17)",          { "z,d17", "n,d17" }, { d }, 17 } },
      { Entry{ 668, "d(18)",          { "z,d18", "n,d18" }, { d }, 18 } },
      { Entry{ 669, "d(19)",          { "z,d19", "n,d19" }, { d }, 19 } },
      { Entry{ 670, "d(20)",          { "z,d20", "n,d20" }, { d }, 20 } },
      { Entry{ 671, "d(21)",          { "z,d21", "n,d21" }, { d }, 21 } },
      { Entry{ 672, "d(22)",          { "z,d22", "n,d22" }, { d }, 22 } },
      { Entry{ 673, "d(23)",          { "z,d23", "n,d23" }, { d }, 23 } },
      { Entry{ 674, "d(24)",          { "z,d24", "n,d24" }, { d }, 24 } },
      { Entry{ 675, "d(25)",          { "z,d25", "n,d25" }, { d }, 25 } },
      { Entry{ 676, "d(26)",          { "z,d26", "n,d26" }, { d }, 26 } },
      { Entry{ 677, "d(27)",          { "z,d27", "n,d27" }, { d }, 27 } },
      { Entry{ 678, "d(28)",          { "z,d28", "n,d28" }, { d }, 28 } },
      { Entry{ 679, "d(29)",          { "z,d29", "n,d29" }, { d }, 29 } },
      { Entry{ 680, "d(30)",          { "z,d30", "n,d30" }, { d }, 30 } },
      { Entry{ 681, "d(31)",          { "z,d31", "n,d31" }, { d }, 31 } },
      { Entry{ 682, "d(32)",          { "z,d32", "n,d32" }, { d }, 32 } },
      { Entry{ 683, "d(33)",          { "z,d33", "n,d33" }, { d }, 33 } },
      { Entry{ 684, "d(34)",          { "z,d34", "n,d34" }, { d }, 34 } },
      { Entry{ 685, "d(35)",          { "z,d35", "n,d35" }, { d }, 35 } },
      { Entry{ 686, "d(36)",          { "z,d36", "n,d36" }, { d }, 36 } },
      { Entry{ 687, "d(37)",          { "z,d37", "n,d37" }, { d }, 37 } },
      { Entry{ 688, "d(38)",          { "z,d38", "n,d38" }, { d }, 38 } },
      { Entry{ 689, "d(39)",          { "z,d39", "n,d39" }, { d }, 39 } },
      { Entry{ 690, "d(40)",          { "z,d40", "n,d40" }, { d }, 40 } },
      { Entry{ 691, "d(41)",          { "z,d41", "n,d41" }, { d }, 41 } },
      { Entry{ 692, "d(42)",          { "z,d42", "n,d42" }, { d }, 42 } },
      { Entry{ 693, "d(43)",          { "z,d43", "n,d43" }, { d }, 43 } },
      { Entry{ 694, "d(44)",          { "z,d44", "n,d44" }, { d }, 44 } },
      { Entry{ 695, "d(45)",          { "z,d45", "n,d45" }, { d }, 45 } },
      { Entry{ 696, "d(46)",          { "z,d46", "n,d46" }, { d }, 46 } },
      { Entry{ 697, "d(47)",          { "z,d47", "n,d47" }, { d }, 47 } },
      { Entry{ 698, "d(48)",          { "z,d48", "n,d48" }, { d }, 48 } },
      { Entry{ 699, "d(c)",           { "z,dc", "n,dc" }, { d }, continuum } },
      { Entry{ 700, "t(0)",           { "z,t0", "n,t0" }, { t }, 0 } },
      { Entry{ 701, "t(1)",           { "z,t1", "n,t1" }, { t }, 1 } },
      { Entry{ 702, "t(2)",           { "z,t2", "n,t2" }, { t }, 2 } },
      { Entry{ 703, "t(3)",           { "z,t3", "n,t3" }, { t }, 3 } },
      { Entry{ 704, "t(4)",           { "z,t4", "n,t4" }, { t }, 4 } },
      { Entry{ 705, "t(5)",           { "z,t5", "n,t5" }, { t }, 5 } },
      { Entry{ 706, "t(6)",           { "z,t6", "n,t6" }, { t }, 6 } },
      { Entry{ 707, "t(7)",           { "z,t7", "n,t7" }, { t }, 7 } },
      { Entry{ 708, "t(8)",           { "z,t8", "n,t8" }, { t }, 8 } },
      { Entry{ 709, "t(9)",           { "z,t9", "n,t9" }, { t }, 9 } },
      { Entry{ 710, "t(10)",          { "z,t10", "n,t10" }, { t }, 10 } },
      { Entry{ 711, "t(11)",          { "z,t11", "n,t11" }, { t }, 11 } },
      { Entry{ 712, "t(12)",          { "z,t12", "n,t12" }, { t }, 12 } },
      { Entry{ 713, "t(13)",          { "z,t13", "n,t13" }, { t }, 13 } },
      { Entry{ 714, "t(14)",          { "z,t14", "n,t14" }, { t }, 14 } },
      { Entry{ 715, "t(15)",          { "z,t15", "n,t15" }, { t }, 15 } },
      { Entry{ 716, "t(16)",          { "z,t16", "n,t16" }, { t }, 16 } },
      { Entry{ 717, "t(17)",          { "z,t17", "n,t17" }, { t }, 17 } },
      { Entry{ 718, "t(18)",          { "z,t18", "n,t18" }, { t }, 18 } },
      { Entry{ 719, "t(19)",          { "z,t19", "n,t19" }, { t }, 19 } },
      { Entry{ 720, "t(20)",          { "z,t20", "n,t20" }, { t }, 20 } },
      { Entry{ 721, "t(21)",          { "z,t21", "n,t21" }, { t }, 21 } },
      { Entry{ 722, "t(22)",          { "z,t22", "n,t22" }, { t }, 22 } },
      { Entry{ 723, "t(23)",          { "z,t23", "n,t23" }, { t }, 23 } },
      { Entry{ 724, "t(24)",          { "z,t24", "n,t24" }, { t }, 24 } },
      { Entry{ 725, "t(25)",          { "z,t25", "n,t25" }, { t }, 25 } },
      { Entry{ 726, "t(26)",          { "z,t26", "n,t26" }, { t }, 26 } },
      { Entry{ 727, "t(27)",          { "z,t27", "n,t27" }, { t }, 27 } },
      { Entry{ 728, "t(28)",          { "z,t28", "n,t28" }, { t }, 28 } },
      { Entry{ 729, "t(29)",          { "z,t29", "n,t29" }, { t }, 29 } },
      { Entry{ 730, "t(30)",          { "z,t30", "n,t30" }, { t }, 30 } },
      { Entry{ 731, "t(31)",          { "z,t31", "n,t31" }, { t }, 31 } },
      { Entry{ 732, "t(32)",          { "z,t32", "n,t32" }, { t }, 32 } },
      { Entry{ 733, "t(33)",          { "z,t33", "n,t33" }, { t }, 33 } },
      { Entry{ 734, "t(34)",          { "z,t34", "n,t34" }, { t }, 34 } },
      { Entry{ 735, "t(35)",          { "z,t35", "n,t35" }, { t }, 35 } },
      { Entry{ 736, "t(36)",          { "z,t36", "n,t36" }, { t }, 36 } },
      { Entry{ 737, "t(37)",          { "z,t37", "n,t37" }, { t }, 37 } },
      { Entry{ 738, "t(38)",          { "z,t38", "n,t38" }, { t }, 38 } },
      { Entry{ 739, "t(39)",          { "z,t39", "n,t39" }, { t }, 39 } },
      { Entry{ 740, "t(40)",          { "z,t40", "n,t40" }, { t }, 40 } },
      { Entry{ 741, "t(41)",          { "z,t41", "n,t41" }, { t }, 41 } },
      { Entry{ 742, "t(42)",          { "z,t42", "n,t42" }, { t }, 42 } },
      { Entry{ 743, "t(43)",          { "z,t43", "n,t43" }, { t }, 43 } },
      { Entry{ 744, "t(44)",          { "z,t44", "n,t44" }, { t }, 44 } },
      { Entry{ 745, "t(45)",          { "z,t45", "n,t45" }, { t }, 45 } },
      { Entry{ 746, "t(46)",          { "z,t46", "n,t46" }, { t }, 46 } },
      { Entry{ 747, "t(47)",          { "z,t47", "n,t47" }, { t }, 47 } },
      { Entry{ 748, "t(48)",          { "z,t48", "n,t48" }, { t }, 48 } },
      { Entry{ 749, "t(c)",           { "z,tc", "n,tc" }, { t }, continuum } },
      { Entry{ 750, "h(0)",           { "z,h0", "n,h0" }, { h }, 0 } },
      { Entry{ 751, "h(1)",           { "z,h1", "n,h1" }, { h }, 1 } },
      { Entry{ 752, "h(2)",           { "z,h2", "n,h2" }, { h }, 2 } },
      { Entry{ 753, "h(3)",           { "z,h3", "n,h3" }, { h }, 3 } },
      { Entry{ 754, "h(4)",           { "z,h4", "n,h4" }, { h }, 4 } },
      { Entry{ 755, "h(5)",           { "z,h5", "n,h5" }, { h }, 5 } },
      { Entry{ 756, "h(6)",           { "z,h6", "n,h6" }, { h }, 6 } },
      { Entry{ 757, "h(7)",           { "z,h7", "n,h7" }, { h }, 7 } },
      { Entry{ 758, "h(8)",           { "z,h8", "n,h8" }, { h }, 8 } },
      { Entry{ 759, "h(9)",           { "z,h9", "n,h9" }, { h }, 9 } },
      { Entry{ 760, "h(10)",          { "z,h10", "n,h10" }, { h }, 10 } },
      { Entry{ 761, "h(11)",          { "z,h11", "n,h11" }, { h }, 11 } },
      { Entry{ 762, "h(12)",          { "z,h12", "n,h12" }, { h }, 12 } },
      { Entry{ 763, "h(13)",          { "z,h13", "n,h13" }, { h }, 13 } },
      { Entry{ 764, "h(14)",          { "z,h14", "n,h14" }, { h }, 14 } },
      { Entry{ 765, "h(15)",          { "z,h15", "n,h15" }, { h }, 15 } },
      { Entry{ 766, "h(16)",          { "z,h16", "n,h16" }, { h }, 16 } },
      { Entry{ 767, "h(17)",          { "z,h17", "n,h17" }, { h }, 17 } },
      { Entry{ 768, "h(18)",          { "z,h18", "n,h18" }, { h }, 18 } },
      { Entry{ 769, "h(19)",          { "z,h19", "n,h19" }, { h }, 19 } },
      { Entry{ 770, "h(20)",          { "z,h20", "n,h20" }, { h }, 20 } },
      { Entry{ 771, "h(21)",          { "z,h21", "n,h21" }, { h }, 21 } },
      { Entry{ 772, "h(22)",          { "z,h22", "n,h22" }, { h }, 22 } },
      { Entry{ 773, "h(23)",          { "z,h23", "n,h23" }, { h }, 23 } },
      { Entry{ 774, "h(24)",          { "z,h24", "n,h24" }, { h }, 24 } },
      { Entry{ 775, "h(25)",          { "z,h25", "n,h25" }, { h }, 25 } },
      { Entry{ 776, "h(26)",          { "z,h26", "n,h26" }, { h }, 26 } },
      { Entry{ 777, "h(27)",          { "z,h27", "n,h27" }, { h }, 27 } },
      { Entry{ 778, "h(28)",          { "z,h28", "n,h28" }, { h }, 28 } },
      { Entry{ 779, "h(29)",          { "z,h29", "n,h29" }, { h }, 29 } },
      { Entry{ 780, "h(30)",          { "z,h30", "n,h30" }, { h }, 30 } },
      { Entry{ 781, "h(31)",          { "z,h31", "n,h31" }, { h }, 31 } },
      { Entry{ 782, "h(32)",          { "z,h32", "n,h32" }, { h }, 32 } },
      { Entry{ 783, "h(33)",          { "z,h33", "n,h33" }, { h }, 33 } },
      { Entry{ 784, "h(34)",          { "z,h34", "n,h34" }, { h }, 34 } },
      { Entry{ 785, "h(35)",          { "z,h35", "n,h35" }, { h }, 35 } },
      { Entry{ 786, "h(36)",          { "z,h36", "n,h36" }, { h }, 36 } },
      { Entry{ 787, "h(37)",          { "z,h37", "n,h37" }, { h }, 37 } },
      { Entry{ 788, "h(38)",          { "z,h38", "n,h38" }, { h }, 38 } },
      { Entry{ 789, "h(39)",          { "z,h39", "n,h39" }, { h }, 39 } },
      { Entry{ 790, "h(40)",          { "z,h40", "n,h40" }, { h }, 40 } },
      { Entry{ 791, "h(41)",          { "z,h41", "n,h41" }, { h }, 41 } },
      { Entry{ 792, "h(42)",          { "z,h42", "n,h42" }, { h }, 42 } },
      { Entry{ 793, "h(43)",          { "z,h43", "n,h43" }, { h }, 43 } },
      { Entry{ 794, "h(44)",          { "z,h44", "n,h44" }, { h }, 44 } },
      { Entry{ 795, "h(45)",          { "z,h45", "n,h45" }, { h }, 45 } },
      { Entry{ 796, "h(46)",          { "z,h46", "n,h46" }, { h }, 46 } },
      { Entry{ 797, "h(47)",          { "z,h47", "n,h47" }, { h }, 47 } },
      { Entry{ 798, "h(48)",          { "z,h48", "n,h48" }, { h }, 48 } },
      { Entry{ 799, "h(c)",           { "z,hc", "n,hc" }, { h }, continuum } },
      { Entry{ 800, "a(0)",           { "z,a0", "n,a0" }, { a }, 0 } },
      { Entry{ 801, "a(1)",           { "z,a1", "n,a1" }, { a }, 1 } },
      { Entry{ 802, "a(2)",           { "z,a2", "n,a2" }, { a }, 2 } },
      { Entry{ 803, "a(3)",           { "z,a3", "n,a3" }, { a }, 3 } },
      { Entry{ 804, "a(4)",           { "z,a4", "n,a4" }, { a }, 4 } },
      { Entry{ 805, "a(5)",           { "z,a5", "n,a5" }, { a }, 5 } },
      { Entry{ 806, "a(6)",           { "z,a6", "n,a6" }, { a }, 6 } },
      { Entry{ 807, "a(7)",           { "z,a7", "n,a7" }, { a }, 7 } },
      { Entry{ 808, "a(8)",           { "z,a8", "n,a8" }, { a }, 8 } },
      { Entry{ 809, "a(9)",           { "z,a9", "n,a9" }, { a }, 9 } },
      { Entry{ 810, "a(10)",          { "z,a10", "n,a10" }, { a }, 10 } },
      { Entry{ 811, "a(11)",          { "z,a11", "n,a11" }, { a }, 11 } },
      { Entry{ 812, "a(12)",          { "z,a12", "n,a12" }, { a }, 12 } },
      { Entry{ 813, "a(13)",          { "z,a13", "n,a13" }, { a }, 13 } },
      { Entry{ 814, "a(14)",          { "z,a14", "n,a14" }, { a }, 14 } },
      { Entry{ 815, "a(15)",          { "z,a15", "n,a15" }, { a }, 15 } },
      { Entry{ 816, "a(16)",          { "z,a16", "n,a16" }, { a }, 16 } },
      { Entry{ 817, "a(17)",          { "z,a17", "n,a17" }, { a }, 17 } },
      { Entry{ 818, "a(18)",          { "z,a18", "n,a18" }, { a }, 18 } },
      { Entry{ 819, "a(19)",          { "z,a19", "n,a19" }, { a }, 19 } },
      { Entry{ 820, "a(20)",          { "z,a20", "n,a20" }, { a }, 20 } },
      { Entry{ 821, "a(21)",          { "z,a21", "n,a21" }, { a }, 21 } },
      { Entry{ 822, "a(22)",          { "z,a22", "n,a22" }, { a }, 22 } },
      { Entry{ 823, "a(23)",          { "z,a23", "n,a23" }, { a }, 23 } },
      { Entry{ 824, "a(24)",          { "z,a24", "n,a24" }, { a }, 24 } },
      { Entry{ 825, "a(25)",          { "z,a25", "n,a25" }, { a }, 25 } },
      { Entry{ 826, "a(26)",          { "z,a26", "n,a26" }, { a }, 26 } },
      { Entry{ 827, "a(27)",          { "z,a27", "n,a27" }, { a }, 27 } },
      { Entry{ 828, "a(28)",          { "z,a28", "n,a28" }, { a }, 28 } },
      { Entry{ 829, "a(29)",          { "z,a29", "n,a29" }, { a }, 29 } },
      { Entry{ 830, "a(30)",          { "z,a30", "n,a30" }, { a }, 30 } },
      { Entry{ 831, "a(31)",          { "z,a31", "n,a31" }, { a }, 31 } },
      { Entry{ 832, "a(32)",          { "z,a32", "n,a32" }, { a }, 32 } },
      { Entry{ 833, "a(33)",          { "z,a33", "n,a33" }, { a }, 33 } },
      { Entry{ 834, "a(34)",          { "z,a34", "n,a34" }, { a }, 34 } },
      { Entry{ 835, "a(35)",          { "z,a35", "n,a35" }, { a }, 35 } },
      { Entry{ 836, "a(36)",          { "z,a36", "n,a36" }, { a }, 36 } },
      { Entry{ 837, "a(37)",          { "z,a37", "n,a37" }, { a }, 37 } },
      { Entry{ 838, "a(38)",          { "z,a38", "n,a38" }, { a }, 38 } },
      { Entry{ 839, "a(39)",          { "z,a39", "n,a39" }, { a }, 39 } },
      { Entry{ 840, "a(40)",          { "z,a40", "n,a40" }, { a }, 40 } },
      { Entry{ 841, "a(41)",          { "z,a41", "n,a41" }, { a }, 41 } },
      { Entry{ 842, "a(42)",          { "z,a42", "n,a42" }, { a }, 42 } },
      { Entry{ 843, "a(43)",          { "z,a43", "n,a43" }, { a }, 43 } },
      { Entry{ 844, "a(44)",          { "z,a44", "n,a44" }, { a }, 44 } },
      { Entry{ 845, "a(45)",          { "z,a45", "n,a45" }, { a }, 45 } },
      { Entry{ 846, "a(46)",          { "z,a46", "n,a46" }, { a }, 46 } },
      { Entry{ 847, "a(47)",          { "z,a47", "n,a47" }, { a }, 47 } },
      { Entry{ 848, "a(48)",          { "z,a48", "n,a48" }, { a }, 48 } },
      { Entry{ 849, "a(c)",           { "z,ac", "n,ac" }, { a }, continuum } },
      { Entry{ 875, "2n(0)",            { "z,2n0", "n,2n0" }, { n, n }, 0 } },
      { Entry{ 876, "2n(1)",            { "z,2n1", "n,2n1" }, { n, n }, 1 } },
      { Entry{ 877, "2n(2)",            { "z,2n2", "n,2n2" }, { n, n }, 2 } },
      { Entry{ 878, "2n(3)",            { "z,2n3", "n,2n3" }, { n, n }, 3 } },
      { Entry{ 879, "2n(4)",            { "z,2n4", "n,2n4" }, { n, n }, 4 } },
      { Entry{ 880, "2n(5)",            { "z,2n5", "n,2n5" }, { n, n }, 5 } },
      { Entry{ 881, "2n(6)",            { "z,2n6", "n,2n6" }, { n, n }, 6 } },
      { Entry{ 882, "2n(7)",            { "z,2n7", "n,2n7" }, { n, n }, 7 } },
      { Entry{ 883, "2n(8)",            { "z,2n8", "n,2n8" }, { n, n }, 8 } },
      { Entry{ 884, "2n(9)",            { "z,2n9", "n,2n9" }, { n, n }, 9 } },
      { Entry{ 885, "2n(10)",           { "z,2n10", "n,2n10" }, { n, n }, 10 } },
      { Entry{ 886, "2n(11)",           { "z,2n11", "n,2n11" }, { n, n }, 11 } },
      { Entry{ 887, "2n(12)",           { "z,2n12", "n,2n12" }, { n, n }, 12 } },
      { Entry{ 888, "2n(13)",           { "z,2n13", "n,2n13" }, { n, n }, 13 } },
      { Entry{ 889, "2n(14)",           { "z,2n14", "n,2n14" }, { n, n }, 14 } },
      { Entry{ 890, "2n(15)",           { "z,2n15", "n,2n15" }, { n, n }, 15 } },
      { Entry{ 891, "2n(c)",            { "z,2nc", "n,2nc" }, { n, n }, continuum } } };

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
