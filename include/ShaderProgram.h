#ifndef _SHADERPROGRAM_H_
#define _SHADERPROGRAM_H_

#include <GL/glew.h>

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <string>
#include <fstream>

class ShaderProgram
{
private:
	std::string writeCode(std::string src);
	GLuint createShader(std::string src, const GLuint type);

	GLuint sp;

public:
	ShaderProgram();

	void setUniform3f(int index, float x, float y, float z);
	void setUniformMat4(int index, glm::mat4 m);

	int getUniform(const char* name);

	void use();

	void init(std::string vertexDir, std::string fragmentDir);

	~ShaderProgram();
};

#endif