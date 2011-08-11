#include <stdint.h>
#include <time.h>

#include <cppunit/extensions/HelperMacros.h>
#include <string.h>
#include <list>
#include <common.h>
#include <bfs.h>

using namespace std;

class BfsTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( BfsTest );
    CPPUNIT_TEST( test_create_peg );
    CPPUNIT_TEST_SUITE_END( );

    public:
	void test_bfs()	{
		Bfs bfs;
		auto_ptr< Bfs > bfs( new Bfs( A,G ) );
		cout<<"Testing Bfs :Peg, for creating a PEG and checking its state: ";
		/* //usage
		CPPUNIT_ASSERT_EQUAL( ,  );	
		*/
		cout<<"PASS"<<endl;	
	}

};

CPPUNIT_TEST_SUITE_REGISTRATION( BfsTest );
