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

int fileHandler::loadChunkFile(int x, int y, std::vector<SimpleTile>* arr)
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

	return 0;
}

bool fileHandler::folderExists(const std::string dir)
{
	char dir_cstr[1024];

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