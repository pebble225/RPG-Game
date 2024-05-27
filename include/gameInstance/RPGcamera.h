#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "../utility/MapPoint.h"

class RPGcamera
{
public:
	MapPoint position;

	RPGcamera(double width);

	~RPGcamera();
};

#endif