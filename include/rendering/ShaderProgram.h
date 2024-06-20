#ifndef _SHADERPROGRAM_H_
#define _SHADERPROGRAM_H_

#include <GL/glew.h>

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <string>
#include <fstream>

//functional blueprint
class ShaderProgram
{
private:
	std::string writeCode(std::string src);
	GLuint createShader(std::string src, const GLuint type);

	GLuint sp;

public:
	int shaderu_transform, shaderu_camera, shaderu_orthographic;

	int shaderu_color;

	ShaderProgram();

	void setUniform3f(int index, float x, float y, float z);
	void setUniformMat4(int index, glm::mat4 m);

	int getUniform(const char* name);

	void use();

	void init(std::string vertexDir, std::string fragmentDir);

	~ShaderProgram();
};

#endif