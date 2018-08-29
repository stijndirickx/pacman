#include "Context.h"

namespace logic
{
	Context::Context()
	{
		this->getHiscore();
	}

	Context::~Context() {}

	void Context::resetGame()
	{
		score = 0;
		mDisplay = "Start again";
	}

	bool Context::checkCollision(int* entityBox, int* brickBox)
	{
		bool horizontalColl1 = (entityBox[0] + entityBox[2]) > brickBox[0];
		bool horizontalColl2 = entityBox[0] < (brickBox[0] + brickBox[2]);
		bool verticalColl1 = (entityBox[1] + entityBox[2]) > brickBox[1];
		bool verticalColl2 = entityBox[1] < (brickBox[1] + brickBox[2]);
		return (horizontalColl1 && horizontalColl2 && verticalColl1 && verticalColl2);
	}


	//Lives
	int Context::getLives()
	{
		return lives;
	}

	int Context::subtractLives(int subtraction)
	{
		lives -= subtraction;
		return lives;
	}

	int Context::setLives(int numOfLives)
	{
		lives = numOfLives;
		return lives;
	}


	//Pause
	bool Context::getPlaying()
	{
		return playing;
	}

	bool Context::setPlaying(bool play, string pDisplay)
	{
		if(lives <= 0)
		{
			playing = false;
			mDisplay = "game over";
			if(score > mHiscore)
			{
				this->setHiscore(score);
			}
		}
		else
		{
			playing = play;
			mDisplay = pDisplay;
		}
		return playing;
	}


	//Score
	int Context::getScore()
	{
		return score;
	}

	int Context::addToScore(int addition)
	{
		score += addition;
		return score;
	}

	int Context::setHiscore(int pHiscore)
	{
		mHiscore = pHiscore;
		file.open("Assets/hiscore.ini", std::ios::out);
		file << pHiscore;
		file.close();
		return mHiscore;
	}

	int Context::getHiscore()
	{
		file.open("Assets/hiscore.ini", std::ios::in);
		file >> mHiscore;
		file.close();
		return mHiscore;
	}


	//Window
	int Context::setwindowWidth(int pWindowWidth)
	{
		mWindowWidth = pWindowWidth;
		return mWindowWidth;
	}

	int Context::setwindowHeight(int pWindowHeight)
	{
		mWindowHeight = pWindowHeight;
		return mWindowHeight;
	}

	int Context::getwindowWidth()
	{
		return mWindowWidth;
	}

	int Context::getwindowHeight()
	{
		return mWindowHeight;
	}


	//Bricks & House
	int Context::setTotalBricks(int totalBricks)
	{
		numOfBricks = totalBricks;
		return numOfBricks;
	}

	int Context::getTotalBricks()
	{
		return numOfBricks;
	}

	int Context::setBrickSize(int size)
	{
		brickSize = size;
		return brickSize;
	}

	int Context::getBrickSize()
	{
		return brickSize;
	}

	Brick** Context::getBricks()
	{
		return mHouse->getBricks();
	}

	void Context::destroyBrick(int brickId)
	{
		mHouse->destroyBrick(brickId);
	}

	void Context::setHouse(House* pHouse)
	{
		mHouse = pHouse;
	}


	//Enemies
	void Context::addEnemy(Enemy* enemy)
	{
		enemies.push_back(enemy);
	}

	std::vector<Enemy*> Context::getEnemies()
	{
		return enemies;
	}

	int Context::setNumOfEnemies(int pNumber)
	{
		numOfEnemies = pNumber;
		return numOfEnemies;
	}

	int Context::getNumOfEnemies()
	{
		return numOfEnemies;
	}
}
