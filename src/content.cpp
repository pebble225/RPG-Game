#include "content.h"

chunkInstanceDB CHUNKINSTANCE_DB;

content::content()
{
	
}

void content::init(int* screenDimension, GLFWwindow* window)
{
	r.init(screenDimension);

	this->window = window;

	fileHandler::checkDirectory("./world");
	fileHandler::checkDirectory("./world/chunkData");

	worldDimensions[0] = 4096;
	worldDimensions[1] = 2048;

	data.initCamera(worldDimensions[0]);

	//wg.setSeed(5346782);
	//wg.orderGenerate();
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