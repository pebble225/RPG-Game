#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "internalgldebug.h"
#include "content.h"

#include <iostream>

GLFWwindow* window;

content c;

int main()
{
	if (!glfwInit())
	{
		std::cout << "GLFW failed to initialize.\n";
		return 1;
	}
	
	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* vmode = glfwGetVideoMode(monitor);
	
	glfwWindowHint(GLFW_RED_BITS, vmode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, vmode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, vmode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, vmode->refreshRate);
	
	int screenDimension[] = {vmode->width, vmode->height};
	
	window = glfwCreateWindow(vmode->width, vmode->height, "RPG Game", monitor, NULL);

	enableglDebugFlag();

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "GLEW initialization failed.\n";
		return 1;
	}

	enableglDebug();
	
	int tps = 60;

	double delta = 0.0;

	double lastTime = glfwGetTime();

	int fps = 144;
	double lastFrame = glfwGetTime();

	double oneDouble = 0.99999999;

	c.init(screenDimension);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		double nowTime = glfwGetTime();
		delta += (nowTime-lastTime)*(double)tps;
		lastTime = nowTime;

		while (delta > oneDouble)
		{
			delta -= 1.0;
			c.Update();
		}

		double nowFrame = glfwGetTime();

		if ((nowFrame - lastFrame) > 1.0f/(double)fps)
		{
			lastFrame = nowFrame;
			c.Render();

			glfwSwapBuffers(window);
		}
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}