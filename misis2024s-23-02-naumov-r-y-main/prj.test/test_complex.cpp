#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "complex/complex.hpp"
#include "doctest.h"

TEST_CASE("Constructor") {
    Complex c2(1);
    CHECK(c2.re == 1);
    CHECK(c2.im == 0);

    Complex c3(1, 2);
    CHECK(c3.re == 1);
    CHECK(c3.im == 2);

    Complex c4(c3);
    CHECK(c4.re == 1);
    CHECK(c4.im == 2);

    Complex c5 = c3;
    CHECK(c5.re == 1);
    CHECK(c5.im == 2);

    Complex c6{};
    CHECK(c6.re == 0);
    CHECK(c6.im == 0);
}

TEST_CASE("Constructor with move semantics") {
    Complex c1(1, 2);
    Complex c2(std::move(c1));
    CHECK(c2.re == 1);
    CHECK(c2.im == 2);

    Complex c3 = std::move(c2);
    CHECK(c3.re == 1);
    CHECK(c3.im == 2);

    Complex&& c4 = Complex(1, 2);
    CHECK(c4.re == 1);
    CHECK(c4.im == 2);
}

TEST_CASE("Testing Complex class") {
    Complex c1(3, 4);
    Complex c2(1, 2);

    SUBCASE("Test operator-") {
        Complex c = -c1;
        CHECK(c.re == -3);
        CHECK(c.im == -4);
    }

    SUBCASE("Test operator+") {
        Complex c = c1 + c2;
        CHECK(c.re == 4);
        CHECK(c.im == 6);
    }

    SUBCASE("Test operator-") {
        Complex c = c1 - c2;
        CHECK(c.re == 2);
        CHECK(c.im == 2);
    }

    SUBCASE("Test operator*") {
        Complex c = c1 * c2;
        CHECK(c.re == -5);
        CHECK(c.im == 10);
    }

    SUBCASE("Test operator/") {
        Complex c = c1 / c2;
        CHECK(c.re == 2.2);
        CHECK(c.im == -0.4);
    }

    SUBCASE("Test operator+=") {
        Complex c = c1;
        c += c2;
        CHECK(c.re == 4);
        CHECK(c.im == 6);
    }

    SUBCASE("Test operator-=") {
        Complex c = c1;
        c -= c2;
        CHECK(c.re == 2);
        CHECK(c.im == 2);
    }

    SUBCASE("Test operator*=") {
        Complex c = c1;
        c *= c2;
        CHECK(c.re == -5);
        CHECK(c.im == 10);
    }

    SUBCASE("Test operator/=") {
        Complex c = c1;
        c /= c2;
        CHECK(c.re == 2.2);
        CHECK(c.im == -0.4);
    }

    SUBCASE("Test operator==") {
        CHECK(c1 == c1);
        CHECK(c1 != c2);
    }

    SUBCASE("Test operator<<") {
        std::stringstream ss;
        ss << c1;
        CHECK(ss.str() == "{3,4}");
    }

    SUBCASE("Test operator>>") {
        std::stringstream ss;
        ss << "{3,4}";
        Complex c{ 0 };
        ss >> c;
        CHECK(c.re == 3);
        CHECK(c.im == 4);
    }
}

TEST_CASE("Test Complex class with double") {
    Complex c1(3, 4);
    double d = 2;

    SUBCASE("Test operator+") {
        Complex c = c1 + d;
        CHECK(c.re == 5);
        CHECK(c.im == 4);
    }

    SUBCASE("Test operator-") {
        Complex c = c1 - d;
        CHECK(c.re == 1);
        CHECK(c.im == 4);
    }

    SUBCASE("Test operator*") {
        Complex c = c1 * d;
        CHECK(c.re == 6);
        CHECK(c.im == 8);
    }

    SUBCASE("Test operator/") {
        Complex c = c1 / d;
        CHECK(c.re == 1.5);
        CHECK(c.im == 2);
    }

    SUBCASE("Test operator+=") {
        Complex c = c1;
        c += d;
        CHECK(c.re == 5);
        CHECK(c.im == 4);
    }

    SUBCASE("Test operator-=") {
        Complex c = c1;
        c -= d;
        CHECK(c.re == 1);
        CHECK(c.im == 4);
    }

    SUBCASE("Test operator*=") {
        Complex c = c1;
        c *= d;
        CHECK(c.re == 6);
        CHECK(c.im == 8);
    }

    SUBCASE("Test operator/=") {
        Complex c = c1;
        c /= d;
        CHECK(c.re == 1.5);
        CHECK(c.im == 2);
    }

    SUBCASE("Test operator==") {
        CHECK(c1 == c1);
        CHECK(c1 != Complex(d));
    }

    SUBCASE("Test operator<<") {
        std::stringstream ss;
        ss << c1;
        CHECK(ss.str() == "{3,4}");
    }

    SUBCASE("Test operator>>") {
        std::stringstream ss;
        ss << "{3,4}";
        Complex c{ 0 };
        ss >> c;
        CHECK(c.re == 3);
        CHECK(c.im == 4);
    }
}