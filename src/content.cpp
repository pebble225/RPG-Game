#include "content.h"

content::content()
{
	
}

SimpleTile arr[4096];

void content::init(int* screenDimension)
{
	r.init(screenDimension);

	fileHandler::checkDirectory("./world");
	fileHandler::checkDirectory("./world/chunkData");

	std::shared_ptr<bool> intialStatus = std::make_shared<bool>(false);

	worldGenStatus.store(intialStatus);

	wg.generate(5664168, worldGenStatus.get());
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