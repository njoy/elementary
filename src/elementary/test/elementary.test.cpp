#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "elementary/absorb.hpp"
#include "elementary/emit.hpp"
#include "elementary/resolve.hpp"
#include "elementary/fromEndfReactionNumber.hpp"
#include "elementary/toEndfReactionNumber.hpp"

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
#include "elementary/test/fromEndfReactionNumber.test.hpp"
#include "elementary/test/toEndfReactionNumber.test.hpp"
