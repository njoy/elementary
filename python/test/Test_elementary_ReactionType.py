# standard imports
import unittest

# third party imports

# local imports
from elementary import ReactionType
from elementary import ParticleID

class Test_elementary_ReactionType( unittest.TestCase ) :
    """Unit test for the ReactionType class."""

    def test_values( self ) :

        neutron = ParticleID( 'n' )
        proton = ParticleID( 'p' )
        deuteron = ParticleID( 'h2' )
        triton = ParticleID( 'h3' )
        helion = ParticleID( 'he3' )
        alpha = ParticleID( 'he4' )

        id = ReactionType( 1 )
        self.assertEqual( 1 == id.mt )
        self.assertEqual( 'total' == id.symbol )
        self.assertEqual( 0 == len( id.particles ) )

        id = ReactionType( 2 )
        self.assertEqual( 2 == id.mt )
        self.assertEqual( 'elastic' == id.symbol )
        self.assertEqual( 0 == len( id.particles ) )

        id = ReactionType( 11 )
        self.assertEqual( 11 == id.mt )
        self.assertEqual( '2nd' == id.symbol )
        self.assertEqual( 3 == len( id.particles ) )
        self.assertEqual( neutron == id.particles[0] )
        self.assertEqual( neutron == id.particles[1] )
        self.assertEqual( deuteron == id.particles[2] )

        id = ReactionType( 16 )
        self.assertEqual( 16 == id.mt )
        self.assertEqual( '2n(t)' == id.symbol )
        self.assertEqual( 2 == len( id.particles ) )
        self.assertEqual( neutron == id.particles[0] )
        self.assertEqual( neutron == id.particles[1] )

        id = ReactionType( 17 )
        self.assertEqual( 17 == id.mt )
        self.assertEqual( '3n' == id.symbol )
        self.assertEqual( 3 == len( id.particles ) )
        self.assertEqual( neutron == id.particles[0] )
        self.assertEqual( neutron == id.particles[1] )
        self.assertEqual( neutron == id.particles[2] )

        id = ReactionType( 22 )
        self.assertEqual( 22 == id.mt )
        self.assertEqual( 'na' == id.symbol )
        self.assertEqual( 2 == len( id.particles ) )
        self.assertEqual( neutron == id.particles[0] )
        self.assertEqual( alpha == id.particles[1] )

        id = ReactionType( 23 )
        self.assertEqual( 23 == id.mt )
        self.assertEqual( 'n3a' == id.symbol )
        self.assertEqual( 4 == len( id.particles ) )
        self.assertEqual( neutron == id.particles[0] )
        self.assertEqual( alpha == id.particles[1] )
        self.assertEqual( alpha == id.particles[2] )
        self.assertEqual( alpha == id.particles[3] )

        id = ReactionType( 24 )
        self.assertEqual( 24 == id.mt )
        self.assertEqual( '2na' == id.symbol )
        self.assertEqual( 3 == len( id.particles ) )
        self.assertEqual( neutron == id.particles[0] )
        self.assertEqual( neutron == id.particles[1] )
        self.assertEqual( alpha == id.particles[2] )

        id = ReactionType( 37 )
        self.assertEqual( 37 == id.mt )
        self.assertEqual( '4n' == id.symbol )
        self.assertEqual( 4 == len( id.particles ) )
        self.assertEqual( neutron == id.particles[0] )
        self.assertEqual( neutron == id.particles[1] )
        self.assertEqual( neutron == id.particles[2] )
        self.assertEqual( neutron == id.particles[3] )

    def test_values( self ) :

        self.assertTrue( ReactionType.is_registered( 'total' ) )
        self.assertTrue( ReactionType.is_registered( 1 ) )

        self.assertFalse( ReactionType.is_registered( 'not registered' ) )
        self.assertFalse( ReactionType.is_registered( 999 ) )

    def test_comparison( self ) :

        id1 = ReactionType( 'n(0)' )
        id2 = ReactionType( 'n(1)' )

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

        id1 = ReactionType( 'n(0)' )
        id2 = ReactionType( 'n(1)' )

        map = { id1 : '1', id2 : '2' }

        self.assertEqual( map[ id1 ], '1' )
        self.assertEqual( map[ id2 ], '2' )
        self.assertEqual( map[ ReactionType( 'n(0)' ) ], '1' )
        self.assertEqual( map[ ReactionType( 'n(1)' ) ], '2' )

    def test_failures( self ) :

        # illegal values
        with self.assertRaises( ValueError ) : id = ReactionType( 'not a reaction name or alternative' )
        with self.assertRaises( ValueError ) : id = ReactionType( 0 )
        with self.assertRaises( ValueError ) : id = ReactionType( -1 )

if __name__ == '__main__' :

    unittest.main()
