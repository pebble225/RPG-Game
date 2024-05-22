#include "utility/HorizonalWrappedTransform.h"

HorizontalWrappedTransform::HorizontalWrappedTransform(double width)
	: y(0.0), width(width) {}

void HorizontalWrappedTransform::setY(double y)
{
	this->y = y;
}

double HorizontalWrappedTransform::getY()
{
	return y;
}

void HorizontalWrappedTransform::setX(double x)
{
	//consider supporting wrapping in the future
	x = x > width ? width : x;
	
	double radian = x / width * (M_PI * 2);

	this->x.x = cos(radian);
	this->x.y = sin(radian);
}

double HorizontalWrappedTransform::getX()
{
	double angle = atan2(x.y, x.x);

	angle = angle < 0 ? angle + M_PI*2 : angle;

	return (angle / (2*M_PI)) * width;
}

void HorizontalWrappedTransform::translateY(double y)
{
	this->y += y;
}

void HorizontalWrappedTransform::translateX(double x)
{
	//also consider supporting wrapping in the future for that big zoom
	x = x > width ? width : x;
	x = x < -width ? -width : x;

	double radian = x / width * (M_PI * 2);

	Vec2D vec(std::cos(radian), std::sin(radian));

	this->x.rotate(&vec);
	this->x.normalize();
}

HorizontalWrappedTransform::~HorizontalWrappedTransform() {}