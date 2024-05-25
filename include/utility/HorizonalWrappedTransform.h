#ifndef _HORIZINTALWRAPPEDTRANSFORM_H_
#define _HORIZINTALWRAPPEDTRANSFORM_H_

#include <cmath>
#include <iostream>

#include "Vec2D.h"


//Semi-Modular transform used to wrap transforms around the x axis

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