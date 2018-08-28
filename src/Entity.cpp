#include "AbstractFactory.h"

namespace logic
{
	Entity::Entity()
	{
		collision = false;
		aFactory = NULL;
		mContext = NULL;

		x = 0;
		y = 0;
		size = 0;
	}

	Entity::~Entity()
	{
		delete entityBox;
	}

	void Entity::setContext(Context* pContext)
	{
		mContext = pContext;
		totalTiles = mContext->getTotalTiles();
		screenWidth = mContext->getScreenWidth();
		screenHeight = mContext->getScreenHeight();
		size = mContext->getTileSize();
		numOfEnemies = mContext->getNumOfEnemies();
	}

	void Entity::setAbstractFactory(AbstractFactory* fac)
	{
		aFactory = fac;
	}

	int* Entity::getCollisionBox()
	{
		entityBox[0] = x;
		entityBox[1] = y;
		entityBox[2] = size;
		entityBox[3] = size;
		return entityBox;
	}


	bool Entity::checkCollisions()
	{
		Brick** bricks = mContext->getBricks();

		collision = false;
		int* tileBoxInt = 0;

		for(int j = 0; j < totalTiles; j++) //CHECK TILES
		{
			tileBoxInt = bricks[j]->getBoxInt();

			bool tempCollide = mContext->checkCollision(this->getCollisionBox(), tileBoxInt);

			if(!collision && tempCollide)
			{
				if(tileBoxInt[4] >= 5 && tileBoxInt[4] <= 24) //is wall
				{
					collision = true;
				}
				if(isPac) //entity is pacman
				{
					mContext->destroyBrick(j);
				}
			}
		}

		delete tileBoxInt;
		return collision;
	}

	void Entity::setSpeed(int pSpeed)
	{
		mSpeed =  pSpeed;
	}
}
