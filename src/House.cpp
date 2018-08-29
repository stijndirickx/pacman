#include "House.h"

namespace logic
{
	House::House(AbstractFactory* pAbstractFactory, string mapName, int pBrickSize)
	{
		mAbstractFactory = pAbstractFactory;
		mContext = NULL;
		mBrickSize = pBrickSize;
		numOfPlus = 0;
		numOfPlusLeft = 0;
		file.open(mapName, std::ios::binary);
		if(file.fail())
		{
			printf("[House.cpp]: Can't load house.\n");
		}

		char line[256]; // 83 chars
		file.getline(line, 256); //get position at first line
		int lineLength = 28;//file.tellg()/3;

		file.seekg(0, ios::end); //to the end of the file
		totalBricks = file.tellg()/3; //get the number of tiles

		windowWidth = lineLength * mBrickSize;
		windowHeight = (totalBricks/lineLength) * mBrickSize;
	}

	House::~House()
	{
		delete [] destroyedBricks;
		for(int i = 0; i < totalBricks; i++)
		{
			delete bricks[i];
		}
		delete [] bricks;
	}

	void House::setContext(Context* pContext)
	{
		mContext = pContext;
		mContext->setwindowWidth(windowWidth);
		mContext->setwindowHeight(windowHeight);
		mContext->setTotalBricks(totalBricks);
	}

	void House::createHouse()
	{
		file.seekg(0, ios::beg);
		int x = 0, y = 0;

		for(int i = 0; i < totalBricks; i++)
		{
			int type = 0;
			file >> type;
			bricks[i] = mAbstractFactory->createBrick(x, y, mBrickSize, type);
			if(type == 2)
			{
				numOfPlus++;
			}
			x += mBrickSize;
			if(x >= windowWidth)
			{
				x = 0;
				y += mBrickSize;
			}
		}
		numOfPlusLeft = numOfPlus;
		file.close();
	}

	void House::load()
	{
		for(int i = 0; i < totalBricks; i++)
		{
			destroyedBricks[i] = 0;
		}
		numOfPlusLeft = numOfPlus;
	}

	void House::paint()
	{
		for(int i = 0; i < totalBricks; i++)
		{
			if(destroyedBricks[i] != 1)
			{
				bricks[i]->paint();
			}
		}
	}

	Brick** House::getBricks()
	{
		return bricks;
	}

	void House::destroyBrick(int brickId)
	{
		if(destroyedBricks[brickId] != 1)
		{
			int* brickInfo = bricks[brickId]->getProp();
			if(brickInfo[3] == 3) // Big plus
			{
				mContext->playSound(5);
				std::vector<Enemy*>enemies = mContext->getEnemies();
				for(size_t i = 0; i <= (enemies.size()-1); i++)
				{
					enemies[i]->setAttackingState(false);
				}
				destroyedBricks[brickId] = 1;
			}
			else if(brickInfo[3] == 25) // Eclipse
			{
				mContext->playSound(7);
				mContext->addToScore(10);
				destroyedBricks[brickId] = 1;
			}
			else if(brickInfo[3] == 2) // Plus
			{
				mContext->addToScore(1);
				destroyedBricks[brickId] = 1;
				numOfPlusLeft--;
			}
			delete brickInfo;
		}
	}

	int House::getwindowWidth()
	{
		return windowWidth;
	}

	int House::getwindowHeight()
	{
		return windowHeight;
	}

	int House::getNumOfPlusLeft()
	{
		return numOfPlusLeft;
	}
}
