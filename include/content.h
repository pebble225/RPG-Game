#ifndef _CONTENT_H_
#define _CONTENT_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <algorithm>
#include <memory>
#include <cmath>
#include <vector>

#include "rendering/renderer.h"

//overhead
class content
{
public:
	GLFWwindow* window;

	renderer r;

	double worldDimensions[2];

	RPGcamera camera;

	content();

	void init(int* screenDimension, GLFWwindow* window);

	void distribute();

	void Update();
	void Render();

	~content();
};

#endif