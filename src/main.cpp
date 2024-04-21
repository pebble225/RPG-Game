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

	window = glfwCreateWindow(1600, 900, "RPG Game", NULL, NULL);

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

	int fps = 30;
	double lastFrame = glfwGetTime();

	double oneDouble = 0.99999999;

	c.init();

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

	glfwTerminate();

	return 0;
}