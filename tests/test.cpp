//
// Created by matt on 5/25/24.
//
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <utility/Vec2D.h>

using namespace Catch::Matchers;

TEST_CASE("Simple Vector Magnitude") {
    Vec2D a(3, 4);
    REQUIRE_THAT(5.0, WithinAbs(a.magnitude(), 0.0001));
}

