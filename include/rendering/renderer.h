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
#include "../gameInstance/chunkInstanceDB.h"
#include "../gameInstance/chunkData.h"
#include "../gameInstance/SimpleTile.h"

#include "../gameInstance/worldMapConstants.h"

//mixed operator
class renderer
{
public:
	Mesh standardMesh;
	ShaderProgram sp;

	glm::mat4 orthographic;

	int* screenDimension;

	chunkInstanceDB* cidb;
	RPGcamera* camera;

	renderer();

	void init(int* screenDimension);

	void renderAllChunks();

	void renderQuad(float x, float y, float r, float g, float b);

	~renderer();
};

#endif