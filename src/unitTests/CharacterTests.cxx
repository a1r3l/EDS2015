#include <MiniCppUnit.hxx>
#include "Character.hxx"
#include "Location.hxx"
class CharacterTest : public TestFixture< CharacterTest >
{
public:
	TEST_FIXTURE( CharacterTest )
	{
		TEST_CASE( test_name_byDefault );
		TEST_CASE( test_name_whenChanged );
		TEST_CASE( test_level_byDefault );
		TEST_CASE( test_level_whenChanged );
		TEST_CASE( test_life_byDefault );
		TEST_CASE( test_life_afterDamage );
		TEST_CASE( test_life_afterCure );
		TEST_CASE( test_life_afterDamageBeyondLife );
		TEST_CASE( test_life_afterCuringBeyondMax );
		TEST_CASE( test_locateAt_whenNoPreviousLocation);
		TEST_CASE(test_locateAt_whenPreviousLocation);
	}
	void test_name_byDefault()
	{
		Character anonymous;
		ASSERT_EQUALS(
			"unknown",
			anonymous.name()
		);
	}
	void test_name_whenChanged()
	{
		Character character;
		character.name( "Peter" );
		ASSERT_EQUALS(
			"Peter",
			character.name()
		);
	}
	void test_level_byDefault()
	{
		Character character;
		ASSERT_EQUALS(
			0u,
			character.level()
		);
	}
	void test_level_whenChanged()
	{
		Character character;
		character.level( 40 );
		ASSERT_EQUALS(
			40u,
			character.level()
		);
	}
	void test_life_byDefault()
	{
		Character character;
		ASSERT_EQUALS(
			10u,
			character.life()
		);
	}
	void test_life_afterDamage()
	{
		Character character;
		character.damage( 4u );
		ASSERT_EQUALS(
			6u,
			character.life()
		);
	}
	void test_life_afterCure()
	{
		Character character;
		character.damage( 4u );
		character.cure( 4u );
		ASSERT_EQUALS(
			10u,
			character.life()
		);
	}
	void test_life_afterDamageBeyondLife()
	{
		Character character;
		character.damage( 15u );
		ASSERT_EQUALS(
			0u,
			character.life()
		);
	}
	void test_life_afterCuringBeyondMax()
	{
		Character character;
		character.cure( 1u );
		ASSERT_EQUALS(
			10u,
			character.life()
		);
	}
	
	void test_locateAt_whenNoPreviousLocation(){

		Character character;
		character.name("AK47");

		Location location;
		location.name("Batllefield");
		character.locateAt(location);

		ASSERT_EQUALS(
			"Location: Batllefield\n"
			"- AK47 is here.\n",
			location.description()
		);

	}
	void test_locateAt_whenPreviousLocation(){

		Character character;
		character.name("AK47");

		Location location;
		location.name("Batllefield");

		Location location2;
		location2.name("Batllefield2");

		character.locateAt(location);
		character.locateAt(location2);

		ASSERT_EQUALS(
			"Location: Batllefield\n"
			"Location: Batllefield2\n"
			"- AK47 is here.\n",
			location.description()+location2.description()
		);
	}
};

REGISTER_FIXTURE( CharacterTest )

