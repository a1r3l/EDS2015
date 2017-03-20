#include <MiniCppUnit.hxx>
#include "Location.hxx"

class LocationTest : public TestFixture< LocationTest >
{
public:
	TEST_FIXTURE( LocationTest )
	{
		TEST_CASE( test_name_byDefault );
		TEST_CASE( test_name_whenChanged );
		TEST_CASE( test_description_whenEmpty );
		
		//Tests unitarios nuevos, creados 
		TEST_CASE( test_connections_whenNotConnected);
		TEST_CASE( test_connections_whenConnectedAtSouth);
		TEST_CASE( test_connections_whenConnectedAtNorth);
		TEST_CASE( test_description_whenConnectedNorthSouth);
		TEST_CASE( test_connections_whenConnectedAtEast);
		TEST_CASE( test_connections_whenConnectedAtWest);
		TEST_CASE( test_description_whenConnectedEastWest);
	}

	void test_name_byDefault()
	{
		Location location;
		ASSERT_EQUALS(
			"unknown",
			location.name()
		);
	}
	void test_name_whenChanged()
	{
		Location location;
		location.name( "A location" );
		ASSERT_EQUALS(
			"A location",
			location.name()
		);
	}
	void test_description_whenEmpty()
	{
		Location location;
		location.name( "A location" );
		ASSERT_EQUALS(
			"Location: A location\n",
			location.description()
		);
	}
	//TEST UNITARIOS CREADOS
	void test_connections_whenNotConnected(){
		Location location;
		Location location2;

		location.name( "Madrid" );
		location2.name("Bilbao");

		ASSERT_EQUALS(
			"Location: Madrid\n",
			location.description()
		);	

	}
	
	void test_connections_whenConnectedAtSouth(){
		Location location;
		Location location2;

		location.name( "Madrid" );
		location2.name("Bilbao");
		location.connectSouth(&location2);

		ASSERT_EQUALS(
			"Location: Madrid\n"
			"\tSouth: Bilbao\n",
			location.description()
			);
	}
	
	void test_connections_whenConnectedAtNorth(){
		Location location;
		Location location2;

		location.name( "Madrid" );
		location2.name("Bilbao");
		location.connectNorth(&location2);

		ASSERT_EQUALS(
			"Location: Madrid\n"
			"\tNorth: Bilbao\n",
			location.description()
			);	
	}
	void test_description_whenConnectedNorthSouth(){
		Location location;
		Location location2;
		Location location3;

		location.name( "Madrid" );
		location2.name("Bilbao");
		location3.name("Sevilla");
		location.connectNorth(&location2);
		location.connectSouth(&location3);
		ASSERT_EQUALS(
			"Location: Madrid\n"
			"\tNorth: Bilbao\n"
			"\tSouth: Sevilla\n",
			location.description()
			);
		
	}

	void test_connections_whenConnectedAtEast(){
		Location location;
		Location location2;

		location.name( "Madrid" );
		location2.name("Barcelona");
		location.connectEast(&location2);

		ASSERT_EQUALS(
			"Location: Madrid\n"
			"\tEast: Barcelona\n",
			location.description()
			);
	}
	void test_connections_whenConnectedAtWest(){

		Location location;
		Location location2;

		location.name( "Madrid" );
		location2.name("Salamanca");
		location.connectWest(&location2);

		ASSERT_EQUALS(
			"Location: Madrid\n"
			"\tWest: Salamanca\n",
			location.description()
			);
	}
	void test_description_whenConnectedEastWest(){

		Location location;
		Location location2;
		Location location3;

		location.name( "Madrid" );
		location2.name("Barcelona");
		location3.name("Salamanca");
		location.connectEast(&location2);
		location.connectWest(&location3);
		ASSERT_EQUALS(
			"Location: Madrid\n"
			"\tEast: Barcelona\n"
			"\tWest: Salamanca\n",
			location.description()
			);
	}
};
REGISTER_FIXTURE( LocationTest )
