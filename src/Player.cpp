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
		if(this->CheckCollisions())
		{
			x = tempX;
			y = tempY;

			this->moveDir(prevDirection);
			if(this->CheckCollisions())
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

	void Player::gotCaptured(Ghost* ghosts[], int numOfGhosts)
	{
		for(int i = 0; i<numOfGhosts; i++)
		{
			int* ghostBoxInt = ghosts[i]->GetCollisionBox();
			bool captured = gContext->CheckCollision(this->GetCollisionBox(), ghostBoxInt);
			if(captured)
			{
				if(ghosts[i]->GetAttackingState())
				{
					gContext->SubtractLives(1);
					gContext->SetPlaying(false, "Dead");
					gContext->PlaySound("dead");
					aliveState = false; //poor thing died :(
				}

				else
				{
					ghosts[i]->SetLivingState(false);
					gContext->PlaySound("kill");
				}
			}

			delete ghostBoxInt;
		}
	}
}
