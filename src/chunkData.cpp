#include "gameInstance/chunkData.h"

int chunkData::chunkCounter = 0;

chunkData::chunkData()
	: loaded(false)
{
	chunkCounter++;
}

void chunkData::init(int x, int y)
{
	this->x = x;
	this->y = y;
}

void chunkData::loadFromFile()
{
	if (loaded)
		return;

	if (fileHandler::loadChunkFile(x, y, &tiles, &positions) == FILE_LOAD_OKAY)
	{
		loaded = true;
	}
	else
	{
		printf("In chunkData: Chunk (%d, %d) was not able to be loaded from file.\n", x, y);
	}

}

bool chunkData::isLoaded() const
{
	return loaded;
}

int chunkData::getX() const
{
	return x;
}

int chunkData::getY() const
{
	return y;
}

SimpleTile chunkData::getTileAt(int index) const
{
	return tiles.at(index);
}

RPGtransform chunkData::getPositionAt(int index) const
{
	return positions.at(index);
}

int chunkData::monitorChunkCounter()
{
	if (chunkCounter > 50)
	{
		std::cout << "CRITICAL MEMORY LEAK: Chunk counter is over 50. Shutting down to prevent memory leak.\n";
		return 1;
	}
	else if (chunkCounter < 0)
	{
		std::cout << "CRITICAL MEMORY ERROR: Chunk counter is below 0. Shutting down to prevent memory leak.\n";
		return 1;
	}

	return 0;
}

int chunkData::getChunkCounter()
{
	return chunkCounter;
}

chunkData::~chunkData()
{
	chunkCounter--;
}