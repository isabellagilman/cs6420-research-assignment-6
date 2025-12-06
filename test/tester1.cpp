#define CATCH_CONFIG_MAIN // Tells Catch2 to provide a main() function
#include <catch2/catch_all.hpp>
#include <fstream>
#include <string>
#include <iostream>
#include "alg_twoway.h"

using namespace std;

TEST_CASE("Basic", "[Test]")
{
	string pattern = "5";
 	string text = "0123456789";

  	vector<int> tw_matches = TwoWayMatch(pattern, text);

	CHECK(tw_matches[0] == 5);
}

TEST_CASE("Edges", "[Test]")
{
 	string text = "0123456789";

	string pattern = "0";
  	vector<int> tw_matches = TwoWayMatch(pattern, text);
	CHECK(tw_matches[0] == 0);

	pattern = "9";
  	tw_matches = TwoWayMatch(pattern, text);
	CHECK(tw_matches[0] == 9);
}

TEST_CASE("Multi-Character Pattern", "[Test]")
{
 	string text = "0123456789";

	string pattern = "456";
  	vector<int> tw_matches = TwoWayMatch(pattern, text);
	CHECK(tw_matches[0] == 4);
}

TEST_CASE("Pattern with repetitions", "[Test]")
{
 	string text = "01234567abaabaabaab89";

	string pattern = "abaabaabaab";
  	vector<int> tw_matches = TwoWayMatch(pattern, text);
	CHECK(tw_matches[0] == 8);
}

TEST_CASE("Multiple Matches", "[Test]")
{
 	string text = "012345a7890a2345a789";

	string pattern = "a";
  	vector<int> tw_matches = TwoWayMatch(pattern, text);
	CHECK(tw_matches[0] == 6);
	CHECK(tw_matches[1] == 11);
	CHECK(tw_matches[2] == 16);
}