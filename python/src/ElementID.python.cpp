// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "elementary/ElementID.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

void wrapElementID( python::module& module ) {

  // type aliases
  using Component = njoy::elementary::ElementID;

  // create the component
  python::class_< Component > component(

    module,
    "ElementID",
    "The element identifier, with associated element symbol and name"
  );

  // wrap the component
  component
  .def(

    python::init< int >(),
    python::arg( "number" ),
    "Initialise the ElementID using an element number\n\n"
    "This function throws a ValueError exception if the number\n"
    "is not between 1 and the largest registered element number.\n\n"
    "Arguments:\n"
    "    self      the identifier\n"
    "    number   the element number"
  )
  .def(

    python::init< const std::string& >(),
    python::arg( "string" ),
    "Initialise the ElementID using a string\n\n"
    "This function throws a ValueError exception exception if the string is\n"
    "not a registered symbol, name or alternative.\n\n"
    "Arguments:\n"
    "    self      the identifier\n"
    "    string    the symbol, name or alternative name of the particle\n"
    "              (case insensitive)"
  )
  .def_property_readonly(

    "number",
    &Component::number,
    "The element number"
  )
  .def_property_readonly(

    "symbol",
    &Component::symbol,
    "The element symbol"
  )
  .def_property_readonly(

    "name",
    &Component::name,
    "The element name"
  );

  // add standard definitions
  addStandardDefinitions< Component >( component );

  // add standard dictionary key definitions
  addStandardDictionaryKeyDefinitions< Component >( component );
}
