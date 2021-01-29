// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "elementary/ParticleTupleID.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

void wrapParticleTupleID( python::module& module ) {

  // type aliases
  using ParticleID = njoy::elementary::ParticleID;
  using ParticlePairID = njoy::elementary::ParticlePairID;
  using Component = njoy::elementary::ParticleTupleID;

  // create the component
  python::class_< Component > component(

    module,
    "ParticleTupleID",
    "A particle tuple represents an n-body exit reaction channel. The tuple\n"
    "consists of a number of \"small\" particles (e.g. a neutron, photon, alpha,\n"
    "etc.) and a \"larger\" residual nucleus (e.g. H1, He4, U235, etc.).\n\n"
    "The symbol of the particle identifier consists of at least two valid\n"
    "particle identifiers separated by a comma. For example:\n"
    "  - \"n,Fe56\" for a neutron and the Fe56 nuclide\n"
    "  - \"n,p,he4\" for a neutron, proton and an alpha particle\n\n"
    "The order in which these are given is important. The last one is\n"
    "considered the \"residual\", all others are considered \"particles\".\n\n"
    "The regular particle tuple identifiers can also be replaced by special\n"
    "reaction type symbols such as \"total\" or \"fission[total]\"."
  );

  // wrap the component
  component
  .def(

    python::init< const std::string& >(),
    python::arg( "string" ),
    "Initialise the ParticleTupleID using a string\n\n"
    "Arguments:\n"
    "    string    the identifier string (case sensitive)"
  )
  .def(

    //! @todo make the variadic template constructor work
    python::init< const ParticleID&, const ParticleID& >(),
    python::arg( "id1" ), python::arg( "id2" ),
    "Initialise the ParticlePairID using two particle identifiers\n\n"
    "Arguments:\n"
    "    id1   a particle identifier for the particle\n"
    "    id2   a particle identifier for the residual"
  )
  .def(

    python::init< const ParticleID&, const ParticleID&, const ParticleID& >(),
    python::arg( "id1" ), python::arg( "id2" ), python::arg( "id3" ),
    "Initialise the ParticlePairID using three particle identifiers\n\n"
    "Arguments:\n"
    "    id1   a particle identifier for the first particle\n"
    "    id2   a particle identifier for the second particle\n"
    "    id3   a particle identifier for the residual"
  )
  .def(

    python::init< const ParticleID&, const ParticleID&,
                  const ParticleID&, const ParticleID& >(),
    python::arg( "id1" ), python::arg( "id2" ),
    python::arg( "id3" ), python::arg( "id4" ),
    "Initialise the ParticlePairID using three particle identifiers\n\n"
    "Arguments:\n"
    "    id1   a particle identifier for the first particle\n"
    "    id2   a particle identifier for the second particle\n"
    "    id3   a particle identifier for the third particle\n"
    "    id4   a particle identifier for the residual"
  )
  .def(

    python::init< const std::vector< ParticleID >& >(),
    python::arg( "identifiers" ),
    "Initialise the ParticleTupleID using a list of particle identifiers\n\n"
    "Arguments:\n"
    "    identifiers   a vector of particle identifiers"
  )
  .def(

    python::init< const ParticlePairID& >(),
    python::arg( "pair" ),
    "Initialise the ParticleTupleID using a ParticlePairID\n\n"
    "Arguments:\n"
    "    pair   a particle pair identifier"
  )
  .def_property_readonly(

    "particles",
    &Component::particles,
    "Return the particle identifiers for the particles in the tuple\n"
    "(this excludes the residual)"
  )
  .def_property_readonly(

    "residual",
    &Component::residual,
    "Return the particle identifier for the residual in the tuple"
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
