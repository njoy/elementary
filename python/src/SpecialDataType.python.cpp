// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <variant>

// local includes
#include "elementary/SpecialDataType.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

void wrapSpecialDataType( python::module& module ) {

  // type aliases
  using Component = njoy::elementary::SpecialDataType;

  // create the component
  python::class_< Component > component(

    module,
    "SpecialDataType",
    "A predefined special data type, with associated information such as a\n"
    "symbol, aliases or optional ENDF reaction numbers"
  );

  // wrap the component
  component
  .def(

    python::init< const std::string& >(),
    python::arg( "string" ),
    "Initialise the SpecialDataType using a string\n\n"
    "This function throws a ValueError exception exception if invalid data\n"
    "is used.\n\n"
    "Arguments:\n"
    "    string    the name or alternative name of the special data (case\n"
    "              sensitive)"
  )
  .def(

    python::init< int >(),
    python::arg( "number" ),
    "Initialise the SpecialDataType using an ENDF MT number\n\n"
    "This function throws a ValueError exception exception if the number is\n"
    "not a registered MT number.\n\n"
    "Arguments:\n"
    "    number   the mt number"
  )
  .def_static(

    "is_registered",
    static_cast< bool (*)( const std::string& ) >( &Component::isRegistered ),
    python::arg( "number" ),
    "Verify if a given string is registered as special data\n\n"
    "Arguments:\n"
    "    string    the name or alternative name of the special data (case\n"
    "              sensitive)"
  )
  .def_static(

    "is_registered",
    static_cast< bool (*)( int ) >( &Component::isRegistered ),
    python::arg( "number" ),
    "Verify if a given mt number is registered as special data\n\n"
    "Arguments:\n"
    "    number   the mt number"
  )
  .def_property_readonly(

    "symbol",
    &Component::symbol,
    "The reaction symbol"
  )
  .def_property_readonly(

    "mt",
    &Component::mt,
    "The mt number of the reaction, or 0 if it does not exist"
  );

  // add standard definitions
  addStandardDefinitions< Component >( component );

  // add standard dictionary key definitions
  addStandardDictionaryKeyDefinitions< Component >( component );
}
