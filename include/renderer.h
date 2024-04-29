#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <GL/glew.h>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>


#include "mesh.h"
#include "ShaderProgram.h"

class renderer
{
public:
	Mesh standardMesh;
	ShaderProgram sp;

	glm::mat4 orthographic;

	int* screenDimension;

	renderer();

	void init(int* screenDimension);

	void renderQuad(float x, float y);

	~renderer();
};

#endif