#include "fileHandling/fileHandler.h"

int fileHandler::writeChunkFile(int x, int y, SimpleTile* arr)
{
	std::ostringstream oss;
	oss << "./world/chunkData/x" << x << "y" << y << ".chunkdata";
	std::string directory = oss.str();

	std::ofstream file(directory, std::ios::out|std::ios::binary);

	const int len = 64*64;

	if (file.is_open())
	{
		for (int i = 0; i < len; i++)
		{
			file.write((char*)&arr[i], sizeof(SimpleTile));
		}
	}
	else
		return 1;

	file.close();

	return 0;
}

//maybe refractor x and y to chunkIndexX and chunkIndexY
int fileHandler::loadChunkFile(int x, int y, std::vector<SimpleTile>* arr, std::vector<RPGtransform>* positions)
{
	std::ostringstream oss;

	oss << "./world/chunkData/x" << x << "y" << y << ".chunkdata";

	std::string directory = oss.str();

	std::ifstream file(directory, std::ios::in|std::ios::binary);

	if (file.is_open())
	{
		SimpleTile tileData;

		while (file.read(reinterpret_cast<char*>(&tileData), sizeof(tileData)))
		{
			arr->push_back(tileData);
		}

		file.close();
	}
	else
		return 1;

	RPGtransform chunkCoordinate(x * WORLDMAP_TILE_WIDTH_PER_CHUNK, y * WORLDMAP_TILE_WIDTH_PER_CHUNK);

	for (int j = 0; j < WORLDMAP_TILE_WIDTH_PER_CHUNK; j++)
	{
		for (int i = 0; i < WORLDMAP_TILE_WIDTH_PER_CHUNK; i++)
		{
			//this isn't done, it still needs to be mutiplied by the tile size
			RPGtransform t(chunkCoordinate.x + (double)i * (double)WORLDMAP_TILE_SIZE, chunkCoordinate.y + (double)j * (double)WORLDMAP_TILE_SIZE);

			positions->push_back(t);
		}
	}

	return 0;
}

bool fileHandler::folderExists(const std::string dir)
{
	char dir_cstr[1024];
	dir_cstr[1023] = '\0';

	strncpy(dir_cstr, dir.c_str(), sizeof(dir_cstr));

	dir_cstr[sizeof(dir_cstr) - 1] = 0;

	struct stat sb;

	if (stat(dir_cstr, &sb) == 0)
		return true;
	else
		return false;
}

void fileHandler::checkDirectory(const std::string dir)
{
	if (folderExists(dir))
		return;

	//oh uh is fs an instance of a namespace? I didn't know this was a thing
	namespace fs = std::filesystem;

	fs::create_directories(dir);
}