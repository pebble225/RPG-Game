#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <iostream>
#include <memory>

#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../utility/RPGtransform.h"

class RPGcamera
{
public:
	RPGtransform position;
	glm::mat4 matrix;

	RPGcamera();

	void resetMatrix();

	void setPosition(double x, double y);
	void addPosition(double x, double y);

	~RPGcamera();
};

extern std::unique_ptr<RPGcamera> RPGCAMERA_DB;

#endif