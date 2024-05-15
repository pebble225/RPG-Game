#include "utility/RPGrandom.h"

RPGrandom::RPGrandom() {}

void RPGrandom::init()
{
	mt.seed(time(0));
}

void RPGrandom::init(unsigned int seed)
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

RPGrandom::~RPGrandom() {}