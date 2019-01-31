#include "catch.hpp"
#include <math.h>
#include "ComplexNum.h"
int main() {


  return 0;
}

TEST_CASE("Equal Test", "[equal]") {
    ComplexNum x1(2,33), x2(2, 33);
    REQUIRE(x1 == x1);
    REQUIRE(x1 == x2);
    REQUIRE(x1 == ComplexNum(2, 33));
}

TEST_CASE("Signs") {
    ComplexNum x1(58,10), x2(11,52);
    REQUIRE(-x1 == ComplexNum(58,10));
    REQUIRE(x2 == ComplexNum(11,52));
}

TEST_CASE("SumTest") {
    ComplexNum x1(20, 32), x2(12, 8), x3(-12, -8);
    REQUIRE((x1 + x2) == ComplexNum(32, 40));
    REQUIRE((x1 + x3) == ComplexNum(8, 24));
    REQUIRE(x1 == ComplexNum(30, 32));
    x1 += x1;
    REQUIRE(x1 == ComplexNum(60, 64));
}

TEST_CASE("MinusTest") {
    ComplexNum x1(20, 32), x2(12, 8), x3(-12, -8);
    REQUIRE((x1 - x2) == ComplexNum(8, 24));
    REQUIRE((x2 - x1) == ComplexNum(-8, -24));
    REQUIRE((x2 - x3) == ComplexNum(24, 16));
    REQUIRE((x1 - 10) == ComplexNum(10, 32));
    REQUIRE((10 - x1) == ComplexNum(-10, -32));
    REQUIRE(x1 == ComplexNum(10, 32));
    REQUIRE(-x1 == ComplexNum(-10, -32));
}
