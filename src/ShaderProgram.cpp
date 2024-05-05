#include "rendering/ShaderProgram.h"

std::string ShaderProgram::writeCode(std::string src)
{
	std::ifstream shaderFile;

	shaderFile.open(src);

	std::string code;
	std::string line;

	if (shaderFile.is_open())
	{
		while (getline(shaderFile, line))
		{
			code += line;
			code += "\n";
		}

		shaderFile.close();
	}
	else
	{
		std::cout << "Unable to open shader at \"" << src << "\"." << std::endl;

		return "error";
	}

	return code;
}

GLuint ShaderProgram::createShader(std::string src, const GLuint type)
{
	GLuint shader = glCreateShader(type);

	int result;
	char infoLog[512];

	std::string shaderCode = ShaderProgram::writeCode(src);

	const char* shaderCode_cstr = shaderCode.c_str();
	glShaderSource(shader, 1, &shaderCode_cstr, NULL);
	glCompileShader(shader);

	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);

	if (!result)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "Error when compiling \"" << src << "\":" << infoLog << std::endl;
	}

	return shader;
}

ShaderProgram::ShaderProgram() {}

void ShaderProgram::setUniform3f(int index, float x, float y, float z)
{
	glUniform3f(index, x, y, z);
}

void ShaderProgram::setUniformMat4(int index, glm::mat4 m)
{
	glUniformMatrix4fv(index, 1, GL_FALSE, glm::value_ptr(m));
}

int ShaderProgram::getUniform(const char* name)
{
	return glGetUniformLocation(sp, name);
}

void ShaderProgram::use()
{
	glUseProgram(sp);
}

void ShaderProgram::init(std::string vertexDir, std::string fragmentDir)
{
	sp = glCreateProgram();

	GLuint vShader, fShader;

	vShader = createShader(vertexDir, GL_VERTEX_SHADER);
	fShader = createShader(fragmentDir, GL_FRAGMENT_SHADER);

	glAttachShader(sp, vShader);
	glAttachShader(sp, fShader);
	glLinkProgram(sp);

	int status;
	char infoLog[512];

	glGetProgramiv(sp, GL_LINK_STATUS, &status);
	
	if (!status)
	{
		glGetProgramInfoLog(sp, 512, NULL, infoLog);
		std::cout << "Error when linking shader program: " << infoLog << std::endl;
	}

	glDetachShader(sp, vShader);
	glDetachShader(sp, fShader);

	glDeleteShader(vShader);
	glDeleteShader(fShader);
}

ShaderProgram::~ShaderProgram()
{
	
}