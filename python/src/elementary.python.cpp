// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// namespace aliases
namespace python = pybind11;

// declarations
void wrapElementID( python::module& );
void wrapFundamentalParticleID( python::module& );
// void wrapIsotopeID( python::module& );
// void wrapLevel( python::module& );
// void wrapNucleusID( python::module& );
// void wrapNuclideID( python::module& );
// void wrapParticleID( python::module& );
// void wrapParticlePairID( python::module& );
// void wrapParticleTupleID( python::module& );
// void wrapReactionType( python::module& );
// void wrapReactionID( python::module& );
// void wrapFromEndfReactionNumber( python::module& );
// void wrapToEndfReactionNumber( python::module& );
// void wrapEmit( python::module& );
// void wrapAbsorb( python::module& );
// void wrapResolve( python::module& );

/**
 *  @brief ENDFtk python bindings
 *
 *  The name given here (elementary) must be the same as the name
 *  set on the PROPERTIES OUTPUT_NAME in the CMakeLists.txt file.
 */
PYBIND11_MODULE( elementary, module ) {

  wrapElementID( module );
  wrapFundamentalParticleID( module );
  // wrapIsotopeID( module );
  // wrapLevel( module );
  // wrapNucleusID( module );
  // wrapNuclideID( module );
  // wrapParticleID( module );
  // wrapParticlePairID( module );
  // wrapParticleTupleID( module );
  // wrapReactionType( module );
  // wrapReactionID( module );
  // wrapFromEndfReactionNumber( module );
  // wrapToEndfReactionNumber( module );
  // wrapEmit( module );
  // wrapAbsorb( module );
  // wrapResolve( module );
}
