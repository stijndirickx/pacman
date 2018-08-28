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
		return entityBox;
	}


	bool Entity::checkCollisions()
	{
		Brick** bricks = mContext->getBricks();

		collision = false;
		int* tileBoxInt = 0;

		for(int j = 0; j < totalTiles; j++) //CHECK TILES
		{
			tileBoxInt = bricks[j]->getProp();

			bool tempCollide = mContext->checkCollision(this->getCollisionBox(), tileBoxInt);

			if(!collision && tempCollide)
			{
				if(tileBoxInt[3] >= 5 && tileBoxInt[3] <= 24) //is wall
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

	void Entity::setAliveState(bool pAliveState)
	{
		mAliveState = pAliveState;
	}

	bool Entity::getAliveState()
	{
		return mAliveState;
	}

	void Entity::speedUp(int factor)
	{
		mSpeed = mSpeed * factor;
	}

	void Entity::slowDown(int factor)
	{
		if(factor != 0)
		{
			mSpeed = mSpeed / factor;
		}
	}

	int Entity::getX()
	{
		return x;
	}

	int Entity::getY()
	{
		return y;
	}
}
