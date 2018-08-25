/*
 * Config.cpp
 *
 *  Created on: May 13, 2018
 *      Author: ruben
 */

#include "Config.h"
#include <fstream>

namespace PACMAN {
	Config::Config() {
		this->GetConfig();
	}

	Config::~Config() {
		// TODO Auto-generated destructor stub
	}

	void Config::GetConfig() {
		ifstream configFile;
		configFile.open("Assets/config.cfg");
		string line;
		while(getline(configFile, line)){
			if(line[0] != '#' || !line.empty())
			{
				int delimiterPos = line.find("=");
				string param = line.substr(0, delimiterPos);
				string value = line.substr(delimiterPos + 1);
				if(param == "numberOfGhosts"){
					numOfGhosts = atoi(value.c_str());
				} else if (param == "fps") {
					fps = atoi(value.c_str());
				} else if (param == "animationSpeed") {
					animationSpeed = atoi(value.c_str());
				} else if (param == "mapName") {
					mapName = value;
				} else if (param == "tileSize") {
					tileSize = atoi(value.c_str());
				} else if (param == "lives") {
					lives = atoi(value.c_str());
				}
			}
		}
		configFile.close();
	}

	int Config::GetNumOfGhost(){
		return numOfGhosts;
	}

	int Config::GetFps(){
		return fps;
	}

	int Config::GetAnimationSpeed(){
		return animationSpeed;
	}

	string Config::GetMapName(){
		return mapName;
	}

	int Config::GetTileSize(){
		return tileSize;
	}

	int Config::GetLives(){
		return lives;
	}
}
