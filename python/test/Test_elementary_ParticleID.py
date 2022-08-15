# standard imports
import unittest

# third party imports

# local imports
from elementary import ParticleID
from elementary import FundamentalParticleID
from elementary import NucleusID
from elementary import NuclideID
from elementary import Level

class Test_elementary_ParticleID( unittest.TestCase ) :
    """Unit test for the ParticleID class."""

    def test_values( self ) :

      id = ParticleID( FundamentalParticleID( 'n' ) );
      self.assertEqual( 'n', id.symbol )
      self.assertEqual( 'neutron', id.name )
      self.assertEqual( 1, id.za )
      self.assertEqual( Level( 0 ), id.level )
      self.assertEqual( True, id.is_fundamental_particle )
      self.assertEqual( False, id.is_nucleus )
      self.assertEqual( False, id.is_nuclide )

      id = ParticleID( 'n' );
      self.assertEqual( 'n', id.symbol )
      self.assertEqual( 'neutron', id.name )
      self.assertEqual( 1, id.za )
      self.assertEqual( Level( 0 ), id.level )
      self.assertEqual( True, id.is_fundamental_particle )
      self.assertEqual( False, id.is_nucleus )
      self.assertEqual( False, id.is_nuclide )

      id = ParticleID( NucleusID( 'h2' ) );
      self.assertEqual( 'h2', id.symbol )
      self.assertEqual( 'h2', id.name )
      self.assertEqual( 1002, id.za )
      self.assertEqual( Level( 0 ), id.level )
      self.assertEqual( False, id.is_fundamental_particle )
      self.assertEqual( True, id.is_nucleus )
      self.assertEqual( False, id.is_nuclide )

      id = ParticleID( 'h2' );
      self.assertEqual( 'h2', id.symbol )
      self.assertEqual( 'h2', id.name )
      self.assertEqual( 1002, id.za )
      self.assertEqual( Level( 0 ), id.level )
      self.assertEqual( False, id.is_fundamental_particle )
      self.assertEqual( True, id.is_nucleus )
      self.assertEqual( False, id.is_nuclide )

      id = ParticleID( NucleusID( 'h2_e1' ) );
      self.assertEqual( 'h2_e1', id.symbol )
      self.assertEqual( 'h2_e1', id.name )
      self.assertEqual( 1002, id.za )
      self.assertEqual( Level( 1 ), id.level )
      self.assertEqual( False, id.is_fundamental_particle )
      self.assertEqual( True, id.is_nucleus )
      self.assertEqual( False, id.is_nuclide )

      id = ParticleID( 'h2_e1' );
      self.assertEqual( 'h2_e1', id.symbol )
      self.assertEqual( 'h2_e1', id.name )
      self.assertEqual( 1002, id.za )
      self.assertEqual( Level( 1 ), id.level )
      self.assertEqual( False, id.is_fundamental_particle )
      self.assertEqual( True, id.is_nucleus )
      self.assertEqual( False, id.is_nuclide )

      id = ParticleID( NuclideID( 'H2' ) );
      self.assertEqual( 'H2', id.symbol )
      self.assertEqual( 'H2', id.name )
      self.assertEqual( 1002, id.za )
      self.assertEqual( Level( 0 ), id.level )
      self.assertEqual( False, id.is_fundamental_particle )
      self.assertEqual( False, id.is_nucleus )
      self.assertEqual( True, id.is_nuclide )

      id = ParticleID( 'H2' );
      self.assertEqual( 'H2', id.symbol )
      self.assertEqual( 'H2', id.name )
      self.assertEqual( 1002, id.za )
      self.assertEqual( Level( 0 ), id.level )
      self.assertEqual( False, id.is_fundamental_particle )
      self.assertEqual( False, id.is_nucleus )
      self.assertEqual( True, id.is_nuclide )

      id = ParticleID( NuclideID( 'H2_e1' ) );
      self.assertEqual( 'H2_e1', id.symbol )
      self.assertEqual( 'H2_e1', id.name )
      self.assertEqual( 1002, id.za )
      self.assertEqual( Level( 1 ), id.level )
      self.assertEqual( False, id.is_fundamental_particle )
      self.assertEqual( False, id.is_nucleus )
      self.assertEqual( True, id.is_nuclide )

      id = ParticleID( 'H2_e1' );
      self.assertEqual( 'H2_e1', id.symbol )
      self.assertEqual( 'H2_e1', id.name )
      self.assertEqual( 1002, id.za )
      self.assertEqual( Level( 1 ), id.level )
      self.assertEqual( False, id.is_fundamental_particle )
      self.assertEqual( False, id.is_nucleus )
      self.assertEqual( True, id.is_nuclide )

    def test_comparison( self ) :

        id1 = ParticleID( 'n' )
        id2 = ParticleID( 'he4' )

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

        id1 = ParticleID( 'he4' )
        id2 = ParticleID( 'He4' )

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

        id1 = ParticleID( 'He4_e5' )
        id2 = ParticleID( 'He4[continuum]' )

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

        id1 = ParticleID( 'n' )
        id2 = ParticleID( 'he4' )

        map = { id1 : '1', id2 : '2' }

        self.assertEqual( map[ id1 ], '1' )
        self.assertEqual( map[ id2 ], '2' )
        self.assertEqual( map[ ParticleID( 'n' ) ], '1' )
        self.assertEqual( map[ ParticleID( 'he4' ) ], '2' )

    def test_failures( self ) :

        # illegal values
        with self.assertRaises( ValueError ) : id = ParticleID( 'not an nuclide' )
        with self.assertRaises( ValueError ) : id = ParticleID( 'H400' )
        with self.assertRaises( ValueError ) : id = ParticleID( 'h400' )

if __name__ == '__main__' :

    unittest.main()
