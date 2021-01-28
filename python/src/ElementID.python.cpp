// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "elementary.hpp"

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
    "    string    the symbol, name or alternative name of the particle\n"
    "              (case insensitive)"
  )
  .def(

    python::init< const std::string& >(),
    python::arg( "string" ),
    "Initialise the ElementID using a string\n\n"
    "This function throws a ValueError exception exception if the string is\n"
    "not a registered symbol, name or alternative.\n\n"
    "Arguments:\n"
    "    number   the element number"
  )
  .def_property_readonly(

    "number",
    &Component::number,
    "Return the element number"
  )
  .def_property_readonly(

    "symbol",
    &Component::symbol,
    "Return the element symbol"
  )
  .def_property_readonly(

    "name",
    &Component::name,
    "Return the element name"
  )
  .def(

    "__repr__",
    &Component::symbol,
    "Convenience function for printing the element identifier"
  )
  .def(

    "__hash__",
    &Component::number,
    "Hash function"
  )
  .def(

    "__eq__",
    &Component::operator==,
    "Equal function"
  )
  .def(

    "__lt__",
    &Component::operator<,
    "Less than function"
  );
}
