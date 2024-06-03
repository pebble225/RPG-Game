#include "gameInstance/chunkInstanceDB.h"

chunkInstanceDB::chunkInstanceDB() {}

bool chunkInstanceDB::checkForChunk(int x, int y)
{
	bool hit = false;

	for (int i = 0; i < chunks.size(); i++)
	{
		chunkData* cd = &chunks.at(i);

		if (x == cd->x && y == cd->y)
			hit = true;
	}

	return hit;
}

int chunkInstanceDB::totalLoadedChunks() const
{
	return chunks.size();
}

void chunkInstanceDB::loadChunkToInstance(int x, int y)
{
	chunks.emplace_back();
	chunkData* cd = &chunks.back();
	cd->init(x, y);
	//cd->loadFromFile();
}

void chunkInstanceDB::freeChunkFromInstance(int x, int y)
{
	int index = indexOfChunkCoordinate(x, y);

	if (index == -1)
		return;

	chunks.erase(chunks.begin() + index);
}

int chunkInstanceDB::indexOfChunkCoordinate(int x, int y)
{
	for (int i = 0; i < chunks.size(); i++)
	{
		chunkData* cd = &chunks.at(i);

		if (x == cd->x && y == cd->y)
			return i;
	}

	return -1;
}

chunkInstanceDB::~chunkInstanceDB() {}