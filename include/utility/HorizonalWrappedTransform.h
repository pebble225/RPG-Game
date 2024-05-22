#ifndef _HORIZONTALWRAPPEDTRANSFORM_H_
#define _HORIZINTALWRAPPEDTRANSFORM_H_

#include <cmath>
#include <iostream>

#include "Vec2D.h"

/*

The world exists on a globe and I intend for the player to be able to seemlessely translate between
the very left and right of the map. In order to accomplish this, the x position is going to be
stored as a unit vector. This reduces the complexity of distance operations and other position
functions in order to avoid messy code involving any kind of wrapping.

The large the world size gets, the less accurate the x value becomes.

*/

class HorizontalWrappedTransform
{
private:
	Vec2D x;
	double y;
	double width;
public:
	HorizontalWrappedTransform(double width);

	void setY(double y);
	double getY();

	void setX(double x);
	double getX();

	void translateY(double y);
	void translateX(double x);

	~HorizontalWrappedTransform();
};

#endif