#include "rendering/mesh.h"

Mesh::Mesh()
{

}

void Mesh::init(const float vertices[], const int indices[], const int vertexCount, const int indexCount)
{
	vertices_s = vertexCount * 3 * sizeof(float);
	indices_s = indexCount * 3 * sizeof(int);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices_s, vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_s, indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
}

void Mesh::bindVAO()
{
	glBindVertexArray(vao);
}

void Mesh::unbindVAO()
{
	glBindVertexArray(0);
}

void Mesh::unbindAnyVAO()
{
	glBindVertexArray(0);
}

void Mesh::draw()
{
	glDrawElements(GL_TRIANGLES, indices_s, GL_UNSIGNED_INT, NULL);
}

Mesh::~Mesh()
{
	
}