#ifndef _RPGTRANSFORM_H_
#define _RPGTRANSFORM_H_

class RPGtransform
{
public:
	double x, y;

	RPGtransform(): x(0.0), y(0.0) {}
	RPGtransform(double n): x(n), y(n) {}
	RPGtransform(double x, double y): x(x), y(y) {}
};

#endif