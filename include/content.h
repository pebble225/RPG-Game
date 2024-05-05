#ifndef _CONTENT_H_
#define _CONTENT_H_

#include <GL/glew.h>
#include <algorithm>

#include "rendering/renderer.h"
#include "worldGen/heightmap.h"

#include "pebbleimgrenderer.h"

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