#ifndef _VEC_2D_H_
#define _VEC_2D_H_

#include <cmath>

class Vec2D
{
public:
	double x, y;

	Vec2D();
	Vec2D(double x, double y);

	void setFromAngle(double angle);

	double dotProduct(Vec2D* v) const;
	double dotDifference(Vec2D* v) const;
	double crossProduct(Vec2D* v) const;
	double magnitude() const;
	
	void clone(Vec2D* target) const;

	void normalize();
	void normalizeTarget(Vec2D* target) const;

	void rotate(Vec2D* change);

	~Vec2D();
};

#endif