# standard imports
import unittest

# third party imports

# local imports
from elementary import FundamentalParticleID

class Test_elementary_FundamentalParticleID( unittest.TestCase ) :
    """Unit test for the FundamentalParticleID class."""

    def test_constructors( self ) :

        id = FundamentalParticleID( 'n' )
        self.assertEqual( 'n', id.symbol )
        self.assertEqual( 'neutron', id.name )
        self.assertEqual( 1, id.za )

        id = FundamentalParticleID( 'photon' )
        self.assertEqual( 'photon', id.symbol )
        self.assertEqual( 'photon', id.name )
        self.assertEqual( 0, id.za )

        id = FundamentalParticleID( 'g' )
        self.assertEqual( 'photon', id.symbol )
        self.assertEqual( 'photon', id.name )
        self.assertEqual( 0, id.za )

        id = FundamentalParticleID( 'gamma' )
        self.assertEqual( 'photon', id.symbol )
        self.assertEqual( 'photon', id.name )
        self.assertEqual( 0, id.za )

        id = FundamentalParticleID( 'GAMMA' )
        self.assertEqual( 'photon', id.symbol )
        self.assertEqual( 'photon', id.name )
        self.assertEqual( 0, id.za )

        id = FundamentalParticleID( 'x-ray' )
        self.assertEqual( 'photon', id.symbol )
        self.assertEqual( 'photon', id.name )
        self.assertEqual( 0, id.za )

    def test_comparison( self ) :

        id1 = FundamentalParticleID( 'n' )
        id2 = FundamentalParticleID( 'p' )

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

        id1 = FundamentalParticleID( 'n' )
        id2 = FundamentalParticleID( 'p' )

        map = { id1 : "1", id2 : "2" }

        self.assertEqual( map[ id1 ], "1" )
        self.assertEqual( map[ id2 ], "2" )
        self.assertEqual( map[ FundamentalParticleID( 'n' ) ], "1" )
        self.assertEqual( map[ FundamentalParticleID( 'p' ) ], "2" )

    def test_failures( self ) :

        # illegal values
        with self.assertRaises( ValueError ) :

            id = FundamentalParticleID( 'not a fundamental particle name, '
                                        'symbol or alternative' )

if __name__ == '__main__' :

    unittest.main()
