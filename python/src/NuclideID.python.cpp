// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "elementary/NuclideID.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

void wrapNuclideID( python::module& module ) {

  // type aliases
  using Component = njoy::elementary::NuclideID;

  // create the component
  python::class_< Component > component(

    module,
    "NuclideID",
    "The nuclide identifier, with associated name - e.g. Fe56_e0.\n\n"
    "For a nuclide in the ground state, the identifier is equal to the\n"
    "symbol of the corresponding isotope. For a nuclide in an excited\n"
    "state, the identifier is composed of the isotope symbol plus\n"
    "the string \"_e#\", where \"#\" is the excited level number.\n\n"
    "For example: \"Fe56\" for the nuclide in the ground state (\"Fe56_e0\"\n"
    "is also accepted but it is converted to \"Fe56\" automatically) or\n"
    "\"Fe56_e1\" for the first excited level.\n\n"
    "Aliases like \"Am242m\" = \"Am242_e2\" will be handled by a factory \n"
    "function that uses a static map for aliasing."
  );

  // wrap the component
  component
  .def(

    python::init< const std::string& >(),
    python::arg( "string" ),
    "Initialise the NuclideID using a string\n\n"
    "This function throws a ValueError exception exception if invalid data\n"
    "is used.\n\n"
    "Arguments:\n"
    "    string    the string representation of the nuclide (case sensitive)"
  )
  .def(

    python::init< int, int >(),
    python::arg( "za" ), python::arg( "l" ),
    "Initialise the NuclideID using a za and level number\n\n"
    "This function throws a ValueError exception exception if invalid data\n"
    "is used.\n\n"
    "Arguments:\n"
    "    za    the za number\n"
    "    l     the level number"
  )
  .def(

    python::init< int, int, int >(),
    python::arg( "z" ), python::arg( "a" ), python::arg( "l" ),
    "Initialise the NuclideID using an element, mass and level number\n\n"
    "This function throws a ValueError exception exception if invalid data\n"
    "is used.\n\n"
    "Arguments:\n"
    "    z    the element number\n"
    "    a    the mass number\n"
    "    l    the level number"
  )
  .def_property_readonly(

    "isotope",
    &Component::isotope,
    "The nuclide isotope identifier"
  )
  .def_property_readonly(

    "element",
    &Component::element,
    "The nuclide element identifier"
  )
  .def_property_readonly(

    "mass",
    &Component::mass,
    "The nuclide mass number"
  )
  .def_property_readonly(

    "level",
    &Component::level,
    "The nuclide level identifier"
  )
  .def_property_readonly(

    "symbol",
    &Component::symbol,
    "The nuclide symbol"
  )
  .def_property_readonly(

    "name",
    &Component::name,
    "The nuclide name"
  )
  .def_property_readonly(

    "za",
    &Component::za,
    "The nuclide za value"
  );

  // add standard definitions
  addStandardDefinitions< Component >( component );

  // add standard dictionary key definitions
  addStandardDictionaryKeyDefinitions< Component >( component );
}
