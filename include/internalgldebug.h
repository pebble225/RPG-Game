#ifndef _INTERNALGLDEBUG_H_
#define _INTERNALGLDEBUG_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#ifdef _RELEASE

void enableglDebugFlag() {}

void enableglDebug() {}

#elif defined _DEBUG

void APIENTRY openglcatcherror(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const char* message, const void* userparam)
{
	std::cout << "===================================\nOPENGL NOTICE:\nSource: " << source << "\nType: 0x" << type << "\nId: " << id << "\nSeverity: " << severity << "\n\n> ";
	std::cout << message << "\n\n";

	if (severity == GL_DEBUG_SEVERITY_NOTIFICATION)
	{
		return;
	}
	else if (severity == GL_DEBUG_SEVERITY_HIGH)
	{
		return;
	}
	else if (severity == GL_DEBUG_SEVERITY_MEDIUM)
	{
		return;
	}
	else if (severity == GL_DEBUG_SEVERITY_LOW)
	{
		return;
	}
	else
	{
		std::cout << "Uncaught severity error level. Terminating the program." << std::endl;
		exit(-4);
	}
}

void enableglDebugFlag()
{
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
}

void enableglDebug()
{
	glEnable(GL_DEBUG_OUTPUT);
	glDebugMessageCallback(openglcatcherror, NULL);
}

#endif

#endif