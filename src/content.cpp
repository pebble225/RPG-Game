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

	//wg.setSeed(5346782);
	//wg.orderGenerate();

	cidb.loadChunkToInstance(0, 0);

	distribute();
}

void content::distribute()
{
	r.camera = &camera;
	r.cidb = &cidb;

	
}

void content::Update()
{
	if (chunkData::monitorChunkCounter())
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}

	camera.addPosition(1.0f, 1.0f);
}

void content::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	r.renderAllChunks();
}

content::~content()
{
	
}