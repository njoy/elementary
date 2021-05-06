// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "elementary/SpecialDataID.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

void wrapSpecialDataID( python::module& module ) {

  // type aliases
  using ParticleID = njoy::elementary::ParticleID;
  using SpecialDataType = njoy::elementary::SpecialDataType;
  using Component = njoy::elementary::SpecialDataID;

  // create the component
  python::class_< Component > component(

    module,
    "SpecialDataID",
    "The identifier for special data\n\n"
    "The special data identifier is an identifier for things that cannot be\n"
    "considered reactions in their own right. An example of this would be\n"
    "nubar, which is not the fission reaction but the fission neutron\n"
    "multiplicity. ENDF rules cloud this distinction while GNDS does not.\n\n"
    "The symbol of the special data identifier consists of a valid particle\n"
    "pair identifier and the special data type symbol separated by an arrow.\n\n"
    "For example:\n"
    "  - \"n,U235->nubar,total\" for U235 total neutron induced fission nubar\n"
    "  - \"n,U235->qfission\" for U235 fission energy release data\n"
    "  - \"n,Be9->xp\" for the total proton production cross section on Be9\n"
    "    Comparison operators are provided using the logical order given by the\n"
    "symbol. A hash function and override for std::hash is also provided."
  );

  // wrap the component
  component
  .def(

    python::init< const std::string& >(),
    python::arg( "string" ),
    "Initialise the SpecialDataID using a string\n\n"
    "Arguments:\n"
    "    string    the identifier string (case sensitive)"
  )
  .def(

    python::init< const ParticleID&, const ParticleID&, const SpecialDataType& >(),
    python::arg( "incident" ), python::arg( "target" ), python::arg( "type" ),
    "Initialise the SpecialDataID using an incident particle, target and\n"
    "special data type\n\n"
    "Arguments:\n"
    "    incident      the incident particle identifier\n"
    "    target        the target particle identifier\n"
    "    type          the special data type"
  )
  .def_property_readonly(

    "incident",
    &Component::incident,
    "The incident particle pair identifier for the reaction"
  )
  .def_static(

    "validate",
    &Component::validate,
    python::arg( "string" ),
    "Verify if a string is a valid identifier string for special data\n\n"
    "Arguments:\n"
    "    string   the string to be validated"
  )
  .def_property_readonly(

    "symbol",
    [] ( const Component& self ) { return self.symbol(); },
    "The particle pair symbol"
  );

  // add standard definitions
  addStandardDefinitions< Component >( component );

  // add standard dictionary key definitions
  addStandardDictionaryKeyDefinitions< Component >( component );
}
