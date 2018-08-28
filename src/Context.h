#ifndef CONTEXT_H_
#define CONTEXT_H_

#include <iostream>
#include <fstream>
#include <vector>

#include "Enemy.h"
#include "House.h"

using namespace std;

namespace PACMAN
{
	class Enemy;
	class House;
	class Context
	{
		public:
			Context();
			virtual ~Context();

			int getLives();
			int subtractLives(int subtraction);
			int setLives(int numOfLives);
			bool getPlaying();
			bool setPlaying(bool play, string text);
			int getScore();
			int addToScore(int addition);
			int setScreenWidth(int sWidth);
			int setScreenHeight(int sHeight);
			int getScreenWidth();
			int getScreenHeight();
			int setTotalTiles(int totalTiles);
			int getTotalTiles();
			int setTileSize(int size);
			int getTileSize();
			void resetGame();
			bool checkCollision(int* a, int* b);
			void addEnemy(Enemy* enemy);
			std::vector<Enemy*> getEnemies();
			void setMap(House* pHouse);
			Brick** getBricks();
			void destroyBrick(int brickId);
			int setHighscore(int score);
			int getHighscore();
			int setNumOfEnemies(int pNumber);
			int getNumOfEnemies();

			virtual void updateText() = 0;
			virtual void playSound(string sound) = 0;
			virtual void clearScreen() = 0;
			virtual void updateScreen() = 0;
			virtual void quitVis() = 0;

		protected:
			int screenWidth = 0;
			int screenHeight = 0;
			int numOfBricks = 0;
			int numOfEnemies = 0;
			std::vector<Enemy*> enemies;
			House* mHouse = NULL;
			std::fstream hs;

			int highScore = 0;
			int score = 0;
			bool playing = false;
			string startText = "Start";

			int brickSize = 20;
			int lives = 3;
	};
}

#endif
