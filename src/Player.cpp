#include "Player.h"

namespace PACMAN
{
	Player::Player()
	{
		isPac = true;
	}

	Player::~Player() {}

	int Player::getX()
	{
		return x;
	}

	int Player::getY()
	{
		return y;
	}

	void Player::setDirection(int key)
	{
		if(direction != key)
		{
			direction = key;
		}
	}

	bool Player::getAliveState()
	{
		return aliveState;
	}

	bool Player::setAliveState(bool pAliveState)
	{
		aliveState = pAliveState;
		if(pAliveState)
		{
			x = (screenWidth/2);
			y = floor(3*screenHeight/4);
		}
		return aliveState;
	}

	void Player::animate()
	{
		if(aliveState)
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
			x = screenWidth;
		}

		if(x > screenWidth)
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
					aliveState = false; //poor thing died :(
				}

				else
				{
					enemies[i]->setLivingState(false);
					mContext->playSound("kill");
				}
			}

			delete ghostBoxInt;
		}
	}

	void Player::setSpeed(int pSpeed)
	{
		playerSpeed = pSpeed;
	}
}
