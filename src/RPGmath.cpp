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