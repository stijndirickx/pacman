#include "House.h"

namespace logic
{
	House::House(AbstractFactory* pAbstractFactory, string mapName, int pBrickSize)
	{
		mAbstractFactory = pAbstractFactory;
		mBrickSize = pBrickSize;

		file.open(mapName, std::ios::binary);
		if(file.fail()) //Error catching
		{
			printf("[House.cpp]: Can't load house.\n");
		}

		char line[256];
		file.getline(line, 256);
		int bricksWidth = file.tellg()/3; //get amount of bricks width
		file.seekg(0, ios::end);
		totalBricks = file.tellg()/3;  //get total bricks
		int bricksHeight = totalBricks / bricksWidth; //calculate amount of bricks height

		windowWidth = bricksWidth * mBrickSize; //brickamount * size = windowsize
		windowHeight = bricksHeight * mBrickSize;
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
			file >> type; //get type out of file
			bricks[i] = mAbstractFactory->createBrick(x, y, mBrickSize, type);
			if(type == 2) //count the plus-bricks
			{
				numOfPlus++;
			}
			x += mBrickSize;
			if(x >= windowWidth) //new row
			{
				x = 0;
				y += mBrickSize;
			}
		}
		file.close();
	}

	void House::load()
	{
		for(int i = 0; i < totalBricks; i++)
		{
			destroyedBricks[i] = 0;
		}
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
				mContext->addToScore(50);
				destroyedBricks[brickId] = 1;
			}
			else if(brickInfo[3] == 2) // Plus
			{
				mContext->addToScore(1);
				destroyedBricks[brickId] = 1;
				numOfPlus--;
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

	int House::getNumOfPlus()
	{
		return numOfPlus;
	}
}
