# standard imports
import unittest

# third party imports

# local imports
from elementary import ParticleTupleID
from elementary import ParticlePairID
from elementary import ParticleID
from elementary import ReactionType
from elementary import ReactionID

class Test_elementary_ReactionID( unittest.TestCase ) :
    """Unit test for the ReactionID class."""

    def test_values( self ) :

        id = ReactionID( ParticlePairID( 'n,Fe56' ), ParticlePairID( 'n,Fe56' ) )
        self.assertEqual( 'n,Fe56->n,Fe56', id.symbol )
        self.assertEqual( ParticlePairID( 'n,Fe56' ), id.incident )
        self.assertEqual( ParticleTupleID( 'n,Fe56' ), id.outgoing )

        id = ReactionID( ParticlePairID( 'n,Fe56' ), ParticleTupleID( 'n,Fe56' ) )
        self.assertEqual( 'n,Fe56->n,Fe56', id.symbol )
        self.assertEqual( ParticlePairID( 'n,Fe56' ), id.incident )
        self.assertEqual( ParticleTupleID( 'n,Fe56' ), id.outgoing )

        id = ReactionID( 'n,Fe56->n,Fe56' )
        self.assertEqual( 'n,Fe56->n,Fe56', id.symbol )
        self.assertEqual( ParticlePairID( 'n,Fe56' ), id.incident )
        self.assertEqual( ParticleTupleID( 'n,Fe56' ), id.outgoing )

        id = ReactionID( 'n,Fe56->capture' )
        self.assertEqual( 'n,Fe56->capture', id.symbol )
        self.assertEqual( ParticlePairID( 'n,Fe56' ), id.incident )

        id = ReactionID( ParticleID( 'n' ), ParticleID( 'Fe56' ), ReactionType( 'elastic' ) )
        self.assertEqual( 'n,Fe56->n,Fe56', id.symbol )
        self.assertEqual( ParticlePairID( 'n,Fe56' ), id.incident )
        self.assertEqual( ParticleTupleID( 'n,Fe56' ), id.outgoing )

        id = ReactionID( ParticleID( 'n' ), ParticleID( 'Fe56' ), ReactionType( 2 ) )
        self.assertEqual( 'n,Fe56->n,Fe56', id.symbol )
        self.assertEqual( ParticlePairID( 'n,Fe56' ), id.incident )
        self.assertEqual( ParticleTupleID( 'n,Fe56' ), id.outgoing )

        id = ReactionID( ParticleID( 'n' ), ParticleID( 'Fe56_e1' ), ReactionType( 2 ) )
        self.assertEqual( 'n,Fe56_e1->n,Fe56', id.symbol )
        self.assertEqual( ParticlePairID( 'n,Fe56_e1' ), id.incident )
        self.assertEqual( ParticleTupleID( 'n,Fe56' ), id.outgoing )

        id = ReactionID( ParticleID( 'n' ), ParticleID( 'Fe56' ), ReactionType( 51 ) )
        self.assertEqual( 'n,Fe56->n,Fe56_e1', id.symbol )
        self.assertEqual( ParticlePairID( 'n,Fe56' ), id.incident )
        self.assertEqual( ParticleTupleID( 'n,Fe56_e1' ), id.outgoing )

        id = ReactionID( ParticleID( 'n' ), ParticleID( 'Fe56' ), ReactionType( 1 ) )
        self.assertEqual( 'n,Fe56->total', id.symbol )
        self.assertEqual( ParticlePairID( 'n,Fe56' ), id.incident )

        id = ReactionID( ParticleID( 'n' ), ParticleID( 'Fe56' ), ReactionType( 5 ) )
        self.assertEqual( 'n,Fe56->anything', id.symbol )
        self.assertEqual( ParticlePairID( 'n,Fe56' ), id.incident )

        id = ReactionID( ParticleID( 'n' ), ParticleID( 'Fe56' ), ReactionType( 4 ) )
        self.assertEqual( 'n,Fe56->inelastic', id.symbol )
        self.assertEqual( ParticlePairID( 'n,Fe56' ), id.incident )

        id = ReactionID( ParticleID( 'n' ), ParticleID( 'Fe56' ), ReactionType( 102 ) )
        self.assertEqual( 'n,Fe56->capture', id.symbol )
        self.assertEqual( ParticlePairID( 'n,Fe56' ), id.incident )

        id = ReactionID( ParticleID( 'n' ), ParticleID( 'Fe56' ), ReactionType( 16 ) )
        self.assertEqual( 'n,Fe56->n,n,Fe55', id.symbol )
        self.assertEqual( ParticlePairID( 'n,Fe56' ), id.incident )
        self.assertEqual( ParticleTupleID( 'n,n,Fe55' ), id.outgoing )

        id = ReactionID( ParticleID( 'n' ), ParticleID( 'Fe56' ), ReactionType( 649 ) )
        self.assertEqual( 'n,Fe56->p,Mn56[continuum]', id.symbol )
        self.assertEqual( ParticlePairID( 'n,Fe56' ), id.incident )
        self.assertEqual( ParticleTupleID( 'p,Mn56[continuum]' ), id.outgoing )

    def test_comparison( self ) :

        id1 = ReactionID( 'n,Fe56->n,Fe56' )
        id2 = ReactionID( 'n,Fe56->n,Fe56_e1' )

        self.assertEqual( id1 <  id1, False )
        self.assertEqual( id1 == id1, True )
        self.assertEqual( id1 != id1, False )
        self.assertEqual( id1 <  id2, True )
        self.assertEqual( id1 == id2, False )
        self.assertEqual( id1 != id2, True )
        self.assertEqual( id2 <  id1, False )
        self.assertEqual( id2 == id1, False )
        self.assertEqual( id2 != id1, True )

    def test_key( self ) :

        id1 = ReactionID( 'n,Fe56->n,Fe56' )
        id2 = ReactionID( 'n,Fe56->n,Fe56_e1' )

        map = { id1 : '1', id2 : '2' }

        self.assertEqual( map[ id1 ], '1' )
        self.assertEqual( map[ id2 ], '2' )
        self.assertEqual( map[ ReactionID( 'n,Fe56->n,Fe56' ) ], '1' )
        self.assertEqual( map[ ReactionID( 'n,Fe56->n,Fe56_e1' ) ], '2' )

    def test_failures( self ) :

        # illegal values
        with self.assertRaises( ValueError ) : id = ReactionID( 'not a reaction ID' )
        with self.assertRaises( ValueError ) : id = ReactionID( 'n,Fe56' )

if __name__ == '__main__' :

    unittest.main()
