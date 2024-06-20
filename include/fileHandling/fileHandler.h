#ifndef _FILEHANDLER_H_
#define _FILEHANDLER_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <sys/stat.h>
#include <cstring>
#include <filesystem>
#include <vector>

/*

DO NOT include game object blueprints. This class strictly works with raw data.

*/

#include "../gameInstance/SimpleTile.h"
#include "../utility/RPGtransform.h"
#include "../gameInstance/worldMapConstants.h"

#define FILE_LOAD_OKAY 0

//strict operator
namespace fileHandler
{
	//SimpleTile * 64 * 64 = 16384 Byte file
	int writeChunkFile(int x, int y, SimpleTile* arr);
	int loadChunkFile(int x, int y, std::vector<SimpleTile>* arr, std::vector<RPGtransform>* positions);
	bool folderExists(const std::string dir);
	void checkDirectory(const std::string dir);
};

#endif