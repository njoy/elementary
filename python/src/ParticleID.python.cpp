// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <variant>

// local includes
#include "elementary/ParticleID.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

void wrapParticleID( python::module& module ) {

  // type aliases
  using FundamentalParticleID = njoy::elementary::FundamentalParticleID;
  using NucleusID = njoy::elementary::NucleusID;
  using NuclideID = njoy::elementary::NuclideID;
  using Component = njoy::elementary::ParticleID;
  using Variant = Component::IdentifierVariant;

  // create the component
  python::class_< Component > component(

    module,
    "ParticleID",
    "The particle identifier, either a fundamental particle, a nucleus\n"
    "or nuclide identifier"
  );

  // wrap the component
  component
  .def(

    python::init< Variant&& >(),
    python::arg( "identifier" ),
    "Initialise the ParticleID using a FundamentalParticleID, NucleusID or\n"
    "NuclideID\n\n"
    "This function throws a ValueError exception exception if invalid data\n"
    "is used.\n\n"
    "Arguments:\n"
    "    identifier    a fundamental particle, nucleus or nuclide identifier"
  )
  .def(

    python::init< const std::string& >(),
    python::arg( "string" ),
    "Initialise the ParticleID using a string\n\n"
    "This function throws a ValueError exception exception if invalid data\n"
    "is used.\n\n"
    "Arguments:\n"
    "    string    the string representation of the particle (case sensitive)"
  )
  .def_property_readonly(

    "is_fundamental_particle",
    &Component::isFundamentalParticle,
    "Return whether or not the particle is a fundamental particle"
  )
  .def_property_readonly(

    "is_nucleus",
    &Component::isNucleus,
    "Return whether or not the particle is a nucleus"
  )
  .def_property_readonly(

    "is_nuclide",
    &Component::isNuclide,
    "Return whether or not the particle is a nuclide"
  )
  .def_property_readonly(

    "symbol",
    &Component::symbol,
    "The particle symbol"
  )
  .def_property_readonly(

    "name",
    &Component::name,
    "The particle name"
  )
  .def_property_readonly(

    "za",
    &Component::za,
    "The particle za value"
  )
  .def_property_readonly(

    "level",
    &Component::level,
    "The particle level identifier"
  );

  // add standard definitions
  addStandardDefinitions< Component >( component );

  // add standard dictionary key definitions
  addStandardDictionaryKeyDefinitions< Component >( component );
}
