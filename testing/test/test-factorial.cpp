#include "catch.hpp"
#include "../factorial.h"

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
}

TEST_CASE("Zero factorial is 1", "[factorial]") {
    REQUIRE(Factorial(0) == 1);
}


TEST_CASE("nEGATIVE NUMBER FACTORIAL", "[FACTORIAL]") {
    REQUIRE(Factorial(-1) == 0);
}
