# standard imports
import unittest

# third party imports

# local imports
from elementary import SpecialDataType

class Test_elementary_SpecialDataType( unittest.TestCase ) :
    """Unit test for the SpecialDataType class."""

    def test_values( self ) :

        id = SpecialDataType( 452 );
        self.assertTrue( 452 == id1.mt )
        self.assertTrue( 'nubar,total' == id1.symbol )

        id = SpecialDataType( 'nubar,total' );
        self.assertTrue( 452 == id2.mt )
        self.assertTrue( 'nubar,total' == id2.symbol )

        id = SpecialDataType( 251 );
        self.assertTrue( 251 == id3.mt )
        self.assertTrue( 'mubar' == id3.symbol )

        id = SpecialDataType( 'mubar' );
        self.assertTrue( 251 == id4.mt )
        self.assertTrue( 'mubar' == id4.symbol )

    def test_values( self ) :

        self.assertTrue( SpecialDataType.is_registered( 'nubar,total' ) )
        self.assertTrue( SpecialDataType.is_registered( 452 ) )

        self.assertTrue( SpecialDataType.is_registered( 'mubar' ) )
        self.assertTrue( SpecialDataType.is_registered( 251 ) )

        self.assertFalse( SpecialDataType.is_registered( 'not registered' ) )
        self.assertFalse( SpecialDataType.is_registered( 999 ) )

    def test_comparison( self ) :

        id1 = SpecialDataType( 'nubar,delayed' )
        id2 = SpecialDataType( 'nubar,total' )

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

        id1 = SpecialDataType( 'nubar,delayed' )
        id2 = SpecialDataType( 'nubar,total' )

        map = { id1 : '1', id2 : '2' }

        self.assertEqual( map[ id1 ], '1' )
        self.assertEqual( map[ id2 ], '2' )
        self.assertEqual( map[ SpecialDataType( 'nubar,delayed' ) ], '1' )
        self.assertEqual( map[ SpecialDataType( 'nubar,total' ) ], '2' )

    def test_failures( self ) :

        # illegal values
        with self.assertRaises( ValueError ) : id = SpecialDataType( 'not a reaction name or alternative' )
        with self.assertRaises( ValueError ) : id = SpecialDataType( 0 )
        with self.assertRaises( ValueError ) : id = SpecialDataType( -1 )

if __name__ == '__main__' :

    unittest.main()
