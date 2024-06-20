#include "gameInstance/RPGcamera.h"

RPGcamera::RPGcamera()
{
	resetMatrix();
}

void RPGcamera::resetMatrix()
{
	matrix = glm::mat4(1.0f);
	matrix = glm::translate(matrix, glm::vec3((float)-position.x, (float)-position.y, 0.0f));
	matrix = glm::rotate(matrix, 0.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	matrix = glm::rotate(matrix, 0.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	matrix = glm::rotate(matrix, 0.0f, glm::vec3(0.0f, 0.0f, 1.0f));
	matrix = glm::scale(matrix, glm::vec3(1.0f, 1.0f, 1.0f));
}

void RPGcamera::setPosition(double x, double y)
{
	position = RPGtransform(x, y);

	resetMatrix();
}

void RPGcamera::addPosition(double x, double y)
{
	position.x += x;
	position.y += y;

	resetMatrix();
}

RPGcamera::~RPGcamera() {}