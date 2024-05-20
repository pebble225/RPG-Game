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

    tiles = std::make_unique<std::vector<SimpleTile>>();
}

void chunkData::loadFromFile()
{
    if (loaded)
        return;

    if (fileHandler::loadChunkFile(x, y, tiles.get()) == FILE_LOAD_OKAY)
    {
        loaded = true;
    }

}

bool chunkData::isLoaded() const
{
    return loaded;
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