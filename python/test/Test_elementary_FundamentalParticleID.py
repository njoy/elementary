# standard imports
import unittest

# third party imports

# local imports
from elementary import FundamentalParticleID

class Test_elementary_FundamentalParticleID( unittest.TestCase ) :
    """Unit test for the FundamentalParticleID class."""

    symbols = [ 'photon', 'n', 'p' ]
    names = [ 'photon', 'neutron', 'proton' ]
    numbers = [ 0, 1, 1001 ]

    alternatives = { 'g' : 0, 'gamma' : 0, 'x-ray' : 0 }

    def test_values( self ) :

        for i in range( len( self.symbols ) ) :

            id = FundamentalParticleID( self.symbols[i] )
            self.assertEqual( id.symbol, self.symbols[i] )
            self.assertEqual( id.name, self.names[i] )
            self.assertEqual( id.za, self.numbers[i] )

            id = FundamentalParticleID( self.symbols[i].lower() )
            self.assertEqual( id.symbol, self.symbols[i] )
            self.assertEqual( id.name, self.names[i] )
            self.assertEqual( id.za, self.numbers[i] )

            id = FundamentalParticleID( self.symbols[i].upper() )
            self.assertEqual( id.symbol, self.symbols[i] )
            self.assertEqual( id.name, self.names[i] )
            self.assertEqual( id.za, self.numbers[i] )

            id = FundamentalParticleID( self.names[i] )
            self.assertEqual( id.symbol, self.symbols[i] )
            self.assertEqual( id.name, self.names[i] )
            self.assertEqual( id.za, self.numbers[i] )

            id = FundamentalParticleID( self.names[i].lower() )
            self.assertEqual( id.symbol, self.symbols[i] )
            self.assertEqual( id.name, self.names[i] )
            self.assertEqual( id.za, self.numbers[i] )

            id = FundamentalParticleID( self.names[i].upper() )
            self.assertEqual( id.symbol, self.symbols[i] )
            self.assertEqual( id.name, self.names[i] )
            self.assertEqual( id.za, self.numbers[i] )

        for alternative, i in self.alternatives.items() :

            id = FundamentalParticleID( alternative )
            self.assertEqual( id.symbol, self.symbols[i] )
            self.assertEqual( id.name, self.names[i] )
            self.assertEqual( id.za, self.numbers[i] )

            id = FundamentalParticleID( alternative.lower() )
            self.assertEqual( id.symbol, self.symbols[i] )
            self.assertEqual( id.name, self.names[i] )
            self.assertEqual( id.za, self.numbers[i] )

            id = FundamentalParticleID( alternative.upper() )
            self.assertEqual( id.symbol, self.symbols[i] )
            self.assertEqual( id.name, self.names[i] )
            self.assertEqual( id.za, self.numbers[i] )

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

        map = { id1 : '1', id2 : '2' }

        self.assertEqual( map[ id1 ], '1' )
        self.assertEqual( map[ id2 ], '2' )
        self.assertEqual( map[ FundamentalParticleID( 'n' ) ], '1' )
        self.assertEqual( map[ FundamentalParticleID( 'p' ) ], '2' )

    def test_failures( self ) :

        # illegal values
        with self.assertRaises( ValueError ) :

            id = FundamentalParticleID( 'not a fundamental particle name, '
                                        'symbol or alternative' )

if __name__ == '__main__' :

    unittest.main()
