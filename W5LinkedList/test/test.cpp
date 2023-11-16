// test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"


uint32_t factorial(uint32_t number) {
    return number <= 1 ? number : factorial(number - 1) * number;
}

TEST_CASE("Factorials are computed", "[factorial]") {
    REQUIRE(factorial(1) == 1);
    REQUIRE(factorial(2) == 2);
    REQUIRE(factorial(3) == 6);
    REQUIRE(factorial(10) == 3'628'800);
}


SCENARIO("vector can be sized and resized") {
    GIVEN("An empty vector") {
        auto v = std::vector<std::string>{};

        // Validate assumption of the GIVEN clause
        THEN("The size and capacity start at 0") {
            REQUIRE(v.size() == 0);
            REQUIRE(v.capacity() == 0);
        }

        // Validate one use case for the GIVEN object
        WHEN("push_back() is called") {
            v.push_back("hullo");

            THEN("The size changes") {
                REQUIRE(v.size() == 1);
                REQUIRE(v.capacity() >= 1);
            }
        }
    }
}