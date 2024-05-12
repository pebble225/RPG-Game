#ifndef _WORLDGEN_H_
#define _WORLDGEN_H_

#include <memory>

#include "heightmap.h"
#include "../utility/RPGrandom.h"
#include "../gameInstance/SimpleTile.h"
#include "../fileHandling/fileHandler.h"

#define GENERATORVALUE_LANDTHRESHOLD 0.5f

//strict operator
namespace worldGenerator
{
	void generate(unsigned int seed);
};

#endif