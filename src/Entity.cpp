#include "AbstractFactory.h"

namespace logic
{
	Entity::Entity(){}

	Entity::~Entity()
	{
		delete entityBox;
	}

	void Entity::setContext(Context* pContext)
	{
		mContext = pContext;
		totalBricks = mContext->getTotalBricks();
		windowWidth = mContext->getwindowWidth();
		windowHeight = mContext->getwindowHeight();
		numOfEnemies = mContext->getNumOfEnemies();
		size = mContext->getBrickSize();
	}

	void Entity::setAbstractFactory(AbstractFactory* pAbstractFactory )
	{
		mAbstractFactory  = pAbstractFactory ;
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
		int* brickBox = 0;

		for(int i = 0; i < totalBricks; i++) //CHECK TILES
		{
			brickBox = bricks[i]->getProp();

			bool tempCollide = mContext->checkCollision(this->getCollisionBox(), brickBox);

			if(!collision && tempCollide)
			{
				if(brickBox[3] >= 5 && brickBox[3] <= 24) //is wall
				{
					collision = true;
				}
				if(isPlayer) //entity is player
				{
					mContext->destroyBrick(i);
				}
			}
		}

		delete brickBox;
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
