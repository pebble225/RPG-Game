#include "utility/XModularTransform.h"

XModularTransform::XModularTransform(double width)
	:x(0.0), y(0.0), width(width) {}

double XModularTransform::getX() const
{
	return x;
}

double XModularTransform::getY() const
{
	return y;
}

double XModularTransform::boundValue(double v) const
{
	return v < 0 ? 0 : (v > width ? width : v);
}

double XModularTransform::boundOffset(double v) const
{
	return v < -width ? -width : (v > width ? width : v);
}

void XModularTransform::setX(double x)
{
	this->x = boundValue(x);
}

void XModularTransform::setY(double y)
{
	this->y = y;
}

void XModularTransform::set(double x, double y)
{
	setX(x);
	setY(y);
}

void XModularTransform::translateX(double n)
{
	x += boundOffset(n);

	x = x < width ? (x < 0 ? x + width : x) : x - width;
}

void XModularTransform::translateY(double n)
{
	y += n;
}

void XModularTransform::translate(double x, double y)
{
	translateX(x);
	translateY(y);
}

XModularTransform::~XModularTransform() {}