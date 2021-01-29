// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "elementary/ParticlePairID.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

void wrapParticlePairID( python::module& module ) {

  // type aliases
  using ParticleID = njoy::elementary::ParticleID;
  using Component = njoy::elementary::ParticlePairID;

  // create the component
  python::class_< Component > component(

    module,
    "ParticlePairID",
    "A particle pair represents the two particles involved in a entrance\n"
    "reaction channel or two body exit reaction channel. The pair consists of\n"
    "a \"small\" incident or outgoing particle (e.g. a neutron, photon, alpha,\n"
    "etc.) and a \"larger\" target or residual nucleus (e.g. H1, He4, U235,\n"
    "etc.).\n\n"
    "The symbol of the particle identifier consists of two valid particle\n"
    "identifiers separated by a comma. For example:\n"
    "  - \"n,Fe56\" for a neutron and the Fe56 nuclide\n"
    "  - \"n,he4\" for a neutron and an alpha particle\n"
    "  - \"h3,h2\" for a triton and a deuteron particle\n\n"
    "The order in which these are given determines which particle is\n"
    "considered the \"particle\" and which is the \"residual\".\n\n"
    "The regular particle pair identifiers can also be replaced by special\n"
    "reaction type symbols such as \"total\" or \"fission[total]\". When such\n"
    "special reaction types are used, the particle pair cannot be used as\n"
    "an incident particle pair in a reaction identifier.\n"
  );

  // wrap the component
  component
  .def(

    python::init< const std::string& >(),
    python::arg( "string" ),
    "Initialise the ParticlePairID using a string\n\n"
    "Arguments:\n"
    "    string    the identifier string (case sensitive)"
  )
  .def(

    python::init< const ParticleID&, const ParticleID& >(),
    python::arg( "id1" ), python::arg( "id2" ),
    "Initialise the ParticlePairID using two particle identifiers\n\n"
    "Arguments:\n"
    "    id1   a particle identifier for the particle\n"
    "    id2   a particle identifier for the residual"
  )
  .def_property_readonly(

    "particle",
    &Component::particle,
    "Return the particle identifier for the particle in the pair"
  )
  .def_property_readonly(

    "residual",
    &Component::residual,
    "Return the particle identifier for the residual in the pair"
  )
  .def_static(

    "validate",
    &Component::validate,
    python::arg( "string" ),
    "Verify if a string is a valid identifier string for a particle pair\n\n"
    "Arguments:\n"
    "    string   the string to be validated"
  )
  .def_property_readonly(

    "symbol",
    [] ( const Component& self ) { return self.symbol(); },
    "Return the particle pair symbol symbol"
  )
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
  )
  .def(

    "__eq__",
    [] ( const Component& self, const std::string& right )
       { return self == right; },
    "Equal function"
  )
  .def(

    "__lt__",
    [] ( const Component& self, const std::string& right )
       { return self < right; },
    "Less than function"
  );

  // add standard definitions
  addStandardDefinitions< Component >( component );

  // cannot add standard dictionary key definitions
}
