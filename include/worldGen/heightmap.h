#ifndef _HEIGHTMAP_H_
#define _HEIGHTMAP_H_

#include "../utility/RPGmath.h"
#include "../utility/RPGrandom.h"

#include <iostream>
#include <memory>
#include <cstdio>
#include <vector>
#include <list>
#include <cmath>

/*

Optimal memory management in this class is critical.
Heightmaps are expensive data structures and the worlds are going to big quite large

bless c++ for smart pointers I will become the smart

*/

//functional blueprint
class heightmap
{
private:
std::unique_ptr<float[]> data;
int width, height;
long arr_len;
bool allocateGuard;
RPGrandom rng;

public:
	heightmap();
	heightmap(int w, int h);

	//please only run this once per heightmap
	void allocate(int w, int h);

	bool isAllocated() const;

	void initRNG(unsigned int seed);
	void addPerlinJob(float octaves, float bias);
	void addPerlinInterpolateTask(int x, int y, float octaves, float bias);
	void iteratePerlinTask();

	int getWidth() const;
	int getHeight() const;

	float at(int x, int y) const;

	void fill(float n);
	void fillNoise(RPGrandom* r);

	//replace this with OpenSimplex in the future to reduce artifacts
	void fillPerlinNoise(RPGrandom* r, int octaves, float bias);

	//this function is slow and inefficient. Future optimization might be useful
	void fillGravityPoints(std::vector<int>* points, double size);

	void fillMapLerp(heightmap* hm1, heightmap* hm2, float f);

	void set(float n, int x, int y);

	~heightmap();

};

#endif