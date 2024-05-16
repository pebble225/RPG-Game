#include "content.h"

content::content()
{
	
}

void content::init(int* screenDimension)
{
	r.init(screenDimension);

	fileHandler::checkDirectory("./world");
	fileHandler::checkDirectory("./world/chunkData");

	wg.setSeed(5346782);
	wg.orderGenerate();
}

void content::Update()
{
	
}

void content::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

content::~content()
{
	
}