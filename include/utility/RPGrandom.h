#ifndef _RPGRANDOM_H_
#define _RPGRANDOM_H_

#include <random>
#include <ctime>

class RPGrandom
{
private:
	std::mt19937 mt;
public:
	RPGrandom();
	RPGrandom(unsigned int seed);

	unsigned int nextInt();

	double nextDouble();
};

#endif