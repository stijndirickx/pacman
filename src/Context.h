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

			void resetGame();
			bool checkCollision(int* a, int* b);

			//Lives
			int getLives();
			int subtractLives(int subtraction);
			int setLives(int numOfLives);

			//Pause
			bool getPlaying();
			bool setPlaying(bool play, string text);

			//Score
			int getScore();
			int addToScore(int addition);
			int setHighscore(int score);
			int getHighscore();

			//Screen
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
			int windowWidth = 0;
			int windowHeight = 0;
			int numOfBricks = 0;
			int numOfEnemies = 0;
			std::vector<Enemy*> enemies;
			House* mHouse = NULL;
			std::fstream hs;

			int highScore = 0;
			int score = 0;
			bool playing = false;

			string displayString = "Start";

			int brickSize = 20;
			int lives = 3;
	};
}

#endif
