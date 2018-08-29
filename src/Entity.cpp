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

			bool tempCollide = checkCollision(this->getCollisionBox(), brickBox);

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

	bool Entity::checkCollision(int* entityBox, int* brickBox)
	{
		bool horizontalColl1 = (entityBox[0] + entityBox[2]) > brickBox[0];
		bool horizontalColl2 = entityBox[0] < (brickBox[0] + brickBox[2]);
		bool verticalColl1 = (entityBox[1] + entityBox[2]) > brickBox[1];
		bool verticalColl2 = entityBox[1] < (brickBox[1] + brickBox[2]);
		return (horizontalColl1 && horizontalColl2 && verticalColl1 && verticalColl2);
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
