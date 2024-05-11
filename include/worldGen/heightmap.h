#ifndef _HEIGHTMAP_H_
#define _HEIGHTMAP_H_

#include "../utility/RPGmath.h"
#include "../utility/RPGrandom.h"

#include <iostream>
#include <memory>
#include <cstdio>
#include <vector>
#include <cmath>

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
bool allocateGuard;

public:
	heightmap();
	heightmap(int w, int h);

	//please only run this once per heightmap
	void allocate(int w, int h);

	bool isAllocated() const;

	int getWidth() const;
	int getHeight() const;

	float at(int x, int y) const;

	void fill(float n);
	void fillNoise(RPGrandom* r);

	void fillPerlinNoise(RPGrandom* r, int octaves, float bias);

	void fillGravityPoints(std::vector<int>* points, double size);

	void fillMapLerp(heightmap* hm1, heightmap* hm2, float f);

	void set(float n, int x, int y);

	~heightmap();

};

#endif