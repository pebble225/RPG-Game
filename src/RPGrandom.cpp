#include "utility/RPGrandom.h"

RPGrandom::RPGrandom()
{
	mt.seed(time(0));
}

RPGrandom::RPGrandom(unsigned int seed)
{
	mt.seed(seed);
}

unsigned int RPGrandom::nextInt()
{
	return mt();
}

double RPGrandom::nextDouble()
{
	return (double)mt() / (double)mt.max();
}