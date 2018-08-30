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

		bricks = new Brick*[totalBricks];
		destroyedBricks = new int [totalBricks];

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
			std::vector<Enemy*>enemies = mContext->getEnemies();
			switch(brickInfo[3])
			{
				case 2: //Plus
					mContext->addToScore(10);
					numOfPlus--;
					break;
				case 3: //Big plus
					mContext->addToScore(50);
					mContext->playSound(5);
					for(size_t i = 0; i <= (enemies.size()-1); i++)
					{
						enemies[i]->setAttackingState(false);
					}
					break;
				case 33: //Eclipse
					mContext->addToScore(-100);
					mContext->playSound(7);
					break;
			}
			if(brickInfo[3] == 2 || brickInfo[3] == 3 || brickInfo[3] == 33)
			{
				destroyedBricks[brickId] = 1;
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
