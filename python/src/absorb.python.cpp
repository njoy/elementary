// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <variant>

// local includes
#include "elementary/absorb.hpp"
#include "elementary/IsotopeID.hpp"
#include "elementary/FundamentalParticleID.hpp"
#include "elementary/NucleusID.hpp"
#include "elementary/NuclideID.hpp"
#include "elementary/ParticleID.hpp"

// namespace aliases
namespace python = pybind11;

template < typename Compound, typename Particle >
void wrapTemplateAbsorb( python::module& module ) {

  module.def(

    "absorb",
    &njoy::elementary::absorb< Compound, Particle >,
    python::arg( "compound" ), python::arg( "particle" ),
    "Return the isotope identifier when a compound absorbs a particle\n\n"
    "This function throws a ValueError if the particle cannot be absorbed.\n\n"
    "Arguments:\n"
    "    compound   the compound identifier (fundamental particle,\n"
    "               isotope, nucleus, nuclide or the general particle)\n"
    "    particle   the absorbed particle identifier (fundamental\n"
    "               particle, isotope, nucleus, nuclide or the general\n"
    "               particle)\n"
  );
}

void wrapAbsorb( python::module& module ) {

  using IsotopeID = njoy::elementary::IsotopeID;
  using FundamentalParticleID = njoy::elementary::FundamentalParticleID;
  using NucleusID = njoy::elementary::NucleusID;
  using NuclideID = njoy::elementary::NuclideID;
  using ParticleID = njoy::elementary::ParticleID;

  wrapTemplateAbsorb< IsotopeID, IsotopeID >( module );
  wrapTemplateAbsorb< IsotopeID, FundamentalParticleID >( module );
  wrapTemplateAbsorb< IsotopeID, NucleusID >( module );
  wrapTemplateAbsorb< IsotopeID, NuclideID >( module );
  wrapTemplateAbsorb< IsotopeID, ParticleID >( module );

  wrapTemplateAbsorb< FundamentalParticleID, IsotopeID >( module );
  wrapTemplateAbsorb< FundamentalParticleID, FundamentalParticleID >( module );
  wrapTemplateAbsorb< FundamentalParticleID, NucleusID >( module );
  wrapTemplateAbsorb< FundamentalParticleID, NuclideID >( module );
  wrapTemplateAbsorb< FundamentalParticleID, ParticleID >( module );

  wrapTemplateAbsorb< NucleusID, IsotopeID >( module );
  wrapTemplateAbsorb< NucleusID, FundamentalParticleID >( module );
  wrapTemplateAbsorb< NucleusID, NucleusID >( module );
  wrapTemplateAbsorb< NucleusID, NuclideID >( module );
  wrapTemplateAbsorb< NucleusID, ParticleID >( module );

  wrapTemplateAbsorb< NuclideID, IsotopeID >( module );
  wrapTemplateAbsorb< NuclideID, FundamentalParticleID >( module );
  wrapTemplateAbsorb< NuclideID, NucleusID >( module );
  wrapTemplateAbsorb< NuclideID, NuclideID >( module );
  wrapTemplateAbsorb< NuclideID, ParticleID >( module );

  wrapTemplateAbsorb< ParticleID, IsotopeID >( module );
  wrapTemplateAbsorb< ParticleID, FundamentalParticleID >( module );
  wrapTemplateAbsorb< ParticleID, NucleusID >( module );
  wrapTemplateAbsorb< ParticleID, NuclideID >( module );
  wrapTemplateAbsorb< ParticleID, ParticleID >( module );
}
