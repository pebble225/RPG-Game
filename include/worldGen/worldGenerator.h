#ifndef _WORLDGEN_H_
#define _WORLDGEN_H_

#include <memory>
#include <atomic>
#include <thread>
#include <vector>

#include "heightmap.h"
#include "../utility/RPGrandom.h"
#include "../gameInstance/SimpleTile.h"
#include "../fileHandling/fileHandler.h"

#define GENERATORVALUE_LANDTHRESHOLD 0.5f

//strict operator
class worldGenerator
{
public:
	static void run(unsigned int seed, std::atomic<std::shared_ptr<bool>> status);
	worldGenerator();

	std::unique_ptr<std::thread> thread;

	void generate(unsigned int seed, std::atomic<std::shared_ptr<bool>> status);
	
	~worldGenerator();
};

#endif