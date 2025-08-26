#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <GL/glew.h>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <memory>


#include "mesh.h"
#include "ShaderProgram.h"
#include "../gameInstance/RPGcamera.h"

//mixed operator
class renderer
{
public:
	Mesh standardMesh;
	ShaderProgram sp;

	glm::mat4 orthographic;

	int* screenDimension;
	
	RPGcamera* camera;

	renderer();

	void init(int* screenDimension);

	void renderAllChunks();

	void renderQuad(float x, float y, float r, float g, float b);

	~renderer();
};

#endif