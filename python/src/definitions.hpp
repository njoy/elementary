#ifndef NJOY_ELEMENTARY_PYTHON_DEFINITIONS
#define NJOY_ELEMENTARY_PYTHON_DEFINITIONS

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// other includes

// namespace aliases
namespace python = pybind11;

/**
 *  @brief Add standard dictionary key functions
 *
 *  This adds the following standard functions:
 *    __hash__, __eq__, __lt__
 *
 *  @param[in] component   the component to which the definitions have to be added
 */
template < typename Component, typename PythonClass >
void addStandardDictionaryKeyDefinitions( PythonClass& component ) {

  component
  .def(

    "__hash__",
    &Component::hash,
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

#endif
