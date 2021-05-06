# standard imports
import unittest

# third party imports

# local imports
from elementary import FundamentalParticleID
from elementary import IsotopeID
from elementary import NucleusID
from elementary import NuclideID
from elementary import ParticleID
from elementary import ReactionType
from elementary import resolve

class Test_elementary_resolve( unittest.TestCase ) :
    """Unit test for the resolve function."""

    def test_values( self ) :

        incident = ParticleID( 'n' )
        target = ParticleID( 'Fe56' )

        mt51 = ReactionType( 51 )
        mt102 = ReactionType( 102 )

        mt1 = ReactionType( 1 )
        mt18 = ReactionType( 1 )

        self.assertEqual( ParticleID( 'Fe56_e1' ), resolve( incident, target, mt51 ) )
        self.assertEqual( ParticleID( 'Fe57' ), resolve( incident, target, mt102 ) )

        with self.assertRaises( ValueError ) : resolve( incident, target, mt1 )
        with self.assertRaises( ValueError ) : resolve( incident, target, mt18 )

if __name__ == '__main__' :

    unittest.main()
