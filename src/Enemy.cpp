#include "Enemy.h"

namespace logic
{
	Enemy::Enemy()
	{
		type = 0;
	}

	Enemy::~Enemy() {}

	bool Enemy::getAttackingState()
	{
		return attacking;
	}

	void Enemy::setAttackingState(bool attack)
	{
		if(mAliveState)
		{
			attacking = attack;
			flashing = false;
		}

		//TODO
		/*if(!attack){
			this->slowDown(2);
		}
		else{
			this->speedUp(2);
		}*/
	}

	void Enemy::reset()
	{
		x = (windowWidth/2)-(floor(numOfEnemies/2) * size)+(type*size);
		y = (windowHeight/2);
		mAliveState = true;
		attacking = true;
		flashing = false;
		isCaged = true;
	}

	bool Enemy::getFlashingState()
	{
		return flashing;
	}

	bool Enemy::setFlashingState(bool flash)
	{
		flashing = flash;
		return flashing;
	}

	void Enemy::move(int playerX, int playerY)
	{
		int oldx = x;
		int oldy = y;

		if(mAliveState)
		{
			if(isCaged)
			{
				timeCaged++;
				if(y == windowHeight/2 - 4 * size) //got out of cage
				{
					isCaged = false;
				}
			}

			if(!hunting)
			{
				if(timeSameDir > rand()%10 + 10) //too long in same direction
				{
					direction = rand()%4 + 1; //change direction
					timeSameDir = 0; //reset time for new direction
				}
				timeSameDir++;

				switch(direction)
				{
					case 1:
						y -= mSpeed;
						break;
					case 2:
						y += mSpeed;
						break;
					case 3:
						x -= mSpeed;
						break;
					case 4:
						x += mSpeed;
						break;
				}
				if(this->checkCollisions()) //not possible to go to direction
				{
						x = oldx;
						y = oldy;

						switch(prevDirection)
						{
							case 1:
								y -= mSpeed;
								break;
							case 2:
								y += mSpeed;
								break;
							case 3:
								x -= mSpeed;
								break;
							case 4:
								x += mSpeed;
								break;
						}

						if(this->checkCollisions())
						{
							x = oldx;
							y = oldy;
							direction = rand()%(4) + 1; //if stuck, change direction
						}
						else
						{
							prevDirection = direction;
						}
				}
				timeRandoming++;
			}
			else // its on the hunt
			{
				if(timeHunting < 30*(type+1))
				{
					if(isCaged && timeCaged > (50*type))
					{
						moveToCoordinates(windowWidth/2, windowHeight/2 - 4 * size);
					}
					else
					{
						moveToCoordinates(playerX, playerY);
						timeHunting++;
					}
				}
				else
				{
					timeHunting = 0;
					hunting = false;
					timeRandoming = 0;
				}
			}
			hunting = timeRandoming > 30*(type+1);
		}
		else //if dead go back to center
		{
			this->returnToCenter();
		}
		this->paint();
	}

	void Enemy::moveToPlayer(int playerX, int playerY)
	{

	}

	void Enemy::returnToCenter()
	{
		int tempx = (windowWidth/2);
		int tempy = (windowHeight/2);

		this->moveToCoordinates(tempx, tempy);

		if(x == tempx && y == tempy)
		{
			reset();
		}
	}

	void Enemy::moveToCoordinates(int coordx, int coordy)
	{
		int oldx = x;
		int oldy = y;

		if(x - coordx > 0) //TRY HORIZONTALLY;
		{
			x -= mSpeed;
		}
		else if (x - coordx < 0) //player is right of enemy
		{
			x += mSpeed;
		}

/*		if(this->checkCollisions())
		{
			x = oldx;
		}*/
		if(y - coordy > 0) //TRY VERTICALLY
		{
			y -= mSpeed;
		}
		else if (y - coordy < 0)
		{
			y += mSpeed;
		}

		if(this->checkCollisions())
		{
			x= oldx;
			y = oldy;
		}
	}
}
