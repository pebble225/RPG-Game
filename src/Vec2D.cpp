#include "utility/Vec2D.h"

Vec2D::Vec2D() : x(1.0), y(0.0) {}

Vec2D::Vec2D(double x, double y) : x(x), y(y) {}

double Vec2D::dotProduct(Vec2D* v) const
{
	return x * v->x + y * v->y;
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

void Vec2D::rotate(Vec2D* a, Vec2D* b)
{
	double cosTheta = a->dotProduct(b);
	double theta = std::acos(cosTheta);

	double direction = a->crossProduct(b);
	if (direction < 0)
		theta = -theta;
	
	x = a->x * std::cos(theta) - a->y * std::sin(theta);
	y = a->x * std::sin(theta) + a->y * std::cos(theta);

	//these values appear to need to be converted but pebble is sleepy

	normalize();
}

Vec2D::~Vec2D() {}