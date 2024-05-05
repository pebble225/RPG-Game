#include "heightmap.h"

heightmap::heightmap(int w, int h) : width(w), height(h)
{
	arr_len = width * height;
	//I don't fully understand how make_unique parameters translate to array parameters such as new arr[w*h]
	data = std::make_unique<float[]>(arr_len);
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

void heightmap::set(float n, int x, int y)
{
	data[y * width + x] = n;
}

heightmap::~heightmap()
{
	
}