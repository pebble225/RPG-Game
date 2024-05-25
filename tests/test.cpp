//
// Created by matt on 5/25/24.
//
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <utility/Vec2D.h>
#include <utility/XModularTransform.h>

using namespace Catch::Matchers;

TEST_CASE("Simple Vector Magnitude") {
    Vec2D a(3, 4);
    REQUIRE_THAT(5.0, WithinAbs(a.magnitude(), 0.0001));
}

TEST_CASE("XModTransform Tests")
{
    //Transform with width of 360 units
    XModularTransform t(360.0);

    SECTION("Addition overflow")
    {
        t.setX(355.0);
        t.translateX(10.0);
        REQUIRE_THAT(5.0, WithinAbs(t.getX(), 0.000001));
        t.setX(0.2);
        t.translateX(1000.0);//overflow! set to width and add
        REQUIRE_THAT(0.2, WithinAbs(t.getX(), 0.000001));
        t.setX(248.0);
        t.translateX(350.0);
        REQUIRE_THAT(238.0, WithinAbs(t.getX(), 0.000001));
        t.setX(359.998);
        t.translateX(0.002);
        REQUIRE_THAT(0.0, WithinAbs(t.getX(), 0.000001));
        t.setX(350.0);
        t.translateX(10.0);
        REQUIRE_THAT(360.0, !WithinAbs(t.getX(), 0.000001));
        t.setX(350.0);
        t.translateX(10.0);
        REQUIRE_THAT(0.0, WithinAbs(t.getX(), 0.000001));
    }
}