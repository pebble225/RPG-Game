#include "worldGen/heightmap.h"

heightmap::heightmap() : allocateGuard(false)
{
	
}

heightmap::heightmap(int w, int h) : allocateGuard(false)
{
	allocate(w, h);
}

void heightmap::allocate(int w, int h)
{
	if (allocateGuard)
		return;
	else
		allocateGuard = true;

	width = w;
	height = h;
	arr_len = width * height;
	data = std::make_unique<float[]>(arr_len);
}

bool heightmap::isAllocated() const
{
	return allocateGuard;
}

int heightmap::getWidth() const
{
	return width;
}

int heightmap::getHeight() const
{
	return height;
}

float heightmap::at(int x, int y) const
{
	return data[y * width + x];
}

void heightmap::fill(float n)
{
	for (int i = 0; i < arr_len; i++)
	{
		data[i] = n;
	}
}

void heightmap::fillNoise(RPGrandom* r)
{
	for (int i = 0; i < arr_len; i++)
	{
		data[i] = (float)r->nextDouble();
	}
}

void heightmap::fillPerlinNoise(RPGrandom* r, int octaves, float bias)
{
	heightmap noisemap(width, height);
	noisemap.fillNoise(r);

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int distance = 1 << octaves - 1;

			float noise = 0.0f;
			float scaleAcc = 0.0f;
			float scale = 1.0f;

			for (int o = 0; o < octaves; o++)
			{
				int pitch = distance >> o;
				
				int sampleX1 = (x / pitch) * pitch;
				int sampleY1 = (y / pitch) * pitch;

				int sampleX2 = (sampleX1 + pitch) % noisemap.getWidth();
				int sampleY2 = (sampleY1 + pitch) % noisemap.getHeight();

				float blendX = (float)(x - sampleX1) / (float)pitch;
				float blendY = (float)(y - sampleY1) / (float)pitch;

				float sampleT = (1.0f - blendX) * noisemap.at(sampleX1, sampleY1) + blendX * noisemap.at(sampleX2, sampleY1);
				float sampleB = (1.0f - blendX) * noisemap.at(sampleX1, sampleY2) + blendX * noisemap.at(sampleX2, sampleY2);

				scaleAcc += scale;
				noise += (blendY * (sampleB - sampleT) + sampleT) * scale;
				scale = scale / bias;
			}

			set(noise / scaleAcc, x, y);
		}
	}
}

void heightmap::fillGravityPoints(std::vector<int>* points, double size)
{
	int len = points->size();

	for (int y = 0; y < getHeight(); y++)
	{
		for (int x = 0; x < getWidth(); x++)
		{
			double minDistance = 100000.0;

			for (int i = 0; i < len; i += 2)
			{
				int vx = points->at(i);
				int vy = points->at(i + 1);

				double d = sqrt(((double)x-(double)vx)*((double)x-(double)vx) + ((double)y-(double)vy)*((double)y-(double)vy));
				d = d == 0 ? 0.00001 : d;
				d = RPGmath::minDouble(d, 100000.0);

				if (d < minDistance)
					minDistance = d;
			}

			set(1.0f - (float)RPGmath::minDouble(minDistance / size, 1.0f), x, y);
		}
	}
}

void heightmap::fillMapLerp(heightmap* hm1, heightmap* hm2, float t)
{
	for (int y = 0; y < getHeight(); y++)
	{
		for (int x = 0; x < getWidth(); x++)
		{
			float a = hm1->at(x, y);
			float b = hm2->at(x, y);

			set(a + t * (b - a), x, y);
		}
	}
}

void heightmap::set(float n, int x, int y)
{
	data[y * width + x] = n;
}

heightmap::~heightmap()
{
	
}