#include "utility/MapPoint.h"

MapPoint::MapPoint(double width)
	: x(0.0), y(0.0), width(width) {}

MapPoint::MapPoint(double x, double y, double width)
	: x(x), y(y), width(width) {}

void MapPoint::set(double x, double y)
{
	this->x = x;
	this->y = y;
}

double MapPoint::boundValue(double n) const
{
	//values between width - 0.0000001 and width will be discarded!
	return n < width ? (n < 0 ? 0 : n) : width - 0.0000001;
}

double MapPoint::boundOffset(double n) const
{
	//values between width - 0.0000001 and width will be discarded!
	return n < width ? (n < -width ? -width : n) : width - 0.0000001;
}

Vec2D MapPoint::getOffsetTo(const MapPoint &p) const
{
	double x2 = p.x - x;

	double w2 = width / 2;

	return {x2 < -w2 ? x2 + width : (x2 < w2 ? x2 : x2 - width), p.y - y};
}

MapPoint MapPoint::operator+(const Vec2D &v) const
{
	double n = boundOffset(v.x);

	double x2 = x + n;

	x2 = x2 < width ? (x2 < 0 ? x2 + width: x2) : x2 - width;

	return {x2, y + v.y, width};
}

MapPoint MapPoint::operator-(const Vec2D &v) const
{
	double n = boundOffset(v.x);

	double x2 = x - n;

	x2 = x2 < width ? (x2 < 0 ? x2 + width: x2) : x2 - width;

	return {x2, y - v.y, width};
}