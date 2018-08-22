#include "House.h"

namespace logic
{
	House::House(AbstractFactory* pAbstractFactory, string pFileName, int pBrickSize)
	{
		mAbstractFactory = pAbstractFactory;
		mBrickSize = pBrickSize;
		mContext = NULL;
		numOfPellets = 0, numOfPelletsLeft = 0;
		stream.open(pFileName, std::ios::binary);
		if(stream.fail())
		{
			printf("Unable to load house from given file. \n");
		}

		char line[256];
		stream.getline(line, 256);
		int lineLength = stream.tellg()/2;
		stream.seekg(0, ios::end);
		totalBricks = stream.tellg()/2;
		screenWidth = lineLength * mBrickSize;
		screenHeight = (totalBricks/lineLength) * mBrickSize;

	}

	House::~House()
	{
		delete [] destroyedBricks;
		for(int brick = 0; brick < totalBricks; brick++)
		{
			delete brickSet[brick];
		}
		delete [] brickSet;
	}

	void House::setContext(Context* pContext) //TODO uncomment when context implemented
	{
		mContext = pContext;
		mContext->setScreenWidth(screenWidth);
		mContext->setScreenHeight(screenHeight);
		mContext->setTotalBricks(totalBricks);
	}

	void House::createHouse()
	{
		stream.seekg(0, ios::beg);
		int x = 0, y = 0;
		for(int brick = 0; brick < totalBricks; brick++)
		{
			int brickType = 0;
			stream >> brickType;
			brickSet[brick] = mAbstractFactory->createBrick(x, y, brickType, mBrickSize, mBrickSize);
			if(brickType == 0)
			{
				numOfPellets++;
			}
			x += mBrickSize;
			if(x >= screenWidth)
			{
				x = 0;
				y += mBrickSize;
			}
		}
		numOfPelletsLeft = (numOfPellets-15); //TODO get explanation
		stream.close();
	}

	void House::load()
	{
		for(int brick = 0; brick < totalBricks; brick++)
		{
			destroyedBricks[brick] = 0;
		}
		numOfPelletsLeft = numOfPellets;
	}

	void House::draw()
	{
		for(int brick = 0; brick < totalBricks; brick++)
		{
			if(destroyedBricks[brick] != 1)
			{
				brickSet[brick]->visualize();
			}
		}
	}

	Brick** House::getBricks()
	{
		return brickSet;
	}

	void House::destroyBrick(int brick){

		//TODO study closely, some important game logic here
		if(destroyedBricks[brick] != 1){
			int* brickInfo = brickSet[brick]->readBrickInfo();
			if(brickInfo[4] == 9){ // TODO change number to correspond to pellet
				mContext->playSound("eat");
				std::vector<Enemy*>enemies = mContext->getEnemies();
				for(size_t i = 0; i <= (enemies.size()-1); i++){
					//enemies[i]->setAttackingState(false); TODO after implement enemy
				}
				destroyedBricks[brick] = 1;
			} else if(brickInfo[4] == 8){ //TODO change number to correspond to CHERRY
				mContext->playSound("eat");
				mContext->addToScore(10);
				destroyedBricks[brick] = 1;
			} else if(brickInfo[4] == 0){ //TODO change number to correspond to PAC-DOT
				mContext->addToScore(1);
				destroyedBricks[brick] = 1;
				numOfPelletsLeft--;
			}
			delete brickInfo;
		}
	}


	int House::getScreenWidth(){
		return screenWidth;
	}

	int House::getScreenHeight(){
		return screenHeight;
	}

	int House::getNumOfPellets(){
		return numOfPelletsLeft;
	}


}
