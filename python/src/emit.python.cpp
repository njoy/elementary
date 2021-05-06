// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <variant>

// local includes
#include "elementary/emit.hpp"
#include "elementary/IsotopeID.hpp"
#include "elementary/FundamentalParticleID.hpp"
#include "elementary/NucleusID.hpp"
#include "elementary/NuclideID.hpp"
#include "elementary/ParticleID.hpp"

// namespace aliases
namespace python = pybind11;

template < typename Compound, typename Particle >
void wrapTemplateEmit( python::module& module ) {

  module.def(

    "emit",
    &njoy::elementary::emit< Compound, Particle >,
    python::arg( "compound" ), python::arg( "particle" ),
    "Return the isotope identifier when a compound emits a particle\n\n"
    "This function throws a ValueError if the particle cannot be emitted.\n\n"
    "Arguments:\n"
    "    compound   the compound identifier (fundamental particle,\n"
    "               isotope, nucleus, nuclide or the general particle)\n"
    "    particle   the emitted particle identifier (fundamental\n"
    "               particle, isotope, nucleus, nuclide or the general\n"
    "               particle)\n"
  );
}

void wrapEmit( python::module& module ) {

  using IsotopeID = njoy::elementary::IsotopeID;
  using FundamentalParticleID = njoy::elementary::FundamentalParticleID;
  using NucleusID = njoy::elementary::NucleusID;
  using NuclideID = njoy::elementary::NuclideID;
  using ParticleID = njoy::elementary::ParticleID;

  wrapTemplateEmit< IsotopeID, IsotopeID >( module );
  wrapTemplateEmit< IsotopeID, FundamentalParticleID >( module );
  wrapTemplateEmit< IsotopeID, NucleusID >( module );
  wrapTemplateEmit< IsotopeID, NuclideID >( module );
  wrapTemplateEmit< IsotopeID, ParticleID >( module );

  wrapTemplateEmit< FundamentalParticleID, IsotopeID >( module );
  wrapTemplateEmit< FundamentalParticleID, FundamentalParticleID >( module );
  wrapTemplateEmit< FundamentalParticleID, NucleusID >( module );
  wrapTemplateEmit< FundamentalParticleID, NuclideID >( module );
  wrapTemplateEmit< FundamentalParticleID, ParticleID >( module );

  wrapTemplateEmit< NucleusID, IsotopeID >( module );
  wrapTemplateEmit< NucleusID, FundamentalParticleID >( module );
  wrapTemplateEmit< NucleusID, NucleusID >( module );
  wrapTemplateEmit< NucleusID, NuclideID >( module );
  wrapTemplateEmit< NucleusID, ParticleID >( module );

  wrapTemplateEmit< NuclideID, IsotopeID >( module );
  wrapTemplateEmit< NuclideID, FundamentalParticleID >( module );
  wrapTemplateEmit< NuclideID, NucleusID >( module );
  wrapTemplateEmit< NuclideID, NuclideID >( module );
  wrapTemplateEmit< NuclideID, ParticleID >( module );

  wrapTemplateEmit< ParticleID, IsotopeID >( module );
  wrapTemplateEmit< ParticleID, FundamentalParticleID >( module );
  wrapTemplateEmit< ParticleID, NucleusID >( module );
  wrapTemplateEmit< ParticleID, NuclideID >( module );
  wrapTemplateEmit< ParticleID, ParticleID >( module );
}
