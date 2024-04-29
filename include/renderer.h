#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "mesh.h"
#include "ShaderProgram.h"

class renderer
{
public:
	Mesh standardMesh;
	ShaderProgram sp;

	renderer();

	void init();

	void renderQuad();

	~renderer();
};

#endif