#ifndef CONFIG_H_
#define CONFIG_H_

#include <fstream>
#include <iostream>

using namespace std;

namespace logic
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
			int getPlayerSpeed();
			int getEnemySpeed();

		protected:

			//Default values:

			string mapFile = "Assets/Maps/house.map";
			string spritesFile = "Assets/Sprites/sprites.png";

			int brickSize = 20;
			int fpa = 3; 		//frames per animation
			int fps = 30; 		//frames per second

			int enemiesCount = 4;
			int livesCount = 4;
			int playerSpeed = 4;
			int enemySpeed = 4;
	};
}

#endif
