#ifndef CONTEXT_H_
#define CONTEXT_H_

#include <iostream>
#include <vector>
#include <fstream>

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

			//TODO really need some RENAMES
			int getLives();
			int subtractLives(int subtraction);
			int setLives(int numOfLives);
			bool getPlaying();
			bool setPlaying(bool play, string text);
			int getScore();
			int addToScore(int addition);
			int setScreenWidth(int width);
			int setScreenHeight(int height);
			int getScreenWidth();
			int getScreenHeight();
			int setTotalBricks(int totalBricks);
			int getTotalBricks();
			int setBrickSize(int size);
			int getBrickSize();
			void resetGame();
			bool checkCollision(int* a, int* b);
			void addEnemy(Enemy* enemy);
			std::vector<Enemy*> getEnemies();
			void setHouse(House* pHouse);
			Brick** getBricks();
			void destroyBrick(int brick);
			int setHiScore(int score);
			int getHiScore();
			int setNumOfEnemies(int pNumOfEnemies);
			int getNumOfEnemies();

			virtual void updateText() = 0;
			virtual void playSound(string sound) = 0;
			virtual void clearScreen() = 0;
			virtual void updateScreen() = 0;
			virtual void quitVisualization() = 0;

		protected:
			int screenWidth = 0;
			int screenHeight = 0;
			int numOfBricks = 0;
			int mNumOfEnemies = 0;
			std::vector<Enemy*> enemies;
			House* mHouse = NULL;
			std::fstream stream; //for hiscores

			int hiScore = 0;
			int score = 0;
			bool playing = false;
			string startText = "Start";

			int brickSize = 20;
			int lives = 3;
	};
}

#endif
