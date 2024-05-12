#include "content.h"

content::content()
{
	
}

SimpleTile arr[4096];

void content::init(int* screenDimension)
{
	//r.init(screenDimension);

	fileHandler::checkDirectory("./world");
	fileHandler::checkDirectory("./world/chunkData");

	worldGenerator::generate(5664169);
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