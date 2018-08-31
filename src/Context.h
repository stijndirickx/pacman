#ifndef CONTEXT_H_
#define CONTEXT_H_

#include <iostream>
#include <fstream>
#include <vector>

#include "Enemy.h"
#include "House.h"

using namespace std;

namespace logic
{
	class Enemy;
	class House;
	class Context
	{
		public:
			Context();
			virtual ~Context();

			//Lives
			int getLives();
			int subtractLives(int subtraction);
			int setLives(int numOfLives);
			void addToLives(int addition);
			bool isExtraLiveGiven();

			//Pause
			bool getPlaying();
			bool setPlaying(bool play, string pDisplay);
			void resetGame();

			//Score
			int getScore();
			int addToScore(int addition);
			int setHiscore(int pHiscore);
			int getHiscore();

			//Window
			int setwindowWidth(int sWidth);
			int setwindowHeight(int sHeight);
			int getwindowWidth();
			int getwindowHeight();

			//Bricks & House
			int setTotalBricks(int totalBricks);
			int getTotalBricks();
			int setBrickSize(int brickSize);
			int getBrickSize();
			Brick** getBricks();
			void destroyBrick(int brickId);
			void setHouse(House* pHouse);

			//Enemies
			void addEnemy(Enemy* enemy);
			std::vector<Enemy*> getEnemies();
			int setNumOfEnemies(int pNumber);
			int getNumOfEnemies();


			virtual void updateText() = 0;
			virtual void playMusic(int musicId) = 0;
			virtual void playSound(int soundId) = 0;
			virtual void clearScreen() = 0;
			virtual void updateScreen() = 0;

		protected:

			//Lives
			int lives = 3;
			bool extraLiveGiven = false;

			//Pause
			bool playing = false;
			string mDisplay = "Start";

			//Score
			std::fstream file;
			int mHiscore = 0;
			int score = 0;

			//Window
			int mWindowWidth = 0;
			int mWindowHeight = 0;

			//Bricks & House
			int numOfBricks = 0;
			int brickSize = 20;
			House* mHouse = NULL;

			//Enemies
			int numOfEnemies = 0;
			std::vector<Enemy*> enemies;
	};
}

#endif
