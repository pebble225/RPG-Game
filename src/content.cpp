#include "content.h"

content::content()
{
	
}

void content::init(int* screenDimension, GLFWwindow* window)
{
	r.init(screenDimension);

	this->window = window;

	cidb = std::make_shared<chunkInstanceDB>();

	fileHandler::checkDirectory("./world");
	fileHandler::checkDirectory("./world/chunkData");

	//wg.setSeed(5346782);
	//wg.orderGenerate();

	camera = std::make_shared<RPGcamera>(screenDimension[0]);
}

void content::Update()
{
	if (chunkData::monitorChunkCounter())
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

void content::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

content::~content()
{
	
}