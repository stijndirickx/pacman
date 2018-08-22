#include "Context.h"

namespace logic
{
	Context::Context()
	{
		this->getHiScore();
	}

	Context::~Context()
	{

	}

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
		if(lives <= 0){
			playing = false;
			startText = "Game Over";
			if(score > hiScore){
				this->setHiScore(score);
			}
		} else {
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

	int Context::setScreenWidth(int width)
	{
		screenWidth = width;
		return screenWidth;
	}

	int Context::setScreenHeight(int height)
	{
		screenHeight = height;
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

	void Context::resetGame(){
		score = 0;
		startText = "Start again";
	}

	bool Context::checkCollision(int* entityBox, int* brickBox) //TODO study
	{
		int leftA, leftB;
		int rightA, rightB;
		int topA, topB;
		int bottomA, bottomB;

		leftA = entityBox[0];
		rightA = entityBox[0] + entityBox[2]; // + width
		topA = entityBox[1];
		bottomA = entityBox[1] + entityBox[3]; // + height

		leftB = brickBox[0];
		rightB = brickBox[0] + brickBox[2]; // + width
		topB = brickBox[1];
		bottomB = brickBox[1] + brickBox[3]; // + height

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

	void Context::setHouse(House* pHouse)
	{
		mHouse = pHouse;
	}

	Brick** Context::getBricks()
	{
		return mHouse->getBricks();
	}

	void Context::destroyBrick(int brick)
	{
		mHouse->destroyBrick(brick);
	}

	int Context::setHiScore(int score)
	{
		hiScore = score;
		stream.open("Assets/highscore.ini", std::ios::out);
		stream << score;
		stream.close();
		return hiScore;
	}

	int Context::getHiScore()
	{
		stream.open("Assets/highscore.ini", std::ios::in);
		stream >> hiScore;
		stream.close();
		return hiScore;
	}

	int Context::setNumOfEnemies(int pNumOfEnemies)
	{
		mNumOfEnemies = pNumOfEnemies;
		return mNumOfEnemies;
	}

	int Context::getNumOfEnemies()
	{
		return mNumOfEnemies;
	}
}
