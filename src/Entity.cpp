#include "AbstractFactory.h"
//#include "Entity.h" TODO

namespace logic
{
	Entity::Entity()
	{
		mAbstractFactory = NULL;
		mContext = NULL;
	}

	Entity::~Entity()
	{
		delete box;
	}

	bool Entity::checkCollisions()
	{
		collision = false;
		Brick** bricks = mContext->getBricks();
		int* brickInfo = 0;

		for(int i = 0; i < totalBricks; i++)
		{
			brickInfo = bricks[i]->readBrickInfo();
			bool temp = mContext->checkCollision(this->getCollisionBox(), brickInfo);

			if(!collision && temp)
			{
				if(brickInfo[4] > 0 && brickInfo[4] <= 6) //TODO (is wall?) dirty code?
				{
					collision = true;
				}

				if(isPlayer)
				{
					mContext->destroyBrick(i);
				}
			}
		}

		delete brickInfo;
		return collision;
	}

	int* Entity::getCollisionBox()
	{
		box[0] = x;
		box[1] = y;
		box[2] = w;
		box[3] = h;
		return box;
	}

	void Entity::setAbstractFactory(AbstractFactory* pAbstractFactory)
	{
		mAbstractFactory = pAbstractFactory;
	}

	void Entity::setContext(Context* pContext)
	{
		mContext = pContext;
		totalBricks = mContext->getTotalBricks();
		screenWidth = mContext->getScreenWidth();
		screenHeight = mContext->getScreenHeight();
		w = mContext->getBrickSize();					//TODO check to make easier
		h = mContext->getBrickSize();
		numOfEnemies = mContext->getNumOfEnemies();
	}
}

