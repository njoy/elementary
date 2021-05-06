# standard imports
import unittest

# third party imports

# local imports
from elementary import ParticleTupleID
from elementary import ParticlePairID
from elementary import ParticleID

class Test_elementary_ParticlePairID( unittest.TestCase ) :
    """Unit test for the ParticlePairID class."""

    def test_values( self ) :

      id = ParticleTupleID( ParticleID( "n" ), ParticleID( "Fe56" ) )
      particles = id.particles
      residual = id.residual

      self.assertEqual( "n,Fe56", id.symbol )
      self.assertEqual( 1, len( particles ) )
      self.assertEqual( ParticleID( "n" ), particles[0] )
      self.assertEqual( ParticleID( "Fe56" ), residual )

      id = ParticleTupleID( ParticleID( "n" ), ParticleID( "p" ),
                            ParticleID( "Fe56" ) )
      particles = id.particles
      residual = id.residual

      self.assertEqual( "n,p,Fe56", id.symbol )
      self.assertEqual( 2, len( particles ) )
      self.assertEqual( ParticleID( "n" ), particles[0] )
      self.assertEqual( ParticleID( "p" ), particles[1] )
      self.assertEqual( ParticleID( "Fe56" ), residual )

      id = ParticleTupleID( ParticleID( "n" ), ParticleID( "p" ),
                            ParticleID( "he4" ), ParticleID( "Fe56" ) )
      particles = id.particles
      residual = id.residual

      self.assertEqual( "n,p,he4,Fe56", id.symbol )
      self.assertEqual( 3, len( particles ) )
      self.assertEqual( ParticleID( "n" ), particles[0] )
      self.assertEqual( ParticleID( "p" ), particles[1] )
      self.assertEqual( ParticleID( "he4" ), particles[2] )
      self.assertEqual( ParticleID( "Fe56" ), residual )

      identifiers = [ ParticleID( "n" ), ParticleID( "p" ),
                      ParticleID( "he4" ), ParticleID( "Fe56" ) ]
      id = ParticleTupleID( identifiers )
      particles = id.particles
      residual = id.residual

      self.assertEqual( "n,p,he4,Fe56", id.symbol )
      self.assertEqual( 3, len( particles ) )
      self.assertEqual( ParticleID( "n" ), particles[0] )
      self.assertEqual( ParticleID( "p" ), particles[1] )
      self.assertEqual( ParticleID( "he4" ), particles[2] )
      self.assertEqual( ParticleID( "Fe56" ), residual )

      id = ParticleTupleID( "n,p,Fe56" )
      self.assertEqual( "n,p,Fe56", id.symbol )

      id = ParticleTupleID( "total" )
      self.assertEqual( "total", id.symbol )

      id = ParticleTupleID( "capture" )
      self.assertEqual( "capture", id.symbol )

      id = ParticleTupleID( ParticlePairID( ParticleID( "n" ),
                                            ParticleID( "Fe56" ) ) )
      self.assertEqual( "n,Fe56", id.symbol )

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
        with self.assertRaises( ValueError ) : id = ParticlePairID( 'not an particle tuple ID' )
        with self.assertRaises( ValueError ) : id = ParticlePairID( 'Fe56' )
        with self.assertRaises( ValueError ) : id = ParticlePairID( 'elastic' )

if __name__ == '__main__' :

    unittest.main()
