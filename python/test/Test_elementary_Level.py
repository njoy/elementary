# standard imports
import unittest

# third party imports

# local imports
from elementary import Level

class Test_elementary_Level( unittest.TestCase ) :
    """Unit test for the Level class."""

    def test_values( self ) :

        id = Level( 0 )
        self.assertEqual( 0, id.number )
        self.assertEqual( '', id.symbol )
        self.assertEqual( 'e0', id.name )

        id = Level( 'e0' )
        self.assertEqual( 0, id.number )
        self.assertEqual( '', id.symbol )
        self.assertEqual( 'e0', id.name )

        id = Level( '_e0' )
        self.assertEqual( 0, id.number )
        self.assertEqual( '', id.symbol )
        self.assertEqual( 'e0', id.name )

        id = Level( 1 )
        self.assertEqual( 1, id.number )
        self.assertEqual( '_e1', id.symbol )
        self.assertEqual( 'e1', id.name )

        id = Level( 'e1' )
        self.assertEqual( 1, id.number )
        self.assertEqual( '_e1', id.symbol )
        self.assertEqual( 'e1', id.name )

        id = Level( '_e1' )
        self.assertEqual( 1, id.number )
        self.assertEqual( '_e1', id.symbol )
        self.assertEqual( 'e1', id.name )

        continuum = Level.continuum

        id = Level( continuum )
        self.assertEqual( continuum, id.number )
        self.assertEqual( '[continuum]', id.symbol )
        self.assertEqual( '[continuum]', id.name )

        id = Level( '[continuum]' )
        self.assertEqual( continuum, id.number )
        self.assertEqual( '[continuum]', id.symbol )
        self.assertEqual( '[continuum]', id.name )

    def test_comparison( self ) :

        id1 = Level( 0 )
        id2 = Level( 1 )

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

        id1 = Level( 0 )
        id2 = Level( 1 )

        map = { id1 : '1', id2 : '2' }

        self.assertEqual( map[ id1 ], '1' )
        self.assertEqual( map[ id2 ], '2' )
        self.assertEqual( map[ Level( 0 ) ], '1' )
        self.assertEqual( map[ Level( 1 ) ], '2' )

    def test_failures( self ) :

        # illegal values
        with self.assertRaises( ValueError ) : id = Level( 'not a valid level number' )
        with self.assertRaises( ValueError ) : id = Level( -1 )
        with self.assertRaises( ValueError ) : id = Level( 100 )

if __name__ == '__main__' :

    unittest.main()
