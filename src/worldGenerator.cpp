#include "worldGen/worldGenerator.h"

worldGenerator::worldGenerator()
{
	t = std::thread(&worldGenerator::run, this);
	setRunning(true);
	setGeneratingWorld(false);
	t.detach();
}

void worldGenerator::run()
{
	while(getRunning())
	{
		if (getGeneratingWorld())
		{
			privateGenerate(getSeed());
			setGeneratingWorld(false);
		}
	}
}

void worldGenerator::setRunning(bool v)
{
	std::lock_guard<std::mutex> lock(mtx);
	running.store(v);
}

bool worldGenerator::getRunning() const
{
	return running.load();
}

void worldGenerator::setGeneratingWorld(bool v)
{
	std::lock_guard<std::mutex> lock(mtx);
	generatingWorld.store(v);
}

bool worldGenerator::getGeneratingWorld() const
{
	return generatingWorld.load();
}

void worldGenerator::setSeed(unsigned int v)
{
	std::lock_guard<std::mutex> lock(mtx);

	seed.store(v);
}

unsigned int worldGenerator::getSeed() const
{
	return seed;
}

void worldGenerator::orderGenerate()
{
	setGeneratingWorld(true);
}

void worldGenerator::privateGenerate(unsigned int seed)
{
	RPGrandom ran;
	ran.init(seed);

	int worldWidth = 4096;
	int worldHeight = 2048;

	int chunkSide = 64;

	int chunkCountWidth = worldWidth / chunkSide;
	int chunkCountHeight = worldHeight / chunkSide;

	heightmap pNoise(worldWidth, worldHeight);
	pNoise.fillPerlinNoise(&ran, 8, 1.4f);

	std::unique_ptr<SimpleTile[]> arr = std::make_unique<SimpleTile[]>(64*64);

	for (int y = 0; y < chunkCountHeight; y++)
	{
		for (int x = 0; x < chunkCountWidth; x++)
		{
			for (int j = 0; j < chunkSide; j++)
			{
				for (int i = 0; i < chunkSide; i++)
				{
					int worldX = chunkSide * x + i;
					int worldY = chunkSide * y + j;

					float value = pNoise.at(worldX, worldY);

					//oh god no what's an if-else chain doing here???

					if (value > GENERATORVALUE_LANDTHRESHOLD)
					{
						arr[j * chunkSide + i] = SIMPLETILEID_GRASS_VARIANT_00;
					}
					else
					{
						arr[j * chunkSide + i] = SIMPLETILEID_WATER_OCEAN_DEEP;
					}
				}
			}

			//hopefully using arr.get() doesn't cause leaks or dangling pointers
			fileHandler::writeChunkFile(x, y, arr.get());
		}
	}
}

worldGenerator::~worldGenerator()
{
	setRunning(false);
}