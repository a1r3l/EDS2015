#include <MiniCppUnit.hxx>
#include "Item.hxx"

class ItemTest : public TestFixture< ItemTest >
{
public:
	TEST_FIXTURE( ItemTest )
	{
		TEST_CASE( test_name_byDefault );
		TEST_CASE( test_name_whenChanged );
		TEST_CASE( test_levelRequired_byDefault );
		TEST_CASE( test_levelRequired_whenChanged );
		TEST_CASE( test_itemState_byDefault );
		TEST_CASE( test_itemState_whenDisabled );
		TEST_CASE( test_itemState_whenEnabled );
	}

	void test_name_byDefault()
	{
		Item item;
		ASSERT_EQUALS(
			"unknown",
			item.name()
		);
	}
	
	void test_name_whenChanged()
	{
		Item item;
		item.name( "Umbral Masterblade" );
		ASSERT_EQUALS(
			"Umbral Masterblade",
			item.name()
		);
	}
	void test_levelRequired_byDefault()
	{
		Item item;
		ASSERT_EQUALS(
			0u,
			item.level()
		);
	}
	
	void test_levelRequired_whenChanged()
	{
		Item item;
		item.level(50);
		ASSERT_EQUALS(
			50u,
			item.level()
		);
	}
		void test_itemState_byDefault()
	{
		Item item;
		ASSERT_EQUALS(
			true,
			item.itsEnable()
		);
	}
	
	void test_itemState_whenDisabled()
	{
		Item item;
		item.disable();
		ASSERT_EQUALS(
			false,
			item.itsEnable()
		);
	}
	
	void test_itemState_whenEnabled()
	{
		Item item;
		item.enable();
		ASSERT_EQUALS(
			true,
			item.itsEnable()
		);
	}
	
};

REGISTER_FIXTURE( ItemTest )
