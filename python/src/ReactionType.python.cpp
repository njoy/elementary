// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <variant>

// local includes
#include "elementary/ReactionType.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

void wrapReactionType( python::module& module ) {

  // type aliases
  using Component = njoy::elementary::ReactionType;

  // create the component
  python::class_< Component > component(

    module,
    "ReactionType",
    "A predefined reaction type, with associated information such as a symbol, \n"
    "aliases or optional ENDF reaction numbers"
  );

  // wrap the component
  component
  .def(

    python::init< const std::string& >(),
    python::arg( "string" ),
    "Initialise the ReactionType using a string\n\n"
    "This function throws a ValueError exception exception if invalid data\n"
    "is used.\n\n"
    "Arguments:\n"
    "    string    the name or alternative name of the reaction (case\n"
    "              sensitive)"
  )
  .def(

    python::init< int >(),
    python::arg( "number" ),
    "Initialise the ReactionType using an ENDF MT number\n\n"
    "This function throws a ValueError exception exception if the number is\n"
    "not a registered MT number.\n\n"
    "Arguments:\n"
    "    number   the mt number"
  )
  .def_static(

    "is_registered",
    static_cast< bool (*)( const std::string& ) >( &Component::isRegistered ),
    python::arg( "number" ),
    "Verify if a given string is registered as a reaction\n\n"
    "Arguments:\n"
    "    string    the name or alternative name of the reaction (case\n"
    "              sensitive)"
  )
  .def_static(

    "is_registered",
    static_cast< bool (*)( int ) >( &Component::isRegistered ),
    python::arg( "number" ),
    "Verify if a given mt number is registered as a reaction\n\n"
    "Arguments:\n"
    "    number   the mt number"
  )
  .def_property_readonly(

    "is_special",
    &Component::isSpecial,
    "Return whether or not the reaction is a special reaction (i.e. a\n"
    "reaction for which no outgoing particles are registered, except\n"
    "for elastic)"
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
  )
  .def_property_readonly(

    "particles",
    &Component::particles,
    "The outgoing particles"
  )
  .def_property_readonly(

    "level",
    &Component::level,
    "The excited level number of the outgoing residual"
  );

  // add standard definitions
  addStandardDefinitions< Component >( component );

  // add standard dictionary key definitions
  addStandardDictionaryKeyDefinitions< Component >( component );
}
