#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <math.h>
#include "ComplexNum.h"
#include <sstream>

TEST_CASE("EqualTest") {
    ComplexNum x1(2,33), x2(2, 33);
    REQUIRE(x1 == x1);
    REQUIRE(x1 == x2);
    REQUIRE(x1 == ComplexNum(2, 33));
    x1 = ComplexNum(3, 10);
    REQUIRE(x1 == ComplexNum(3, 10));
}

TEST_CASE("SumTest") {
    ComplexNum x1(20, 32), x2(12, 8), x3(-12, -8);
    REQUIRE((x1 + x2) == ComplexNum(32, 40));
    REQUIRE((x1 + x3) == ComplexNum(8, 24));
    x1 += x1;
    REQUIRE(x1 == ComplexNum(40, 64));
}

TEST_CASE("MinusTest") {
    ComplexNum x1(20, 32), x2(12, 8), x3(-12, -8);
    REQUIRE((x1 - x2) == ComplexNum(8, 24));
    REQUIRE((x2 - x1) == ComplexNum(-8, -24));
    REQUIRE((x2 - x3) == ComplexNum(24, 16));
}

TEST_CASE("MultTest") {
    ComplexNum x1(7, 3), x2(5, -8), x3(-10, -4), x4(8, 0);
    REQUIRE(x1 * x2 == ComplexNum (35, -24));
    REQUIRE(x3 * x4 == ComplexNum (-80, 0));
}

TEST_CASE("DivTest") {
    ComplexNum x1(2, 5), x2(3, -2);
    REQUIRE((x1 / x2) == ComplexNum(-4.0 / 13.0, 19.0 / 13));
}

TEST_CASE("GET_SET_ARG_ABS") {
    ComplexNum x1(2, 5), x2(-3, -8), x3(0, 8), x4(0, -8);
    x1.set_im(9);
    REQUIRE(x1 == ComplexNum(2, 9));
    x1.set_re(-8);
    REQUIRE(x1 == ComplexNum(-8, 9));
    REQUIRE(x1.get_im() == 9);
    REQUIRE(x1.get_re() == -8);
    REQUIRE(std::abs(x1.arg() - 2.29) < 0.008);
    REQUIRE(std::abs(x1.abs() - 12.04159) < 0.002);
    x1.set_im(-5);
    REQUIRE(std::abs(x1.arg()) > 2.58);
    REQUIRE(x3.arg() == (M_PI / 2));
    REQUIRE(x4.arg() == -(M_PI / 2));
    REQUIRE(x2 == polarToCart(cartToPolar(x2)));
}

//polar numbers tests

TEST_CASE("STRINGTEST"){
    PolarComplex x2(12, 12);
    ComplexNum x1(10, 10);
    std::stringstream ss;
    ss << x2;
    REQUIRE(ss.str() == "(ro=12,phi=12)");
    ss.str("");
    ss << x1;
    REQUIRE(ss.str() == "( 10, 10)");
}

TEST_CASE("STRINGTEST_1"){
    PolarComplex x2;
    std::stringstream ss;
    std::stringstream ss1;
    ss << "1 2";
    ComplexNum x1;
    ss >> x1;
    REQUIRE(x1 == ComplexNum(1,2));
    ss1 << ("2 3");
    ss1 >> x2;
    REQUIRE(x2 == PolarComplex(2, 3));
}

TEST_CASE("EqualsTestPolar") {
    PolarComplex x1(20, 32), x2(20, 32);
    REQUIRE(x1 == x1);
    REQUIRE(x1 == x2);
    REQUIRE(x1 == PolarComplex(20, 32));
}

TEST_CASE("SumTestPolar") {
    PolarComplex x1(20, 32), x2(12, 8), x3(-12, -8), x4(10, 10), x5(12, 8);
    REQUIRE((x1 + x2) == cartToPolar(polarToCart(x1) + polarToCart(x2)));
    REQUIRE((x1 + x3) == cartToPolar(polarToCart(x1) + polarToCart(x3)));
    x5 += x4;
    REQUIRE((x4 + x2) == x5);
}

TEST_CASE("MinusTestPolar") {
    PolarComplex x1(20, 32), x2(12, 8), x3(-12, 0), x4(-12, M_PI), x5(10, 0);
    REQUIRE((x1 - x2) == cartToPolar(polarToCart(x1) - polarToCart(x2)));
    REQUIRE((x1 - x3) == cartToPolar(polarToCart(x1) - polarToCart(x3)));
    x1 -= x5;
    REQUIRE(x1 == cartToPolar(polarToCart(PolarComplex(20, 32)) - polarToCart(PolarComplex(10, 0))));
    REQUIRE((x1 - PolarComplex(10)) == cartToPolar(polarToCart(x1) - polarToCart(x5)));
    x1 = PolarComplex(10, 10);
    REQUIRE(x1 == PolarComplex(10, 10));
}


TEST_CASE("MultTestPolar") {
    PolarComplex x1(7, 3), x2(3, -8), x3(-10, -4), x4(8, 0);
    REQUIRE((x1 * x2) == PolarComplex(21, -5));
    REQUIRE((x3 * PolarComplex(8)) == (x3 * x4));
}

TEST_CASE("DivTestPolar") {
    PolarComplex x1(2, 5), x2(3, -2);
    REQUIRE((x1 / x2) == PolarComplex(2.0 / 3, 7));
}

TEST_CASE("GET_SET_POLAR") {
    PolarComplex x1(9, 9);
    x1.set_phi(8);
    REQUIRE(x1 == PolarComplex(9, 8));
    x1.set_ro(8);
    REQUIRE(x1 == PolarComplex(8, 8));
}

TEST_CASE("OTHERTESTS") {
    ComplexNum x1, x2(10), x3(ComplexNum(10, 19));
    REQUIRE(x1 == ComplexNum());
    REQUIRE(x2 == ComplexNum(10));
    REQUIRE(x3 == ComplexNum(10, 19));
    ComplexNum x4 = x3;
    REQUIRE(x4 == ComplexNum(10, 19));
    x4 -= x3;
    REQUIRE(x4 == ComplexNum(0, 0));
    PolarComplex y1, y2(10);
    REQUIRE(y2 == PolarComplex(y2));
    REQUIRE(y1 == PolarComplex());
    REQUIRE(y2.abs() == 10);
    REQUIRE(y2.arg() == 0);
}