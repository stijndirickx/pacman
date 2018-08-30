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
		collision = false; //reset before checking
		Brick** bricks = mContext->getBricks(); //get all bricks

		for(int i = 0; i < totalBricks; i++) //check every brick
		{
			if(!collision) //keep searching till collision is found
			{
				int* brickBox = bricks[i]->getProp(); //get brick x,y and size
				if(checkCollision(this->getCollisionBox(), brickBox)) //grab entity x,y and size and check
				{
					if(isPlayer) //entity is player
					{
						collision = (brickBox[3] >= 4 && brickBox[3] <= 24); //collision was wall or barrier
						mContext->destroyBrick(i); //only player can destroybricks
					}
					else //entity is enemy
					{
						if(brickBox[3] >= 5 && brickBox[3] <= 24) //collision was wall
						{
							collision = mAliveState; //dont collide if enemy is dead (for easier return to center)
						}
					}
				}
				delete brickBox;
			}
		}
		return collision;
	}

	bool Entity::checkCollision(int* entityBox, int* brickBox)
	{
		bool horizontalColl1 = (entityBox[0] + entityBox[2]) > brickBox[0]; //entity got hit from right
		bool horizontalColl2 = entityBox[0] < (brickBox[0] + brickBox[2]); //entity got hit from left
		bool verticalColl1 = (entityBox[1] + entityBox[2]) > brickBox[1]; //entity got hit from bottom
		bool verticalColl2 = entityBox[1] < (brickBox[1] + brickBox[2]); //entity got hit from top
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
