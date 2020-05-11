#include "catch.hpp"
#include "../search.h"


TEST_CASE("Testing tests","[search]") {

	int size = 5;
	float arr[5] = {1,2,3,4,5};

	REQUIRE(binarySearch(arr,size,9) == -1);
}

TEST_CASE("Item on the middle odd elements","[search]") {

	int size = 5;
	float arr[5] = {1,2,3,4,5};

	REQUIRE(binarySearch(arr,size,3) == 2);
}

TEST_CASE("Item on the middle even elements","[search]") {

	int size = 6;
	float arr[6] = {1,2,3,4,5,6};

	REQUIRE(binarySearch(arr,size,4) == 3);
}


TEST_CASE("Big array odd","search") {
	int size = 13;
	float arr[13] = {1,2,3,4,5,6,7,8,9,10,11,12,13};

	REQUIRE(binarySearch(arr, size, 3) == 2);
}

TEST_CASE("Big array even","search") {
	int size = 14;
	float arr[14] = {-6,-3,12,65,78,89,98,556,45468,122220,9888888};

	REQUIRE(binarySearch(arr, size, 3) == -1);
}



