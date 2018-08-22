#include "Player.h"

namespace logic
{

	Player::Player()
	{
		isPlayer = true;
	}

	Player::~Player()
	{

	}

	void Player::animate() //TODO study tho
	{
		if(mAlive)
		{
			if(Entity::collision) //TODO delete comment --> stuck
			{
				frame = 1;
			}
			else
			{
				frame++;
				if(frame > 2)
				{
					frame = 0;
				}
			}
		}
		else
		{
			frame++;
			if(frame > 14)
			{
				frame = 2;
			}
		}
	}

	int Player::getX()
	{
		return x;
	}

	int Player::getY()
	{
		return y;
	}

	void Player::gotCaptured(Enemy* enemies[], int numOfEnemies)
	{
		for(int i = 0; i < numOfEnemies; i++)
		{
			int* enemyInfo = enemies[i]->getCollisionBox();
			bool captured = Entity::mContext->checkCollision(this->getCollisionBox(), enemyInfo);
			if(captured)
			{
				if(enemies[i]->getAttackingState())
				{
					Entity::mContext->subtractLives(1);
					Entity::mContext->setPlaying(false,"death"); //TODO check
					Entity::mContext->playSound("death");
					mAlive = false;
				}

				else
				{
					enemies[i]->setLivingState(false);
					Entity::mContext->playSound("eatghost");
				}
			}
			delete enemyInfo;
		}
	}

	bool Player::isAlive()
	{
		return mAlive;
	}

	void Player::move()
	{
		int tempX = Entity::x;
		int tempY = Entity::y;

		this->moveInDir(direction);
		if(this->checkCollisions())
		{
			Entity::x = tempX;
			Entity::y = tempY;

			this->moveInDir(prevDirection);
			if(this->checkCollisions())
			{
				Entity::x = tempX;
				Entity::y = tempY;
			}
		}
		else
		{
			prevDirection = direction;
		}

		if(Entity::x < -20) //TODO too far comment
		{
			Entity::x = Entity::screenWidth;
		}

		if(Entity::x > Entity::screenWidth)
		{
			Entity::x = -20;
		}

		this->paint();
	}

	void Player::setDirection(int key)
	{
		if(direction != key)
		{
			direction = key;
		}
	}

	bool Player::setAlive(bool pAlive)
	{
		mAlive = pAlive;
		if(mAlive)
		{
			Entity::x = Entity::screenWidth/2;
			Entity::y = floor(3*Entity::screenHeight/4); //TODO maybe a bit too specific
		}
		return mAlive;
	}
}

