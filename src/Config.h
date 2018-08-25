/*
 * Config.h
 *
 *  Created on: May 13, 2018
 *      Author: ruben
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#include <iostream>
using namespace std;

namespace PACMAN {
	class Config {
	public:
		Config();
		virtual ~Config();

		void GetConfig();
		int GetNumOfGhost();
		int GetFps();
		int GetAnimationSpeed();
		string GetMapName();
		int GetTileSize();
		int GetLives();
	protected:
		// DEFAULT VALUES
		int numOfGhosts = 4;
		int fps = 30; //best 30
		int animationSpeed = 3; //every x frames sprite change
		string mapName = "Assets/Map2.map";
		int tileSize = 20;
		int lives = 4;
	};
}

#endif /* CONFIG_H_ */
