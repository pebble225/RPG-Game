#ifndef _CONTENT_H_
#define _CONTENT_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <algorithm>
#include <memory>
#include <cmath>
#include <vector>

#include "gameInstance/SimpleTile.h"
#include "gameInstance/chunkData.h"
#include "gameInstance/chunkInstanceDB.h"
#include "gameInstance/Camera.h"

#include "fileHandling/fileHandler.h"

#include "rendering/renderer.h"

#include "utility/RPGrandom.h"

#include "worldGen/heightmap.h"
#include "worldGen/worldGenerator.h"

//overhead
class content
{
public:
	GLFWwindow* window;

	std::shared_ptr<chunkInstanceDB> cidb;

	worldGenerator wg;

	renderer r;

	content();

	void init(int* screenDimension, GLFWwindow* window);
	void Update();
	void Render();

	~content();
};

#endif