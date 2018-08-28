#include "House.h"

namespace PACMAN
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

		screenWidth = lineLength * tileSize;
		screenHeight = (totalBricks/lineLength) * tileSize;
	}

	House::~House()
	{
		delete [] destroyedBricks;
		for(int tile = 0; tile < totalBricks; tile++)
		{
			delete bricks[tile];
		}
		delete [] bricks;
	}

	void House::setContext(Context* pContext)
	{
		mContext = pContext;
		mContext->setScreenWidth(screenWidth);
		mContext->setScreenHeight(screenHeight);
		mContext->setTotalTiles(totalBricks);
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
			if(x >= screenWidth)
			{
				x = 0;
				y += tileSize;
			}
		}
		numOfPelletsLeft = numOfPellets; //TODO deleted -15
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
			int* tileBoxInt = bricks[brickId]->getBoxInt();
			if(tileBoxInt[4] == 3) // PELLET TODO get variable int of pellet
			{
				mContext->playSound("eat");
				std::vector<Enemy*>enemies = mContext->getEnemies();
				for(size_t i = 0; i <= (enemies.size()-1); i++)
				{
					enemies[i]->setAttackingState(false);
				}
				destroyedBricks[brickId] = 1;
			}
			else if(tileBoxInt[4] == 25) // CHERRY
			{
				mContext->playSound("eat");
				mContext->addToScore(10);
				destroyedBricks[brickId] = 1;
			}
			else if(tileBoxInt[4] == 2) //PAC-DOT
			{
				mContext->addToScore(1);
				destroyedBricks[brickId] = 1;
				numOfPelletsLeft--;
			}
			delete tileBoxInt;
		}
	}

	int House::getScreenWidth()
	{
		return screenWidth;
	}

	int House::getScreenHeight()
	{
		return screenHeight;
	}

	int House::getNumOfPellets()
	{
		return numOfPelletsLeft;
	}
}
