# standard imports
import unittest

# third party imports

# local imports
from elementary import NuclideID
from elementary import Level
from elementary import ElementID
from elementary import IsotopeID

class Test_elementary_NuclideID( unittest.TestCase ) :
    """Unit test for the NuclideID class."""

    def test_values( self ) :

      id = NuclideID( 1, 1, 0 )
      self.assertEqual( IsotopeID( 1, 1 ), id.isotope )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 1, id.mass )
      self.assertEqual( Level( 0 ), id.level )
      self.assertEqual( 1001, id.za )
      self.assertEqual( 'H1', id.symbol )
      self.assertEqual( 'H1', id.name )

      id = NuclideID( 1001, 0 )
      self.assertEqual( IsotopeID( 1, 1 ), id.isotope )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 1, id.mass )
      self.assertEqual( Level( 0 ), id.level )
      self.assertEqual( 1001, id.za )
      self.assertEqual( 'H1', id.symbol )
      self.assertEqual( 'H1', id.name )

      id = NuclideID( 'H1' )
      self.assertEqual( IsotopeID( 1, 1 ), id.isotope )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 1, id.mass )
      self.assertEqual( Level( 0 ), id.level )
      self.assertEqual( 1001, id.za )
      self.assertEqual( 'H1', id.symbol )
      self.assertEqual( 'H1', id.name )

      id = NuclideID( 'H1_e0' )
      self.assertEqual( IsotopeID( 1, 1 ), id.isotope )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 1, id.mass )
      self.assertEqual( Level( 0 ), id.level )
      self.assertEqual( 1001, id.za )
      self.assertEqual( 'H1', id.symbol )
      self.assertEqual( 'H1', id.name )

      id = NuclideID( 1, 1, 1 )
      self.assertEqual( IsotopeID( 1, 1 ), id.isotope )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 1, id.mass )
      self.assertEqual( Level( 1 ), id.level )
      self.assertEqual( 1001, id.za )
      self.assertEqual( 'H1_e1', id.symbol )
      self.assertEqual( 'H1_e1', id.name )

      id = NuclideID( 1001, 1 )
      self.assertEqual( IsotopeID( 1, 1 ), id.isotope )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 1, id.mass )
      self.assertEqual( Level( 1 ), id.level )
      self.assertEqual( 1001, id.za )
      self.assertEqual( 'H1_e1', id.symbol )
      self.assertEqual( 'H1_e1', id.name )

      id = NuclideID( 'H1_e1' )
      self.assertEqual( IsotopeID( 1, 1 ), id.isotope )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 1, id.mass )
      self.assertEqual( Level( 1 ), id.level )
      self.assertEqual( 1001, id.za )
      self.assertEqual( 'H1_e1', id.symbol )
      self.assertEqual( 'H1_e1', id.name )

      id = NuclideID( 1, 0, 0 )
      self.assertEqual( IsotopeID( 1, 0 ), id.isotope )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 0, id.mass )
      self.assertEqual( Level( 0 ), id.level )
      self.assertEqual( 1000, id.za )
      self.assertEqual( 'H0', id.symbol )
      self.assertEqual( 'H0', id.name )

      id = NuclideID( 'H0' )
      self.assertEqual( IsotopeID( 1, 0 ), id.isotope )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 0, id.mass )
      self.assertEqual( Level( 0 ), id.level )
      self.assertEqual( 1000, id.za )
      self.assertEqual( 'H0', id.symbol )
      self.assertEqual( 'H0', id.name )

      continuum = Level.continuum;

      id = NuclideID( 1, 1, continuum )
      self.assertEqual( IsotopeID( 1, 1 ), id.isotope )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 1, id.mass )
      self.assertEqual( Level( continuum ), id.level )
      self.assertEqual( 1001, id.za )
      self.assertEqual( 'H1[continuum]', id.symbol )
      self.assertEqual( 'H1[continuum]', id.name )

      id = NuclideID( 1001, continuum )
      self.assertEqual( IsotopeID( 1, 1 ), id.isotope )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 1, id.mass )
      self.assertEqual( Level( continuum ), id.level )
      self.assertEqual( 1001, id.za )
      self.assertEqual( 'H1[continuum]', id.symbol )
      self.assertEqual( 'H1[continuum]', id.name )

      id = NuclideID( 'H1[continuum]' )
      self.assertEqual( IsotopeID( 1, 1 ), id.isotope )
      self.assertEqual( ElementID( 1 ), id.element )
      self.assertEqual( 1, id.mass )
      self.assertEqual( Level( continuum ), id.level )
      self.assertEqual( 1001, id.za )
      self.assertEqual( 'H1[continuum]', id.symbol )
      self.assertEqual( 'H1[continuum]', id.name )

    def test_comparison( self ) :

        id1 = NuclideID( 'H1' )
        id2 = NuclideID( 'He4' )

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

        id1 = NuclideID( 'H1' )
        id2 = NuclideID( 'He4' )

        map = { id1 : '1', id2 : '2' }

        self.assertEqual( map[ id1 ], '1' )
        self.assertEqual( map[ id2 ], '2' )
        self.assertEqual( map[ NuclideID( 'H1' ) ], '1' )
        self.assertEqual( map[ NuclideID( 'He4' ) ], '2' )

    def test_failures( self ) :

        # illegal values
        with self.assertRaises( ValueError ) : id = NuclideID( -1, 0, 0 )
        with self.assertRaises( ValueError ) : id = NuclideID( 1, -1, 0 )
        with self.assertRaises( ValueError ) : id = NuclideID( 119, 1, 0 )
        with self.assertRaises( ValueError ) : id = NuclideID( 1, 400, 0 )
        with self.assertRaises( ValueError ) : id = NuclideID( 0, 0 )
        with self.assertRaises( ValueError ) : id = NuclideID( -1, 0 )
        with self.assertRaises( ValueError ) : id = NuclideID( 'not an nuclide' )
        with self.assertRaises( ValueError ) : id = NuclideID( 'h400' )

if __name__ == '__main__' :

    unittest.main()
