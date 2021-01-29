// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "elementary/Level.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

void wrapLevel( python::module& module ) {

  // type aliases
  using Component = njoy::elementary::Level;

  // create the component
  python::class_< Component > component(

    module,
    "Level",
    "The nuclear level number"
  );

  component
  .def(

    python::init< const std::string& >(),
    python::arg( "string" ),
    "Initialise the Level using a string\n\n"
    "This function throws a ValueError exception exception if invalid data\n"
    "is used.\n\n"
    "Arguments:\n"
    "    self      the identifier\n"
    "    string    the string representation of a level number (case \n"
    "              insensitive)"
  )
  .def(

    python::init< int >(),
    python::arg( "za" ),
    "Initialise the Level using the level number\n\n"
    "This function throws a ValueError exception exception if invalid data\n"
    "is used.\n\n"
    "Arguments:\n"
    "    self   the identifier\n"
    "    l      the level number"
  )
  .def_property_readonly_static(

    "continuum",
    [] ( python::object ) { return Component::continuum; },
    "The continuum level number"
  )
  .def_property_readonly(

    "number",
    &Component::number,
    "Return the level number"
  )
  .def_property_readonly(

    "symbol",
    &Component::symbol,
    "Return the level symbol"
  )
  .def_property_readonly(

    "name",
    &Component::name,
    "Return the level name"
  );

  // add standard definitions
  addStandardDefinitions< Component >( component );

  // add standard dictionary key definitions
  addStandardDictionaryKeyDefinitions< Component >( component );
}
