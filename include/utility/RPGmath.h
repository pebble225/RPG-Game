#ifndef _RPGMATH_H_
#define _RPGMATH_H_

//function database
namespace RPGmath
{
	int intBound(int value, int min, int max);
	double minDouble(const double a, const double b);
	double maxDouble(const double a, const double b);
	double doubleBound(double value, double min, double max);
	//std::lerp() is undefined?? Was the function depricated?
	float lerp(float a, float b, float f);
}

#endif