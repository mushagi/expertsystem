#include <string>

#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"
#include "expertsystem.hpp"

TEST_CASE( "simple" )
{
	int res = 1;
 	REQUIRE( res == 0);
}
