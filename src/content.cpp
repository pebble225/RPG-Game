#include "content.h"

content::content()
{
	
}

void content::init(int* screenDimension)
{
	r.init(screenDimension);
}

float x = 0.0f;

void content::Update()
{
	x += 1.0f;
}

void content::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	r.renderQuad(x, 0.0f);
}

content::~content()
{
	
}