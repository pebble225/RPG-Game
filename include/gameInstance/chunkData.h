#ifndef _CHUNKDATA_H_
#define _CHUNKDATA_H_

#include <vector>
#include <memory>

#include "SimpleTile.h"

#include "../fileHandling/fileHandler.h"

class chunkData
{
private:
    bool loaded;

    static int chunkCounter;
public:
    int x, y;

    std::vector<SimpleTile> tiles;

    chunkData();

    void init(int x, int y);

    void loadFromFile();

    bool isLoaded() const;

    static int monitorChunkCounter();

    static int getChunkCounter();

    ~chunkData();
};

#endif