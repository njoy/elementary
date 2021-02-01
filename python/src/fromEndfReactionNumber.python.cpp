// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <variant>

// local includes
#include "elementary/fromEndfReactionNumber.hpp"

// namespace aliases
namespace python = pybind11;

void wrapFromEndfReactionNumber( python::module& module ) {

  module.def(

    "from_endf_reaction_number",
    &njoy::elementary::fromEndfReactionNumber,
    python::arg( "incident" ), python::arg( "target" ), python::arg( "mt" ),
    "Return a reaction identifier corresponding to the given MT number\n\n"
    "Arguments:\n"
    "    incident   the incident particle identifier\n"
    "    target     the target particle identifier\n"
    "    mt         the MT number"
  );

}
