# standard imports
import unittest

# third party imports

# local imports
from elementary import FundamentalParticleID
from elementary import IsotopeID
from elementary import NucleusID
from elementary import NuclideID
from elementary import ParticleID
from elementary import emit

class Test_elementary_emit( unittest.TestCase ) :
    """Unit test for the emit function."""

    def test_values( self ) :

      n = FundamentalParticleID( "n" );
      isotope_h1 = IsotopeID( "h1" );
      isotope_h2 = IsotopeID( "h2" );
      h2 = NucleusID( "h2" );
      H2 = NuclideID( "H2" );
      particle_h2 = ParticleID( "h2" );

      self.assertEqual( isotope_h1, emit( isotope_h2, n ) );
      self.assertEqual( isotope_h1, emit( h2, n ) );
      self.assertEqual( isotope_h1, emit( H2, n ) );
      self.assertEqual( isotope_h1, emit( particle_h2, n ) );

if __name__ == '__main__' :

    unittest.main()
