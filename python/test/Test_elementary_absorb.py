# standard imports
import unittest

# third party imports

# local imports
from elementary import FundamentalParticleID
from elementary import IsotopeID
from elementary import NucleusID
from elementary import NuclideID
from elementary import ParticleID
from elementary import absorb

class Test_elementary_absorb( unittest.TestCase ) :
    """Unit test for the absorb function."""

    def test_values( self ) :

        n = FundamentalParticleID( "n" );
        isotope_h1 = IsotopeID( "h1" );
        isotope_h2 = IsotopeID( "h2" );
        h1 = NucleusID( "h1" );
        H1 = NuclideID( "H1" );
        particle_h1 = ParticleID( "h1" );

        self.assertEqual( isotope_h2, absorb( isotope_h1, n ) );
        self.assertEqual( isotope_h2, absorb( h1, n ) );
        self.assertEqual( isotope_h2, absorb( H1, n ) );
        self.assertEqual( isotope_h2, absorb( particle_h1, n ) );

if __name__ == '__main__' :

    unittest.main()
