// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <variant>

// local includes
#include "elementary/resolve.hpp"

// namespace aliases
namespace python = pybind11;

void wrapResolve( python::module& module ) {

  module.def(

    "resolve",
    &njoy::elementary::resolve,
    python::arg( "incident" ), python::arg( "target" ), python::arg( "type" ),
    "Return the particle identifier for the residual particle\n\n"
    "Arguments:\n"
    "    incident   the incident particle identifier\n"
    "    target     the target particle identifier\n"
    "    type       the reaction type"
  );
}
