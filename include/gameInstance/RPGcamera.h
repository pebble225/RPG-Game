#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <iostream>
#include <memory>

#include "../utility/MapPoint.h"
#include "../utility/RPGtransform.h"

class RPGcamera
{
public:
	RPGtransform position;

	RPGcamera();

	~RPGcamera();
};

extern std::unique_ptr<RPGcamera> RPGCAMERA_DB;

#endif