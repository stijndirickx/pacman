#include "House.h"

namespace logic
{
	House::House(AbstractFactory* abstractFactory, string mapName, int size)
	{
		aFactory = abstractFactory;
		mContext = NULL;
		tileSize = size;
		numOfPellets = 0;
		numOfPelletsLeft = 0;
		map.open(mapName, std::ios::binary);
		if( map.fail() )
		{
			printf( "Unable to load map file!\n" );
		}

		char line[256];
		map.getline(line, 256); //get position at first line
		int lineLength = map.tellg()/3;

		map.seekg(0, ios::end); //to the end of the file
		totalBricks = map.tellg()/3; //get the number of tiles

		windowWidth = lineLength * tileSize;
		windowHeight = (totalBricks/lineLength) * tileSize;
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

	void House::createMap()
	{
		map.seekg(0, ios::beg);
		int x = 0, y = 0;

		for(int tile = 0; tile < totalBricks; tile++)
		{
			int tileType = 0;
			map >> tileType;
			bricks[tile] = aFactory->createBrick(x, y, tileType, tileSize, tileSize);
			if(tileType == 2)
			{
				numOfPellets++;
			}
			x += tileSize;
			if(x >= windowWidth)
			{
				x = 0;
				y += tileSize;
			}
		}
		numOfPelletsLeft = numOfPellets;
		map.close();
	}

	void House::load()
	{
		for(int tile = 0; tile < totalBricks; tile++)
		{
			destroyedBricks[tile] = 0;
		}
		numOfPelletsLeft = numOfPellets;
	}

	void House::draw()
	{
		for(int tile = 0; tile < totalBricks; tile++)
		{
			if(destroyedBricks[tile] != 1)
			{
				bricks[tile]->paint();
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
				mContext->playSound("eat");
				std::vector<Enemy*>enemies = mContext->getEnemies();
				for(size_t i = 0; i <= (enemies.size()-1); i++)
				{
					enemies[i]->setAttackingState(false);
				}
				destroyedBricks[brickId] = 1;
			}
			else if(brickInfo[3] == 25) // Eclipse
			{
				mContext->playSound("eat");
				mContext->addToScore(10);
				destroyedBricks[brickId] = 1;
			}
			else if(brickInfo[3] == 2) // Plus
			{
				mContext->addToScore(1);
				destroyedBricks[brickId] = 1;
				numOfPelletsLeft--;
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

	int House::getNumOfPellets()
	{
		return numOfPelletsLeft;
	}
}
