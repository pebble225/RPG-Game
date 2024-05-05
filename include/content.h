#ifndef _CONTENT_H_
#define _CONTENT_H_

#include <GL/glew.h>
#include <algorithm>

#include "renderer.h"
#include "heightmap.h"

#include "pebbleimgrenderer.h"
#include "PerlinNoise.hpp"

class content
{
public:
	renderer r;

	imagerenderer ir;

	content();

	void init(int* screenDimension);
	void Update();
	void Render();

	~content();
};

#endif