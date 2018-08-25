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

			string getMapFile();
			string getSpritesFile();

			int getBrickSize();
			int getFps();
			int getFpa();

			int getEnemiesCount();
			int getLivesCount();

		protected:
			string mapFile = "Assets/Maps/house.map";
			string spritesFile = "Assets/Sprites/sprites.png";

			int brickSize = 20;
			int fpa = 3; 		//frames per animation
			int fps = 30; 		//frames per second

			int enemiesCount = 4;
			int livesCount = 4;
	};
}

#endif
