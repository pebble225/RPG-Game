#include "worldGen/worldGenerator.h"

void worldGenerator::generate(unsigned int seed)
{
	RPGrandom ran(seed);

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