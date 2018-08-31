#include "Context.h"

namespace logic
{
	Context::Context()
	{
		this->getHiscore();
	}

	Context::~Context() {}


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

	void Context::addToLives(int addition)
	{
		extraLiveGiven = true;
		lives++;
	}

	int Context::setLives(int numOfLives)
	{
		lives = numOfLives;
		return lives;
	}

	bool Context::isExtraLiveGiven()
	{
		return extraLiveGiven;
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
			mDisplay = "rip, try again!";
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

	void Context::resetGame()
	{
		level = 1;
		score = 0;
		mDisplay = "Start again";
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

	int Context::getVulnerableTime()
	{
		return vulnerableTime;
	}


	//Level
	int Context::getLevel()
	{
		return level;
	}

	void Context::nextLevel() //Enemies become less long vulnerable
	{
		level++;
		if(vulnerableTime >= 1000)
		{
			vulnerableTime -= 1000;
		}
	}
}
