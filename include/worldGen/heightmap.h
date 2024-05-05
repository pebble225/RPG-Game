#ifndef _HEIGHTMAP_H_
#define _HEIGHTMAP_H_

#include "../utility/RPGmath.h"

#include <iostream>
#include <memory>
#include <cstdio>

/*

Optimal memory management in this class is critical.
Heightmaps are expensive data structures and the worlds are going to big quite large

bless c++ for smart pointers I will become the smart

*/

class heightmap
{
private:
//is an array the best practice for heap or are vectors better?
std::unique_ptr<float[]> data;
int width, height;
long arr_len;

public:
	heightmap(int w, int h);

	int getWidth() const;
	int getHeight() const;

	float at(int x, int y) const;

	void fill(float n);

	void set(float n, int x, int y);

	~heightmap();

};

#endif