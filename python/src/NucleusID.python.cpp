// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "elementary/NucleusID.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

void wrapNucleusID( python::module& module ) {

  // type aliases
  using Component = njoy::elementary::NucleusID;

  // create the component
  python::class_< Component > component(

    module,
    "NucleusID",
    "The nucleus identifier, with associated name - e.g. fe56_e0.\n\n"
    "This identifier is the same as the nuclide identifier, except that the\n"
    "name is complete lower case.\n\n"
    "For a nucleus in the ground state, the identifier is equal to the\n"
    "lower case symbol of the corresponding isotope. For a nucleus in an\n"
    "excited state, the identifier is composed of the lower case isotope\n"
    "symbol plus the string \"_e#\", where \"#\" is the excited level"
    "number.\n\n"
    "For example: \"fe56\" for the nucleus in the ground state (\"fe56_e0\"\n"
    "is also accepted but it is converted to \"fe56\" automatically) or\n"
    "\"fe56_e1\" for the first excited level.\n\n"
    "Aliases like \"am242m\" = \"am242_e2\" will be handled by a factory \n"
    "function that uses a static map for aliasing."
  );

  // wrap the component
  component
  .def(

    python::init< const std::string& >(),
    python::arg( "string" ),
    "Initialise the NucleusID using a string\n\n"
    "This function throws a ValueError exception exception if invalid data\n"
    "is used.\n\n"
    "Arguments:\n"
    "    string    the string representation of the nucleus (case sensitive)"
  )
  .def(

    python::init< int, int >(),
    python::arg( "za" ), python::arg( "l" ),
    "Initialise the NucleusID using a za and level number\n\n"
    "This function throws a ValueError exception exception if invalid data\n"
    "is used.\n\n"
    "Arguments:\n"
    "    za    the za number\n"
    "    l     the level number"
  )
  .def(

    python::init< int, int, int >(),
    python::arg( "z" ), python::arg( "a" ), python::arg( "l" ),
    "Initialise the NucleusID using an element, mass and level number\n\n"
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
    "Return the nucleus isotope identifier"
  )
  .def_property_readonly(

    "element",
    &Component::element,
    "Return the nucleus element identifier"
  )
  .def_property_readonly(

    "mass",
    &Component::mass,
    "Return the nucleus mass number"
  )
  .def_property_readonly(

    "level",
    &Component::level,
    "Return the nucleus level identifier"
  )
  .def_property_readonly(

    "symbol",
    &Component::symbol,
    "Return the nucleus symbol"
  )
  .def_property_readonly(

    "name",
    &Component::name,
    "Return the nucleus name"
  )
  .def_property_readonly(

    "za",
    &Component::za,
    "Return the nucleus za value"
  );

  // add standard definitions
  addStandardDefinitions< Component >( component );

  // add standard dictionary key definitions
  addStandardDictionaryKeyDefinitions< Component >( component );
}
