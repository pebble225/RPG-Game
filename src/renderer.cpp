#include "renderer.h"

renderer::renderer()
{
	
}

void renderer::init()
{
	const float vertices[] = {
		-0.5f, 0.5f, 0.0f,
		0.5f, 0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f
	};
	const int vertexCount = 4;

	const int indices[] = {
		0, 1, 2,
		1, 3, 2
	};
	const int indexCount = 2;

	standardMesh.init(vertices, indices, vertexCount, indexCount);
}

void renderer::renderQuad()
{
	standardMesh.bindVAO();
	standardMesh.draw();
	standardMesh.unbindVAO();
}

renderer::~renderer()
{
	
}