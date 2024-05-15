#include "worldGen/worldGenerator.h"

worldGenerator::worldGenerator() {}

void worldGenerator::generate(unsigned int seed, std::atomic<std::shared_ptr<bool>> status)
{
	thread = std::make_unique<std::thread>(run, seed, status);
	thread->detach();
}

void worldGenerator::run(unsigned int seed, std::atomic<bool>* status)
{
	std::cout << "Generating...\n";

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

	std::cout << "Generating complete.\n";
}

worldGenerator::~worldGenerator() {}