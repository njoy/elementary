# standard imports
import unittest

# third party imports

# local imports
from elementary import ElementID
from elementary import IsotopeID

class Test_elementary_IsotopeID( unittest.TestCase ) :
    """Unit test for the IsotopeID class."""

    def test_values( self ) :

      id = IsotopeID( 1, 1 )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 1, id.mass )
      self.assertEqual( 1001, id.za )
      self.assertEqual( 'H1', id.symbol )
      self.assertEqual( 'H1', id.name )

      id = IsotopeID( 1001 )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 1, id.mass )
      self.assertEqual( 1001, id.za )
      self.assertEqual( 'H1', id.symbol )
      self.assertEqual( 'H1', id.name )

      id = IsotopeID( 'H1' )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 1, id.mass )
      self.assertEqual( 1001, id.za )
      self.assertEqual( 'H1', id.symbol )
      self.assertEqual( 'H1', id.name )

      id = IsotopeID( 'h1' )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 1001, id.za )
      self.assertEqual( 1, id.mass )
      self.assertEqual( 'H1', id.symbol )
      self.assertEqual( 'H1', id.name )

      id = IsotopeID( 1, 0 )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 0, id.mass )
      self.assertEqual( 1000, id.za )
      self.assertEqual( 'H0', id.symbol )
      self.assertEqual( 'H0', id.name )

      id = IsotopeID( 1000 )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 0, id.mass )
      self.assertEqual( 1000, id.za )
      self.assertEqual( 'H0', id.symbol )
      self.assertEqual( 'H0', id.name )

      id = IsotopeID( 'H0' )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 0, id.mass )
      self.assertEqual( 1000, id.za )
      self.assertEqual( 'H0', id.symbol )
      self.assertEqual( 'H0', id.name )

      id = IsotopeID( 'h0' )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 0, id.mass )
      self.assertEqual( 1000, id.za )
      self.assertEqual( 'H0', id.symbol )
      self.assertEqual( 'H0', id.name )

      id = IsotopeID( 'H' )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 0, id.mass )
      self.assertEqual( 1000, id.za )
      self.assertEqual( 'H0', id.symbol )
      self.assertEqual( 'H0', id.name )

      id = IsotopeID( 'h' )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 0, id.mass )
      self.assertEqual( 1000, id.za )
      self.assertEqual( 'H0', id.symbol )
      self.assertEqual( 'H0', id.name )

    def test_comparison( self ) :

        id1 = IsotopeID( 'H1' )
        id2 = IsotopeID( 'He4' )

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

        id1 = IsotopeID( 'n' )
        id2 = IsotopeID( 'p' )

        map = { id1 : '1', id2 : '2' }

        self.assertEqual( map[ id1 ], '1' )
        self.assertEqual( map[ id2 ], '2' )
        self.assertEqual( map[ IsotopeID( 'n' ) ], '1' )
        self.assertEqual( map[ IsotopeID( 'p' ) ], '2' )

    def test_failures( self ) :

        # illegal values
        with self.assertRaises( ValueError ) : id = IsotopeID( -1, 0 )
        with self.assertRaises( ValueError ) : id = IsotopeID( 1, -1 )
        with self.assertRaises( ValueError ) : id = IsotopeID( 119, 1 )
        with self.assertRaises( ValueError ) : id = IsotopeID( 1, 400 )
        with self.assertRaises( ValueError ) : id = IsotopeID( 0 )
        with self.assertRaises( ValueError ) : id = IsotopeID( 119000 )
        with self.assertRaises( ValueError ) : id = IsotopeID( 1400 )
        with self.assertRaises( ValueError ) : id = IsotopeID( -1 )
        with self.assertRaises( ValueError ) : id = IsotopeID( 'not an isotope' )
        with self.assertRaises( ValueError ) : id = IsotopeID( 'H400' )

if __name__ == '__main__' :

    unittest.main()
