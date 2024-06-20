#ifndef _CHUNKDATA_H_
#define _CHUNKDATA_H_

#include <vector>
#include <memory>
#include <iostream>

#include "SimpleTile.h"
#include "../utility/RPGtransform.h"

#include "../fileHandling/fileHandler.h"

class chunkData
{
private:
    bool loaded;

    static int chunkCounter;

    int x, y;
public:

    std::vector<SimpleTile> tiles;
    std::vector<RPGtransform> positions;

    chunkData();

    void init(int x, int y);

    void loadFromFile();

    bool isLoaded() const;

    int getX() const;
    int getY() const;

    SimpleTile getTileAt(int index) const;
    RPGtransform getPositionAt(int index) const;

    static int monitorChunkCounter();

    static int getChunkCounter();

    ~chunkData();
};

#endif