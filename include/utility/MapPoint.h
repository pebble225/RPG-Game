#ifndef _MODULARTRANSFORM_H_
#define _MODULARTRANSFORM_H_

#include "Vec2D.h"


struct MapPoint
{
public:
	double x, y, width;

	MapPoint();
	MapPoint(double width);
	MapPoint(double x, double y, double width);

	void setWidth();

	void set(double x, double y);

	double boundValue(double n) const;
	double boundOffset(double n) const;

	Vec2D getOffsetTo(const MapPoint &p) const;

	MapPoint operator+(const Vec2D &v) const;
	MapPoint operator-(const Vec2D &v) const;
};

#endif