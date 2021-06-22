# standard imports
import unittest

# third party imports

# local imports
from elementary import ParticleTupleID
from elementary import ParticlePairID
from elementary import ParticleID
from elementary import SpecialDataType
from elementary import SpecialDataID

class Test_elementary_SpecialDataID( unittest.TestCase ) :
    """Unit test for the SpecialDataID class."""

    def test_values( self ) :

        id = SpecialDataID( 'n,U235->nubar,total' );
        self.assertEqual( 'n,U235->nubar,total', id.symbol )
        self.assertEqual( ParticlePairID( 'n,U235' ), id.incident )

        id = SpecialDataID( 'n,U235->xp' );
        self.assertEqual( 'n,U235->xp', id.symbol )
        self.assertEqual( ParticlePairID( 'n,U235' ), id.incident )

        id = SpecialDataID( ParticleID( 'n' ), ParticleID( 'U235' ), SpecialDataType( 'xp' ) );
        self.assertEqual( 'n,U235->xp', id.symbol )
        self.assertEqual( ParticlePairID( 'n,U235' ), id.incident )

        id = SpecialDataID( ParticleID( 'n' ), ParticleID( 'U235' ), SpecialDataType( 203 ) );
        self.assertEqual( 'n,U235->xp', id.symbol )
        self.assertEqual( ParticlePairID( 'n,U235' ), id.incident )

    def test_comparison( self ) :

        id1 = SpecialDataID( 'n,U235->qfission' )
        id2 = SpecialDataID( 'n,U235->xp' )

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

        id1 = SpecialDataID( 'n,U235->qfission' )
        id2 = SpecialDataID( 'n,U235->xp' )

        map = { id1 : '1', id2 : '2' }

        self.assertEqual( map[ id1 ], '1' )
        self.assertEqual( map[ id2 ], '2' )
        self.assertEqual( map[ SpecialDataID( 'n,U235->qfission' ) ], '1' )
        self.assertEqual( map[ SpecialDataID( 'n,U235->xp' ) ], '2' )

    def test_failures( self ) :

        # illegal values
        with self.assertRaises( ValueError ) : id = SpecialDataID( 'not a reaction ID' )
        with self.assertRaises( ValueError ) : id = SpecialDataID( 'n,Fe56' )

if __name__ == '__main__' :

    unittest.main()
