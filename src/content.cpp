#include "content.h"

content::content()
{
	
}

void content::init(int* screenDimension)
{
	//r.init(screenDimension);

	int dim[] = {4096, 4096};

	renderer_init(&ir, dim[0], 2048);

	RPGrandom ran(19937);

	heightmap noise(dim[0], dim[1]);
	noise.fillPerlinNoise(&ran, 8, 1.4f);

	heightmap elevation(dim[0], dim[1]);
	std::vector<int> vec;

	heightmap overworld(dim[0], dim[1]);

	for (int y = 800; y < 1300; y += 100)
	{
		for (int x = 1000; x < 1500; x += 100)
		{
			vec.push_back(x);
			vec.push_back(y);
		}
	}

	for (int y = 1000; y < 1500; y += 200)
	{
		for (int x = 3000; x < 3500; x += 200)
		{
			vec.push_back(x);
			vec.push_back(y);
		}
	}

	elevation.fillGravityPoints(&vec, 500.0);
	overworld.fillMapLerp(&noise, &elevation, 0.5f);
	
	for (int y = 0; y < ir.imgH; y++)
	{
		for (int x = 0; x < ir.imgW; x++)
		{
			float value = overworld.at(x, y);

			if (value > 0.5f)
				renderer_setColor(&ir, COLORVALUE_GREEN);
			else if (value > 0.49f)
				renderer_setColor(&ir, COLORVALUE_YELLOW);
			else if (value > 0.45f)
				renderer_setIntColor(&ir, 90, 170, 215);
			else if (value > 0.40f)
				renderer_setIntColor(&ir, 40, 110, 150);
			else
				renderer_setIntColor(&ir, 20, 30, 75);
			

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