#ifndef CONFIG_H_
#define CONFIG_H_

#include <iostream>
//#include <fstream>

using namespace std;

namespace logic
{
	class Config
	{
		public:
			Config();
			virtual ~Config();
			void getConfig();

			int getAnimationSpeed();
			int getBrickSize();
			string getFileName(); //For house
			int getFps();
			int getLives();
			int getNumOfEnemies();

		protected:
			//DEFAULT VALUES //TODO other parameters? why these parameters?
			int animationSpeed = 3;
			int brickSize = 20;
			string fileName = "Assets/house.map";
			int fps = 30;
			int lives = 4;
			int numOfEnemies = 4;
	};
}

#endif
