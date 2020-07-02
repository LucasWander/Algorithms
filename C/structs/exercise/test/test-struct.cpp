#include <string>
#include "catch.hpp"
#include "../struct.h"

TEST_CASE("Test input", "[struct]")
{

    student *s1;

    s1 = readNewStudent();

    std::string name(s1->name);
    std::string curso(s1->curso);

    REQUIRE(name == "Lucas\n");
    REQUIRE(curso == "Info\n");
    REQUIRE(s1->age == 21);

    SECTION("Read grades")
    {

        s1->grades = readGrades();

        REQUIRE(s1->grades[0] == 1.0);
        REQUIRE(s1->grades[1] == 2.0);
        REQUIRE(s1->grades[2] == 3.0);
        REQUIRE(average(s1)==2);
    }
}
