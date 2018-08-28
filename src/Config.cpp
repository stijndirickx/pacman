#include "Config.h"

namespace logic
{
	Config::Config()
	{
		this->getConfig();
	}

	Config::~Config() {	}

	void Config::getConfig()
	{
		string line;
		ifstream file;
		file.open("Assets/config.cfg");
		while(getline(file, line))
		{
			if(line[0] != '#' || !line.empty()) // '#'-char gives a comment line
			{
				int split = line.find("|");
				int id = atoi(line.substr(0, split).c_str());
				string value = line.substr(split + 1);

				switch(id)
				{
					case 1:
						mapFile = value;
						break;
					case 2:
						spritesFile = value;
						break;
					case 11:
						brickSize = atoi(value.c_str());
						break;
					case 12:
						fpa = atoi(value.c_str());
						break;
					case 13:
						fps = atoi(value.c_str());
						break;
					case 21:
						enemiesCount = atoi(value.c_str());
						break;
					case 22:
						livesCount = atoi(value.c_str());
						break;
					case 23:
						playerSpeed = atoi(value.c_str());
						break;
				}
			}
		}
		file.close();
	}

	string Config::getMapFile()
	{
		return mapFile;
	}

	string Config::getSpritesFile()
	{
		return spritesFile;
	}

	int Config::getBrickSize()
	{
		return brickSize;
	}

	int Config::getFps()
	{
		return fps;
	}

	int Config::getFpa()
	{
		return fpa;
	}

	int Config::getEnemiesCount()
	{
		return enemiesCount;
	}

	int Config::getLivesCount()
	{
		return livesCount;
	}

	int Config::getPlayerSpeed()
	{
		return playerSpeed;
	}
}
