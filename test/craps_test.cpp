#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"

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

TEST_CASE("Test that shooter returns a Roll and verify that the roll result has one of the following values: 2-12")
{
	Die die1, die2;
	Shooter shooter;

	for(int i=0; i < 10; i++)
	{
		Roll* roll = shooter.throw_die(die1, die2);
		
		REQUIRE(roll->roll_value() >= 2);
		REQUIRE(roll->roll_value() <= 12);
		
	}
}

TEST_CASE("Test Come Out Phase")
{
	Die die1, die2;
	Shooter shooter;

	ComeOutPhase come_out_phase;

	for(int i = 0; i < 10; i++)
	{
		Roll* roll = shooter.throw_die(die1, die2);
		RollOutcome outcome = come_out_phase.get_outcome(roll);

		REQUIRE((outcome == RollOutcome::natural || outcome == RollOutcome::craps || outcome == RollOutcome::point));
	}
}

TEST_CASE("Test Point Phase")
{
	Die die1, die2;
	Shooter shooter;

	PointPhase point_phase(1);

	for(int i = 0; i < 10; i++)
	{
		Roll* roll = shooter.throw_die(die1, die2);
		RollOutcome outcome = point_phase.get_outcome(roll);

		REQUIRE((outcome == RollOutcome::point || outcome == RollOutcome::seven_out || outcome == RollOutcome::nopoint));
	}
}