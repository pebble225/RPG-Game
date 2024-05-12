#ifndef _CONTENT_H_
#define _CONTENT_H_

#include <GL/glew.h>
#include <algorithm>
#include <cmath>
#include <vector>

#include "gameInstance/SimpleTile.h"

#include "fileHandling/fileHandler.h"

#include "rendering/renderer.h"

#include "utility/RPGrandom.h"

#include "worldGen/heightmap.h"
#include "worldGen/worldGenerator.h"

#include "pebbleimgrenderer.h"

//overhead
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