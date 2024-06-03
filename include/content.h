#ifndef _CONTENT_H_
#define _CONTENT_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <algorithm>
#include <memory>
#include <cmath>
#include <vector>

#include "GlobalData.h"

#include "gameInstance/SimpleTile.h"
#include "gameInstance/chunkData.h"
#include "gameInstance/chunkInstanceDB.h"
#include "gameInstance/RPGcamera.h"

#include "fileHandling/fileHandler.h"

#include "rendering/renderer.h"

#include "utility/RPGrandom.h"
#include "utility/MapPoint.h"

#include "worldGen/heightmap.h"
#include "worldGen/worldGenerator.h"

//overhead
class content
{
public:
	GLFWwindow* window;

	worldGenerator wg;
	renderer r;

	double worldDimensions[2];

	GlobalData data;

	content();

	void init(int* screenDimension, GLFWwindow* window);

	void Update();
	void Render();

	~content();
};

#endif