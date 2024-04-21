#ifndef _MESH_H_
#define _MESH_H_

#include <GL/glew.h>

class Mesh
{
private:
	GLuint vao;
	GLuint vbo, ibo;

	int vertices_s, indices_s;
public:
	Mesh();

	void init(const float vertices[], const int indices[], const int vertexCount, const int indexCount);
	void draw();

	void bindVAO();
	void unbindVAO();

	static void unbindAnyVAO();

	~Mesh();
};

#endif