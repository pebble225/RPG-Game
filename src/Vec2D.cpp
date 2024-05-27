#include "utility/Vec2D.h"

Vec2D::Vec2D() : x(1.0), y(0.0) {}

Vec2D::Vec2D(double n) : x(n), y(n) {}

Vec2D::Vec2D(double x, double y) : x(x), y(y) {}

void Vec2D::setFromAngle(double angle)
{
	x = std::cos(angle * M_PI / 180.0);
	y = std::sin(angle * M_PI / 180.0);
}

double Vec2D::dotProduct(Vec2D* v) const
{
	return x * v->x + y * v->y;
}

double Vec2D::dotDifference(Vec2D* v) const
{
	return x * v->x - y * v->y;
}

double Vec2D::crossProduct(Vec2D* v) const
{
	return x * v->y + y * v->x;
}

double Vec2D::magnitude() const
{
	return std::sqrt(x*x + y*y);
}

void Vec2D::clone(Vec2D* target) const
{
	target->x = x;
	target->y = y;
}

void Vec2D::normalize()
{
	double mag = magnitude();

	x /= mag;
	y /= mag;
}

void Vec2D::normalizeTarget(Vec2D* target) const
{
	double mag = magnitude();

	target->x = x / mag;
	target->y = y / mag;
}

void Vec2D::rotate(Vec2D* change)
{
	double x2 = x;

	x = x * change->x - y * change->y;
	y = x2 * change->y + y * change->x;
}

Vec2D::~Vec2D() {}