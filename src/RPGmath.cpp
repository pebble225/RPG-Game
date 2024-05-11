#include "utility/RPGmath.h"

int RPGmath::intBound(int value, int min, int max)
{
	value = value <= min ? min : value;
	value = value >= max ? max : value;

	return value;
}

double RPGmath::minDouble(const double a, const double b)
{
	return a < b ? a : b;
}

double RPGmath::maxDouble(const double a, const double b)
{
	return a > b ? a : b;
}

double RPGmath::doubleBound(double value, double min, double max)
{
	if (value < min)
		return min;
	else if (value > max)
		return max;
	else
		return value;
}

float RPGmath::lerp(float a, float b, float f)
{
	return a + f * (b - a);
}