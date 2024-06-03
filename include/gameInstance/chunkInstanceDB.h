#ifndef _CHUNKINSTANCEDB_H_
#define _CHUNKINSTANCEDB_H_

#include <memory>
#include <vector>
#include <utility>

#include "chunkData.h"

/*

there should only be once instance of this class

*/

//database
class chunkInstanceDB
{
private:
	std::vector<chunkData> chunks;
public:
	chunkInstanceDB();

	bool checkForChunk(int x, int y);
	

	int totalLoadedChunks() const;
	
	void loadChunkToInstance(int x, int y);
	void freeChunkFromInstance(int x, int y);

	int indexOfChunkCoordinate(int x, int y);

	~chunkInstanceDB();
};

extern chunkInstanceDB CHUNKINSTANCE_DB;

#endif