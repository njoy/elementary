# standard imports
import unittest

# third party imports

# local imports
from elementary import NucleusID
from elementary import Level
from elementary import ElementID
from elementary import IsotopeID

class Test_elementary_NucleusID( unittest.TestCase ) :
    """Unit test for the NucleusID class."""

    def test_values( self ) :

      id = NucleusID( 1, 1, 0 )
      self.assertEqual( IsotopeID( 1, 1 ), id.isotope )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 1, id.mass )
      self.assertEqual( Level( 0 ), id.level )
      self.assertEqual( 1001, id.za )
      self.assertEqual( 'h1', id.symbol )
      self.assertEqual( 'h1', id.name )

      id = NucleusID( 1001, 0 )
      self.assertEqual( IsotopeID( 1, 1 ), id.isotope )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 1, id.mass )
      self.assertEqual( Level( 0 ), id.level )
      self.assertEqual( 1001, id.za )
      self.assertEqual( 'h1', id.symbol )
      self.assertEqual( 'h1', id.name )

      id = NucleusID( 'h1' )
      self.assertEqual( IsotopeID( 1, 1 ), id.isotope )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 1, id.mass )
      self.assertEqual( Level( 0 ), id.level )
      self.assertEqual( 1001, id.za )
      self.assertEqual( 'h1', id.symbol )
      self.assertEqual( 'h1', id.name )

      id = NucleusID( 'h1_e0' )
      self.assertEqual( IsotopeID( 1, 1 ), id.isotope )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 1, id.mass )
      self.assertEqual( Level( 0 ), id.level )
      self.assertEqual( 1001, id.za )
      self.assertEqual( 'h1', id.symbol )
      self.assertEqual( 'h1', id.name )

      id = NucleusID( 1, 1, 1 )
      self.assertEqual( IsotopeID( 1, 1 ), id.isotope )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 1, id.mass )
      self.assertEqual( Level( 1 ), id.level )
      self.assertEqual( 1001, id.za )
      self.assertEqual( 'h1_e1', id.symbol )
      self.assertEqual( 'h1_e1', id.name )

      id = NucleusID( 1001, 1 )
      self.assertEqual( IsotopeID( 1, 1 ), id.isotope )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 1, id.mass )
      self.assertEqual( Level( 1 ), id.level )
      self.assertEqual( 1001, id.za )
      self.assertEqual( 'h1_e1', id.symbol )
      self.assertEqual( 'h1_e1', id.name )

      id = NucleusID( 'h1_e1' )
      self.assertEqual( IsotopeID( 1, 1 ), id.isotope )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 1, id.mass )
      self.assertEqual( Level( 1 ), id.level )
      self.assertEqual( 1001, id.za )
      self.assertEqual( 'h1_e1', id.symbol )
      self.assertEqual( 'h1_e1', id.name )

      id = NucleusID( 1, 0, 0 )
      self.assertEqual( IsotopeID( 1, 0 ), id.isotope )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 0, id.mass )
      self.assertEqual( Level( 0 ), id.level )
      self.assertEqual( 1000, id.za )
      self.assertEqual( 'h0', id.symbol )
      self.assertEqual( 'h0', id.name )

      id = NucleusID( 'h0' )
      self.assertEqual( IsotopeID( 1, 0 ), id.isotope )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 0, id.mass )
      self.assertEqual( Level( 0 ), id.level )
      self.assertEqual( 1000, id.za )
      self.assertEqual( 'h0', id.symbol )
      self.assertEqual( 'h0', id.name )

      continuum = Level.continuum;

      id = NucleusID( 1, 1, continuum )
      self.assertEqual( IsotopeID( 1, 1 ), id.isotope )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 1, id.mass )
      self.assertEqual( Level( continuum ), id.level )
      self.assertEqual( 1001, id.za )
      self.assertEqual( 'h1[continuum]', id.symbol )
      self.assertEqual( 'h1[continuum]', id.name )

      id = NucleusID( 1001, continuum )
      self.assertEqual( IsotopeID( 1, 1 ), id.isotope )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 1, id.mass )
      self.assertEqual( Level( continuum ), id.level )
      self.assertEqual( 1001, id.za )
      self.assertEqual( 'h1[continuum]', id.symbol )
      self.assertEqual( 'h1[continuum]', id.name )

      id = NucleusID( 'h1[continuum]' )
      self.assertEqual( IsotopeID( 1, 1 ), id.isotope )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 1, id.mass )
      self.assertEqual( Level( continuum ), id.level )
      self.assertEqual( 1001, id.za )
      self.assertEqual( 'h1[continuum]', id.symbol )
      self.assertEqual( 'h1[continuum]', id.name )

    def test_comparison( self ) :

        id1 = NucleusID( 'h1' )
        id2 = NucleusID( 'he4' )

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

        id1 = NucleusID( 'h1' )
        id2 = NucleusID( 'he4' )

        map = { id1 : '1', id2 : '2' }

        self.assertEqual( map[ id1 ], '1' )
        self.assertEqual( map[ id2 ], '2' )
        self.assertEqual( map[ NucleusID( 'h1' ) ], '1' )
        self.assertEqual( map[ NucleusID( 'he4' ) ], '2' )

    def test_failures( self ) :

        # illegal values
        with self.assertRaises( ValueError ) : id = NucleusID( -1, 0, 0 )
        with self.assertRaises( ValueError ) : id = NucleusID( 1, -1, 0 )
        with self.assertRaises( ValueError ) : id = NucleusID( 119, 1, 0 )
        with self.assertRaises( ValueError ) : id = NucleusID( 1, 400, 0 )
        with self.assertRaises( ValueError ) : id = NucleusID( 0, 0 )
        with self.assertRaises( ValueError ) : id = NucleusID( -1, 0 )
        with self.assertRaises( ValueError ) : id = NucleusID( 'not an nuclide' )
        with self.assertRaises( ValueError ) : id = NucleusID( 'H1' )
        with self.assertRaises( ValueError ) : id = NucleusID( 'h400' )

if __name__ == '__main__' :

    unittest.main()
