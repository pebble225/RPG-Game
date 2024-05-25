#ifndef _MODULARTRANSFORM_H_
#define _MODULARTRANSFORM_H_

//meant to replace `HorizontalWrappedTransform`

class XModularTransform
{
private:
	double x, y;
	double width;
public:
	XModularTransform(double width);

	double getX() const;
	double getY() const;

	double boundValue(double v) const;
	double boundOffset(double v) const;

	void setX(double x);
	void setY(double y);

	void set(double x, double y);

	void translateX(double n);
	void translateY(double n);

	void translate(double x, double y);
	~XModularTransform();
};

#endif