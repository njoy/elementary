// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <variant>

// local includes
#include "elementary.hpp"

// namespace aliases
namespace python = pybind11;

void wrapToEndfReactionNumber( python::module& module ) {

  module.def(

    "to_endf_reaction_number",
    &njoy::elementary::toEndfReactionNumber,
    python::arg( "identifier" ),
    "Return the MT number for the reaction, if one can be derived\n\n"
    "If no MT number can be derived, zero will be returned.\n\n"
    "Arguments:\n"
    "    identifier   the reaction identifier"
  );

}
