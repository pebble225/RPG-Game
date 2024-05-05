#include "content.h"

content::content()
{
	
}

void content::init(int* screenDimension)
{
	r.init(screenDimension);

	int dim[] = {800, 600};

	renderer_init(&ir, dim[0], dim[1]);

	heightmap hm(dim[0], dim[1]);
	hm.fill(0.5f);

	for (int y = 0; y < hm.getHeight(); y++)
	{
		for (int x = 0; x < hm.getWidth(); x++)
		{
			int value = (int)std::min(hm.at(x, y)*256.0f, 255.0f);

			renderer_setIntColor(&ir, value, value, value);
			renderer_drawPixel(&ir, x, y);
		}
	}

	renderer_generateImage(&ir, "map.ppm");

	renderer_destroy(&ir);
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