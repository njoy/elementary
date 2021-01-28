// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "elementary/FundamentalParticleID.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

void wrapFundamentalParticleID( python::module& module ) {

  // type aliases
  using Component = njoy::elementary::FundamentalParticleID;

  // create the component
  python::class_< Component > component(

    module,
    "FundamentalParticleID",
    "The element identifier, with associated element symbol and name"
    "The fundamental particle identifier, with associated symbol and\n"
    "name\n\n"
    "The following fundamental particles are recognised by this class:\n"
    "  - \"photon\" : \"g\", \"gamma\", \"x-ray\"\n"
    "  - \"n\" : \"neutron\"\n"
    "  - \"p\" : \"proton\""
  );

  // wrap the component
  component
  .def(

    python::init< const std::string& >(),
    python::arg( "string" ),
    "Initialise the FundamentalParticleID using a string\n\n"
    "This function throws a ValueError exception exception if the string is\n"
    "not a registered symbol, name or alternative.\n\n"
    "Arguments:\n"
    "    string    the symbol, name or alternative name of the particle\n"
    "              (case insensitive)"
  )
  .def_property_readonly(

    "za",
    &Component::za,
    "Return the fundamental particle za value"
  )
  .def_property_readonly(

    "symbol",
    &Component::symbol,
    "Return the fundamental particle symbol"
  )
  .def_property_readonly(

    "name",
    &Component::name,
    "Return the fundamental particle name"
  )
  .def(

    "__repr__",
    &Component::symbol,
    "Convenience function for printing the element identifier"
  );

  // add standard dictionary key definitions
  addStandardDictionaryKeyDefinitions< Component >( component );
}
