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
    [] ( const Component& self ) { return self.hash(); },
    "Hash function"
  )
  .def(

    "__eq__",
    [] ( const Component& self, const Component& right )
       { return self == right; },
    "Equal function"
  )
  .def(

    "__lt__",
    [] ( const Component& self, const Component& right )
       { return self < right; },
    "Less than function"
  );
}

/**
 *  @brief Add standard definitions
 *
 *  This adds the following standard functions:
 *    __repr__
 *
 *  @param[in] component   the component to which the definitions have to be added
 */
template < typename Component, typename PythonClass >
void addStandardDefinitions( PythonClass& component ) {

  component
  .def(

    "__repr__",
    [] ( const Component& self ) { return self.symbol(); },
    "Convenience function for printing the identifier"
  );
}

#endif
