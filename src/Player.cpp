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
		return mPosX;
	}

	int Player::getY()
	{
		return mPosY;
	}

	void Player::setDirection(int key)
	{
		if(direction != key)
		{
			direction = key;
		}
	}

	bool Player::getLiving()
	{
		return living;
	}

	bool Player::setLiving(bool alive)
	{
		living = alive;
		if(alive)
		{
			mPosX = (screenWidth/2);
			mPosY = floor(3*screenHeight/4);
		}
		return living;
	}

	void Player::animate()
	{
		if(living)
		{
			if(collision)  //stuck
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

	void Player::move()
	{
		int tempPosX = mPosX;
		int tempPosY = mPosY;

		this->moveDir(direction);
		if(this->CheckCollisions()) //not possible to go to direction
		{
			mPosX = tempPosX;
			mPosY = tempPosY;

			this->moveDir(prevDirection); //keep going prev direction
			if(this->CheckCollisions())
			{
				mPosX = tempPosX;
				mPosY = tempPosY;
			}
		}
		else
		{
			prevDirection = direction;
		}

		if(mPosX < -20) //pacman went to far
		{
			mPosX = screenWidth;
		}

		if(mPosX > screenWidth)
		{
			mPosX = -20;
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
					living = false;
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
