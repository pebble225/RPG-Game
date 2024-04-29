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

	sp.init("res/shaders/defaultVertex.glsl", "res/shaders/defaultFragment.glsl");
}

void renderer::renderQuad()
{
	sp.use();
	standardMesh.bindVAO();
	standardMesh.draw();
	standardMesh.unbindVAO();
	glUseProgram(0);
}

renderer::~renderer()
{
	
}