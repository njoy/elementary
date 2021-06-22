# standard imports
import unittest

# third party imports

# local imports
from elementary import ParticlePairID
from elementary import ParticleID

class Test_elementary_ParticlePairID( unittest.TestCase ) :
    """Unit test for the ParticlePairID class."""

    def test_values( self ) :

        id = ParticlePairID( ParticleID( 'n' ), ParticleID( 'Fe56' ) )
        self.assertEqual( 'n,Fe56', id.symbol )
        self.assertEqual( ParticleID( 'n' ), id.particle )
        self.assertEqual( ParticleID( 'Fe56' ), id.residual )

        id = ParticlePairID( 'n,Fe56' )
        self.assertEqual( 'n,Fe56', id.symbol )
        self.assertEqual( ParticleID( 'n' ), id.particle )
        self.assertEqual( ParticleID( 'Fe56' ), id.residual )

        id = ParticlePairID( 'total' )
        self.assertEqual( 'total', id.symbol )

        id = ParticlePairID( 'capture' )
        self.assertEqual( 'capture', id.symbol )

    def test_comparison( self ) :

        id1 = ParticlePairID( 'n,Fe56' )
        id2 = ParticlePairID( 'n,Fe56_e1' )

        self.assertEqual( id1 <  id1, False )
        self.assertEqual( id1 <= id1, True )
        self.assertEqual( id1 >  id1, False )
        self.assertEqual( id1 >= id1, True )
        self.assertEqual( id1 == id1, True )
        self.assertEqual( id1 != id1, False )
        self.assertEqual( id1 <  id2, True )
        self.assertEqual( id1 <= id2, True )
        self.assertEqual( id1 >  id2, False )
        self.assertEqual( id1 >= id2, False )
        self.assertEqual( id1 == id2, False )
        self.assertEqual( id1 != id2, True )
        self.assertEqual( id2 <  id1, False )
        self.assertEqual( id2 <= id1, False )
        self.assertEqual( id2 >  id1, True )
        self.assertEqual( id2 >= id1, True )
        self.assertEqual( id2 == id1, False )
        self.assertEqual( id2 != id1, True )

    def test_key( self ) :

        id1 = ParticlePairID( 'n,Fe56' )
        id2 = ParticlePairID( 'n,Fe56_e1' )

        map = { id1 : '1', id2 : '2' }

        self.assertEqual( map[ id1 ], '1' )
        self.assertEqual( map[ id2 ], '2' )
        self.assertEqual( map[ ParticlePairID( 'n,Fe56' ) ], '1' )
        self.assertEqual( map[ ParticlePairID( 'n,Fe56_e1' ) ], '2' )

    def test_failures( self ) :

        # illegal values
        with self.assertRaises( ValueError ) : id = ParticlePairID( 'not an particle pair ID' )
        with self.assertRaises( ValueError ) : id = ParticlePairID( 'n,p,Fe56' )
        with self.assertRaises( ValueError ) : id = ParticlePairID( 'Fe56' )
        with self.assertRaises( ValueError ) : id = ParticlePairID( 'elastic' )

if __name__ == '__main__' :

    unittest.main()
