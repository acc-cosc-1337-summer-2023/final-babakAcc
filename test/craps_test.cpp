#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("test case to assert die rolls return a value from 1 to 6")
{
	Die die;
	for(int i = 0; i < 10; i++)
	{
		die.roll();
		REQUIRE(die.rolled_value() >= 1);
		REQUIRE(die.rolled_value() <= 6);
	}
}

TEST_CASE("Test case to assert die rolls return a value from 2 to 12")
{
	Die die1, die2;

	Roll roll(die1, die2);
	
	for(int i = 0; i < 10; i++) 
	{
		roll.roll_die();
		REQUIRE(roll.roll_value() >= 2);
		REQUIRE(roll.roll_value() <= 12);
	}

}