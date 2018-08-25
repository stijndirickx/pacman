#include "Config.h"

namespace PACMAN
{
	Config::Config()
	{
		this->getConfig();
	}

	Config::~Config() {	}

	void Config::getConfig()
	{
		ifstream configFile;
		configFile.open("Assets/config.cfg");
		string line;
		while(getline(configFile, line))
		{
			if(line[0] != '#' || !line.empty())
			{
				int delimiterPos = line.find("=");
				int pId = atoi(line.substr(0, delimiterPos).c_str());
				string value = line.substr(delimiterPos + 1);

				switch(pId)
				{
					case 1:
						numOfGhosts = atoi(value.c_str());
						break;
					case 2:
						fps = atoi(value.c_str());
						break;
					case 3:
						animationSpeed = atoi(value.c_str());
						break;
					case 4:
						mapFile = value;
						break;
					case 5:
						brickSize = atoi(value.c_str());
						break;
					case 6:
						lives = atoi(value.c_str());
						break;
				}
			}
		}
		configFile.close();
	}

	int Config::getNumOfGhost()
	{
		return numOfGhosts;
	}

	int Config::getFps()
	{
		return fps;
	}

	int Config::getAnimationSpeed()
	{
		return animationSpeed;
	}

	string Config::getMapName()
	{
		return mapFile;
	}

	int Config::getTileSize()
	{
		return brickSize;
	}

	int Config::getLives()
	{
		return lives;
	}
}
