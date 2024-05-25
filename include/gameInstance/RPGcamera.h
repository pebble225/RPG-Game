#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "../utility/HorizonalWrappedTransform.h"

class RPGcamera
{
public:
	HorizontalWrappedTransform transform;

	RPGcamera(double transform);

	~RPGcamera();
};

#endif