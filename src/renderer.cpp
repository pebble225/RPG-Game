#include "rendering/renderer.h"

renderer::renderer()
{
	
}

void renderer::init(int* screenDimension)
{
	this->screenDimension = screenDimension;

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
	sp.use();

	sp.shaderu_transform = sp.getUniform("transform");
	sp.shaderu_camera = sp.getUniform("camera");
	sp.shaderu_orthographic = sp.getUniform("orthographic");
	sp.shaderu_color = sp.getUniform("inColor");

	orthographic = glm::ortho(-(float)screenDimension[0]/2, (float)screenDimension[0]/2, -(float)screenDimension[1]/2, (float)screenDimension[1]/2);
	sp.setUniformMat4(sp.shaderu_orthographic, orthographic);

	glUseProgram(0);
}

void renderer::renderQuad(float x, float y, float r, float g, float b)
{
	glm::mat4 m = glm::mat4(1.0f);
	m = glm::translate(m, glm::vec3(x, y, 0.0f));
	m = glm::rotate(m, 0.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	m = glm::rotate(m, 0.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	m = glm::rotate(m, 0.0f, glm::vec3(0.0f, 0.0f, 1.0f));
	m = glm::scale(m, glm::vec3(1.0f,1.0f, 1.0f));

	sp.use();

	sp.setUniformMat4(sp.shaderu_orthographic, orthographic);
	sp.setUniformMat4(sp.shaderu_camera, camera->matrix);
	sp.setUniformMat4(sp.shaderu_transform, m);
	sp.setUniform3f(sp.shaderu_color, r / 256.0f, g / 256.0f, b / 256.0f);

	standardMesh.bindVAO();
	standardMesh.draw();
	standardMesh.unbindVAO();
	glUseProgram(0);
}

renderer::~renderer()
{
	
}