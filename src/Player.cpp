#include "Player.h"

namespace logic
{
	Player::Player()
	{
		isPac = true;
	}

	Player::~Player() {}

	void Player::setDirection(int key)
	{
		if(direction != key)
		{
			direction = key;
		}
	}

	void Player::animate()
	{
		if(mAliveState)
		{
			if(collision)  //stuck
			{
				spriteSelector = 1;
			}
			else	//moving between 0-2
			{
				spriteSelector++;
				if(spriteSelector > 2)
				{
					spriteSelector = 0;
				}
			}
		}
		else //dead
		{
			spriteSelector++;
			if(spriteSelector > 14)
			{
				spriteSelector = 14; //= 2 for repeating dead animation
			}
		}
	}

	void Player::move()
	{
		int tempX = x;
		int tempY = y;

		this->moveDir(direction);
		if(this->checkCollisions())
		{
			x = tempX;
			y = tempY;

			this->moveDir(prevDirection);
			if(this->checkCollisions())
			{
				x = tempX;
				y = tempY;
			}
		}
		else
		{
			prevDirection = direction;
		}

		if(x < 0)
		{
			x = windowWidth;
		}

		if(x > windowWidth)
		{
			x = 0;
		}

		this->paint();
	}

	void Player::gotCaptured(Enemy* enemies[], int numOfEnemies)
	{
		for(int i = 0; i<numOfEnemies; i++)
		{
			int* ghostBoxInt = enemies[i]->getCollisionBox();
			bool captured = mContext->checkCollision(this->getCollisionBox(), ghostBoxInt);
			if(captured)
			{
				if(enemies[i]->getAttackingState())
				{
					mContext->subtractLives(1);
					mContext->setPlaying(false, "Dead");
					mContext->playSound("dead");
					mAliveState = false; //poor thing died :(
				}

				else
				{
					enemies[i]->setAliveState(false);
					mContext->playSound("kill");
				}
			}

			delete ghostBoxInt;
		}
	}

/*	void Player::setSpeed(int pSpeed)
	{
		playerSpeed = pSpeed;
	}*/
}
