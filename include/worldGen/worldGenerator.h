#ifndef _WORLDGEN_H_
#define _WORLDGEN_H_

#include <memory>
#include <atomic>
#include <thread>
#include <vector>
#include <mutex>

#include "heightmap.h"
#include "../utility/RPGrandom.h"
#include "../gameInstance/SimpleTile.h"
#include "../fileHandling/fileHandler.h"

#define GENERATORVALUE_LANDTHRESHOLD 0.5f

//threaded operator
class worldGenerator
{
private:
	std::atomic<bool> running;
	std::atomic<unsigned int> seed;
	std::atomic<bool> generatingWorld;

public:
	std::thread t;
	std::mutex mtx;

	worldGenerator();
	void run();
	
	void setRunning(bool v);
	bool getRunning() const;

	void setGeneratingWorld(bool v);
	bool getGeneratingWorld() const;

	void setSeed(unsigned int v);
	unsigned int getSeed() const;

	void orderGenerate();
	void privateGenerate(unsigned int seed);

	~worldGenerator();
};

#endif