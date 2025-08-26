#include "content.h"

content::content()
{
	
}

void content::init(int* screenDimension, GLFWwindow* window)
{
	r.init(screenDimension);

	this->window = window;
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