#ifndef _VEC_2D_H_
#define _VEC_2D_H_

#include <cmath>

class Vec2D
{
public:
	double x, y;

	Vec2D();
	Vec2D(double x, double y);

	double dotProduct(Vec2D* v) const;
	double crossProduct(Vec2D* v) const;
	double magnitude() const;
	
	void clone(Vec2D* target) const;

	void normalize();
	void normalizeTarget(Vec2D* target) const;

	void rotate(Vec2D* a, Vec2D* b);

	~Vec2D();
};

#endif