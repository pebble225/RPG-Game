#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "mesh.h"

class renderer
{
public:
	Mesh standardMesh;

	renderer();

	void init();

	void renderQuad();

	~renderer();
};

#endif