// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "elementary/IsotopeID.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

void wrapIsotopeID( python::module& module ) {

  // type aliases
  using Component = njoy::elementary::IsotopeID;

  // create the component
  python::class_< Component > component(

    module,
    "IsotopeID",
    "The isotope identifier, with associated name\n\n"
    "Isotope symbols are composed of the corresponding chemical symbol plus\n"
    "the mass number A (values larger than 300 are not allowed).\n\n"
    "For example: \"Fe56\" for a single isotope or \"Fe0\" for the element.\n"
    "\"Fe\" is also accepted but will be converted into \"Fe0\""
  );

  // wrap the component
  component
  .def(

    python::init< const std::string& >(),
    python::arg( "string" ),
    "Initialise the IsotopeID using a string\n\n"
    "This function throws a ValueError exception exception if invalid data\n"
    "is used.\n\n"
    "Arguments:\n"
    "    self      the identifier\n"
    "    string    the string representation of the isotope (case insensitive)"
  )
  .def(

    python::init< int >(),
    python::arg( "za" ),
    "Initialise the IsotopeID using a za number\n\n"
    "This function throws a ValueError exception exception if invalid data\n"
    "is used.\n\n"
    "Arguments:\n"
    "    self      the identifier\n"
    "    za    the za value of the isotope"
  )
  .def(

    python::init< int, int >(),
    python::arg( "z" ), python::arg( "a" ),
    "Initialise the IsotopeID using a za number\n\n"
    "This function throws a ValueError exception exception if invalid data\n"
    "is used.\n\n"
    "Arguments:\n"
    "    self      the identifier\n"
    "    z    the element number of the isotope\n"
    "    a    the mass number of the isotope\n"
  )
  .def_property_readonly(

    "element",
    &Component::element,
    "Return the isotope's element identifier"
  )
  .def_property_readonly(

    "mass",
    &Component::mass,
    "Return the isotope mass number"
  )
  .def_property_readonly(

    "za",
    &Component::za,
    "Return the isotope's za value"
  )
  .def_property_readonly(

    "symbol",
    &Component::symbol,
    "Return the isotope symbol"
  )
  .def_property_readonly(

    "name",
    &Component::name,
    "Return the isotope name"
  );

  // add standard definitions
  addStandardDefinitions< Component >( component );

  // add standard dictionary key definitions
  addStandardDictionaryKeyDefinitions< Component >( component );
}
