#include "Config.h"
#include <fstream> //TODO move to config.h?

namespace logic
{
	Config::Config()
	{
		this->getConfig(); //TODO try getconfig method here?
	}

	Config::~Config()
	{
		// TODO Auto-generated destructor stub
	}

	void Config::getConfig()
	{
		ifstream stream;
		stream.open("Assets/config.cfg");
		string line;
		while(getline(stream, line))
		{
			if(line[0] != '#' || !line.empty()) //# gives commentline
			{
				int delimiterPos = line.find("=");
				string param = line.substr(0, delimiterPos);
				string value = line.substr(delimiterPos + 1);

				if(param == "animationSpeed")
				{
					animationSpeed = atoi(value.c_str());
				}
				else if(param == "brickSize")
				{
					brickSize = atoi(value.c_str());
				}
				else if(param == "fileName")
				{
					fileName = atoi(value.c_str());
				}
				else if(param == "fps")
				{
					fps = atoi(value.c_str());
				}
				else if(param == "lives")
				{
					lives = atoi(value.c_str());
				}
				else if(param == "numOfEnemies")
				{
					numOfEnemies = atoi(value.c_str());
				}
			}
		}
		stream.close();
	}

	int Config::getAnimationSpeed()
	{
		return animationSpeed;
	}

	int Config::getBrickSize()
	{
		return brickSize;
	}

	string Config::getFileName()
	{
		return fileName;
	}

	int Config::getFps()
	{
		return fps;
	}

	int Config::getLives()
	{
		return lives;
	}

	int Config::getNumOfEnemies()
	{
		return numOfEnemies;
	}
}
