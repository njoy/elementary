#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/src/absorb.hpp"
#include "elementary/src/emit.hpp"
#include "elementary/src/resolve.hpp"
#include "elementary/src/join.hpp"
#include "elementary/src/split.hpp"
#include "elementary/src/fromEndfReactionNumber.hpp"
#include "elementary/src/toEndfReactionNumber.hpp"

// other includes
#include "elementary/FundamentalParticleID.hpp"
#include "elementary/IsotopeID.hpp"
#include "elementary/NucleusID.hpp"
#include "elementary/NuclideID.hpp"
#include "elementary/ParticleID.hpp"
#include "elementary/ReactionID.hpp"

// convenience typedefs
using namespace njoy::elementary;

#include "elementary/test/absorb.test.hpp"
#include "elementary/test/emit.test.hpp"
#include "elementary/test/resolve.test.hpp"
#include "elementary/test/join.test.hpp"
#include "elementary/test/split.test.hpp"
#include "elementary/test/fromEndfReactionNumber.test.hpp"
#include "elementary/test/toEndfReactionNumber.test.hpp"
