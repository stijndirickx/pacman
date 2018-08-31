#include "Player.h"

namespace logic
{
	Player::Player()
	{
		isPlayer = true;
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
		int oldx = x;
		int oldy = y;
		this->moveDir(direction);

		if(this->checkCollisions()) //Collision while trying to move
		{
			x = oldx;
			y = oldy;

			this->moveDir(prevDirection); //Move back in previous direction
			if(this->checkCollisions())
			{
				x = oldx;
				y = oldy;
			}
		}
		else
		{
			prevDirection = direction;
		}
		this->paint();
	}

	void Player::gotHit(Enemy* enemies[], int numOfEnemies)
	{
		for(int i = 0; i<numOfEnemies; i++)
		{
			bool captured = checkCollision(this->getCollisionBox(), enemies[i]->getCollisionBox());
			if(captured)
			{
				if(enemies[i]->getAttackingState()) //Agressive enemies
				{
					mContext->subtractLives(1);
					mContext->setPlaying(false, "A live has been taken");
					mContext->playSound(4);
					mAliveState = false;
				}

				else		//Vulnerable enemies
				{
					enemies[i]->setAliveState(false);
					mContext->playSound(6);
				}
			}
		}
	}

	void Player::reset()
	{
		x = (windowWidth/2);
		y = floor(3*windowHeight/4);
		mAliveState = true;
		setDirection(4);
	}
}
