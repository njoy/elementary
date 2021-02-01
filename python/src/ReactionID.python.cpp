// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "elementary/ReactionID.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

void wrapReactionID( python::module& module ) {

  // type aliases
  using ParticleID = njoy::elementary::ParticleID;
  using ParticlePairID = njoy::elementary::ParticlePairID;
  using ParticleTupleID = njoy::elementary::ParticleTupleID;
  using ReactionType = njoy::elementary::ReactionType;
  using Component = njoy::elementary::ReactionID;

  // create the component
  python::class_< Component > component(

    module,
    "ReactionID",
    "The identifier for a reaction\n\n"
    "A reaction is represented by a two body entrance reaction channel and\n"
    "an n-body exit reaction channel.\n\n"
    "The symbol of the reaction identifier consists of a valid particle pair\n"
    "identifier and one particle tuple identifiers separated by an arrow. For\n"
    "example:\n"
    "  - \"n,Fe56->n,Fe56\" for elastic neutron scattering on Fe56\n"
    "  - \"n,he4->h2,h3\" for a neutron on alpha resulting in a deuteron and\n"
    "    triton\n\n"
    "The outgoing particle tuple identifer may also be a special reaction\n"
    "identifier. For example:\n"
    "  - \"n,Fe56->total\" for the total reaction\n"
    "  - \"n,U235->fission[total]\" for total neutron induced fission on U235"
  );

  // wrap the component
  component
  .def(

    python::init< const std::string& >(),
    python::arg( "string" ),
    "Initialise the ReactionID using a string\n\n"
    "Arguments:\n"
    "    string    the identifier string (case sensitive)"
  )
  .def(

    python::init< const ParticlePairID&, const ParticlePairID& >(),
    python::arg( "in" ), python::arg( "out" ),
    "Initialise the ParticlePairID using two particle pairs\n\n"
    "Arguments:\n"
    "    in    the incoming particle pair\n"
    "    out   the outgoing particle pair"
  )
  .def(

    python::init< const ParticlePairID&, const ParticleTupleID& >(),
    python::arg( "in" ), python::arg( "out" ),
    "Initialise the ParticlePairID using an incident particle pair and\n"
    "outgoing particle tuple\n\n"
    "Arguments:\n"
    "    in    the incoming particle pair\n"
    "    out   the outgoing particle tuple"
  )
  .def(

    python::init< const ParticleID&, const ParticleID&, const ReactionType& >(),
    python::arg( "incident" ), python::arg( "target" ), python::arg( "type" ),
    "Initialise the ReactionID using an incident particle, target and\n"
    "reaction type\n\n"
    "Arguments:\n"
    "    incident      the incident particle identifier\n"
    "    target        the target particle identifier\n"
    "    type          the reaction type"
  )
  .def_property_readonly(

    "is_special",
    &Component::isSpecial,
    "Return whether or not the identifier is a special reaction"
  )
  .def_property_readonly(

    "incident",
    &Component::incident,
    "Return the incident particle pair identifier for the reaction"
  )
  .def_property_readonly(

    "outgoing",
    &Component::outgoing,
    "Return the exit particle tuple identifier for the reaction"
  )
  .def_static(

    "validate",
    &Component::validate,
    python::arg( "string" ),
    "Verify if a string is a valid identifier string for a reaction\n\n"
    "Arguments:\n"
    "    string   the string to be validated"
  )
  .def_property_readonly(

    "symbol",
    [] ( const Component& self ) { return self.symbol(); },
    "Return the particle pair symbol"
  );

  // add standard definitions
  addStandardDefinitions< Component >( component );

  // add standard dictionary key definitions
  addStandardDictionaryKeyDefinitions< Component >( component );
}
