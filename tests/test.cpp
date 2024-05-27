//
// Created by matt on 5/25/24.
//
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <utility/Vec2D.h>
#include <utility/MapPoint.h>

using namespace Catch::Matchers;

TEST_CASE("Simple Vector Magnitude") {
	Vec2D a(3, 4);
	REQUIRE_THAT(5.0, WithinAbs(a.magnitude(), 0.0001));
}

TEST_CASE("MapPoint addition wraps forward")
{
	//Transform with width of 360 units
	MapPoint p(350.0, 0.0, 360.0);
	Vec2D v(20.0, 0.0);

	MapPoint p2 = p + v;

	REQUIRE_THAT(10.0, WithinAbs(p2.x, 0.000001));
}

TEST_CASE("MapPoint addition wraps backward")
{
	//Transform with width of 360 units
	MapPoint p(10.0, 0.0, 360.0);
	Vec2D v(-20.0, 0.0);

	MapPoint p2 = p + v;

	REQUIRE_THAT(350.0, WithinAbs(p2.x, 0.000001));
}

TEST_CASE("MapPoint subtraction wraps forward")
{
	//Transform with width of 360 units
	MapPoint p(10.0, 0.0, 360.0);
	Vec2D v(20.0, 0.0);

	MapPoint p2 = p - v;

	REQUIRE_THAT(350.0, WithinAbs(p2.x, 0.000001));
}

TEST_CASE("MapPoint subtraction wraps backward")
{
	//Transform with width of 360 units
	MapPoint p(350.0, 0.0, 360.0);
	Vec2D v(-20.0, 0.0);

	MapPoint p2 = p - v;

	REQUIRE_THAT(10.0, WithinAbs(p2.x, 0.000001));
}

TEST_CASE("Forward Addition: \"width\" is not a possible x value")
{
	MapPoint p(359.0, 0.0, 360.0);
	Vec2D v(1.0, 0.0);

	MapPoint p2 = p + v;

	REQUIRE_THAT(0.0, WithinAbs(p2.x, 0.000001));
}

TEST_CASE("Backward Addition: \"width\" is not a possible x value")
{
	MapPoint p(0.0, 0.0, 360.0);
	Vec2D v(-1.0, 0.0);

	MapPoint p2 = p + v;

	REQUIRE_THAT(359.0, WithinAbs(p2.x, 0.000001));
}

TEST_CASE("Backward subtraction: \"width\" is not a possible x value")
{
	MapPoint p(0.0, 0.0, 360.0);
	Vec2D v(1.0, 0.0);

	MapPoint p2 = p - v;

	REQUIRE_THAT(359.0, WithinAbs(p2.x, 0.000001));
}

TEST_CASE("Forward subtraction: \"width\" is not a possible x value")
{
	MapPoint p(359.0, 0.0, 360.0);
	Vec2D v(-1.0, 0.0);

	MapPoint p2 = p - v;

	REQUIRE_THAT(0.0, WithinAbs(p2.x, 0.000001));
}

TEST_CASE("Get Offset returns appropritate values near target")
{
	MapPoint p1(150.0, 150.0, 360.0);
	MapPoint p2(160.0, 160.0, 360.0);

	Vec2D v = p1.getOffsetTo(p2);
	REQUIRE_THAT(10.0, WithinAbs(v.x, 0.000001));
	REQUIRE_THAT(10.0, WithinAbs(v.y, 0.000001));

	p2.set(140.0, 155.0);
	v = p1.getOffsetTo(p2);
	REQUIRE_THAT(-10.0, WithinAbs(v.x, 0.000001));
	REQUIRE_THAT(5.0, WithinAbs(v.y, 0.000001));

	p2.set(135.0, 140.0);
	v = p1.getOffsetTo(p2);
	REQUIRE_THAT(-15.0, WithinAbs(v.x, 0.000001));
	REQUIRE_THAT(-10.0, WithinAbs(v.y, 0.000001));

	p2.set(168.0, 144.0);
	v = p1.getOffsetTo(p2);
	REQUIRE_THAT(18.0, WithinAbs(v.x, 0.000001));
	REQUIRE_THAT(-6.0, WithinAbs(v.y, 0.000001));

	p2.set(150.0, 150.0);
	v = p1.getOffsetTo(p2);
	REQUIRE_THAT(0.0, WithinAbs(v.x, 0.000001));
	REQUIRE_THAT(0.0, WithinAbs(v.y, 0.000001));
}

TEST_CASE("Offsets are corrected to + or - width/2")
{
	MapPoint p1(10.0, 0.0, 360.0);
	MapPoint p2(350.0, 0.0, 360.0);
	Vec2D v = p1.getOffsetTo(p2);

	REQUIRE_THAT(-20.0, WithinAbs(v.x, 0.000001));
	v = p2.getOffsetTo(p1);
	REQUIRE_THAT(20.0, WithinAbs(v.x, 0.000001));

	p1.set(5.0, 0.0);
	p2.set(340.0, 0.0);

	v = p1.getOffsetTo(p2);
	REQUIRE_THAT(-25.0, WithinAbs(v.x, 0.000001));
	v = p2.getOffsetTo(p1);
	REQUIRE_THAT(25.0, WithinAbs(v.x, 0.000001));
}