#include "content.h"

content::content()
{
	
}

double minDouble(const double a, const double b)
{
	if (a < b)
		return a;
	else
		return b;
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

	/*
	const siv::PerlinNoise::seed_type seed = 123456u;

	const siv::PerlinNoise perlin{ seed };
	
	for (int y = 0; y < 1080; y++)
	{
		for (int x = 0; x < 1920; x++)
		{
			const double noise = perlin.octave2D_01((x * 0.01), (y * 0.01), 4);
			
			int gradient = minDouble((int)floor(noise*256), 255);

			renderer_setIntColor(&ir, gradient, gradient, gradient);

			renderer_drawPixel(&ir, x, y);
		}
	}

	*/

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