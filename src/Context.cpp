#include "Context.h"

namespace PACMAN
{
	Context::Context()
	{
		this->getHighscore();
	}

	Context::~Context() {}

	int Context::getLives()
	{
		return lives;
	}


	int Context::subtractLives(int subtraction)
	{
		lives = lives - subtraction;
		return lives;
	}

	int Context::setLives(int numOfLives)
	{
		lives = numOfLives;
		return lives;
	}

	bool Context::getPlaying()
	{
		return playing;
	}

	bool Context::setPlaying(bool play, string text)
	{
		if(lives <= 0)
		{
			playing = false;
			startText = "Game Over";
			if(score > highScore)
			{
				this->setHighscore(score);
			}
		}
		else
		{
			playing = play;
			startText = text;
		}
		return playing;
	}

	int Context::getScore()
	{
		return score;
	}

	int Context::addToScore(int addition)
	{
		score = score + addition;
		return score;
	}

	int Context::setScreenWidth(int sWidth)
	{
		screenWidth = sWidth;
		return screenWidth;
	}

	int Context::setScreenHeight(int sHeight)
	{
		screenHeight = sHeight;
		return screenHeight;
	}

	int Context::getScreenWidth()
	{
		return screenWidth;
	}

	int Context::getScreenHeight()
	{
		return screenHeight;
	}

	int Context::setTotalTiles(int totalTiles)
	{
		numOfBricks = totalTiles;
		return numOfBricks;
	}

	int Context::getTotalTiles()
	{
		return numOfBricks;
	}

	int Context::setTileSize(int size)
	{
		brickSize = size;
		return brickSize;
	}

	int Context::getTileSize()
	{
		return brickSize;
	}

	void Context::resetGame()
	{
		score = 0;
		startText = "Start again";
	}

	bool Context::checkCollision(int* entityBox, int* tileBox)
	{
		int leftA, leftB;
		int rightA, rightB;
		int topA, topB;
		int bottomA, bottomB;

		leftA = entityBox[0];
		rightA = entityBox[0] + entityBox[2]; // + width
		topA = entityBox[1];
		bottomA = entityBox[1] + entityBox[3]; // + height

		leftB = tileBox[0];
		rightB = tileBox[0] + tileBox[2]; // + width
		topB = tileBox[1];
		bottomB = tileBox[1] + tileBox[3]; // + height

		if( rightA > leftB && leftA < rightB && topA < bottomB && bottomA > topB)
		{
			return true;
		}
		return false;
	}

	void Context::addEnemy(Enemy* enemy)
	{
		enemies.push_back(enemy);
	}

	std::vector<Enemy*> Context::getEnemies()
	{
		return enemies;
	}

	void Context::setMap(House* pHouse)
	{
		mHouse = pHouse;
	}

	Brick** Context::getBricks()
	{
		return mHouse->getBricks();
	}

	void Context::destroyBrick(int brickId)
	{
		mHouse->destroyBrick(brickId);
	}

	int Context::setHighscore(int hscore)
	{
		highScore = hscore;
		hs.open("Assets/highscore.ini", std::ios::out);
		hs << hscore;
		hs.close();
		return highScore;
	}

	int Context::getHighscore()
	{
		hs.open("Assets/highscore.ini", std::ios::in);
		hs >> highScore;
		hs.close();
		return highScore;
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
