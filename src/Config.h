#ifndef CONFIG_H_
#define CONFIG_H_

#include <fstream>
#include <iostream>

using namespace std;

namespace PACMAN
{
	class Config
	{
		public:
			Config();
			virtual ~Config();

			void getConfig();
			int getNumOfGhost();
			int getFps();
			int getAnimationSpeed();
			string getMapName();
			int getTileSize();
			int getLives();

		protected:

			int numOfGhosts = 4;
			int fps = 30; //best 30
			int animationSpeed = 3; //every x frames sprite change

			int brickSize = 20;
			int lives = 4;


			string mapFile = "Assets/Maps/house.map";
			string spriteFile = "Assets/Sprites/sprites.png";
	};
}

#endif
