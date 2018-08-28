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
	}

	void Enemy::resetEnemy()
	{
		x = (screenWidth/2)-(floor(numOfEnemies/2) * size)+(type*size);
		y = (screenHeight/2);
		mAliveState = true;
		attacking = true;
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

	void Enemy::move() //RANDOM MOVEMENT
	{
		int velocity = size / mSpeed;
		if(mAliveState)
		{
			int tempx = x;
			int tempy = y;
			if(changeDir >= 15 ) //after x movements change direction
			{
				dir[type] = rand()%(4) + 1;
				changeDir = 0;
			}
			changeDir++;

			switch(dir[type])
			{
				case 1:
					y -= velocity;
					break;
				case 2:
					y += velocity;
					break;
				case 3:
					x -= velocity;
					break;
				case 4:
					x += velocity;
					break;
			}

			if(this->checkCollisions()) //not possible to go to direction
			{
					x = tempx;
					y = tempy;

					switch(prevDir[type])
					{
						case 1:
							y -= velocity;
							break;
						case 2:
							y += velocity;
							break;
						case 3:
							x -= velocity;
							break;
						case 4:
							x += velocity;
							break;
					}

					if(this->checkCollisions())
					{
						x = tempx;
						y = tempy;
						dir[type] = rand()%(4) + 1; //if stuck, change direction
					}
			}
			else
			{
				prevDir[type] = dir[type];
			}
		}
		else
		{
			this->returnToCenter();
		}

		if(x < -30) //ghost went to far
		{
			x = screenWidth;
		}

		if(y > screenWidth)
		{
			y = -30;
		}

		this->paint();
	}

	void Enemy::returnToCenter()
	{
		int tempx = (screenWidth/2);
		int tempy = (screenHeight/2);

		this->moveToCoordinates(tempx, tempy);

		if(x == tempx && y == tempy)
		{
			mAliveState = true;
			attacking = true;
			flashing = false;
		}
	}

	void Enemy::moveToCoordinates(int coordx, int coordy)
	{
		int tempx = x;
		int tempy = y;
		int velocity = size / mSpeed;

		if(x - coordx > 0) //TRY HORIZONTALLY;
		{
			x -= velocity;
		}
		else if (x - coordx < 0)
		{
			x += velocity;
		}

		if(this->checkCollisions())
		{
			x = tempx;
		}


		if(y - coordy > 0) //TRY VERTICALLY
		{
			y -= velocity;
		}
		else if (y - coordy < 0)
		{
			y += velocity;
		}

		if(this->checkCollisions())
		{
			y = tempy;
		}

		if(y == tempy && x == tempx)
		{
			//this->Move();
		}
	}

	void Enemy::moveTo(int x, int y)
	{
		if(mAliveState)
		{
			this->moveToCoordinates(x, y);
		}
		else
		{
			this->returnToCenter();
		}
		this->paint();
	}

	void Enemy::moveInFront(int pX, int pY)
	{
		if(mAliveState)
		{
			int tempx, tempy;
			int further = 4;
			if(x - pX > 0) //pacman to the left of the ghost
			{
				tempx = pX - (further*size);
			}
			else
			{
				tempx = pX + (further*size);
			}

			if(tempx < 0)
			{
				tempx = 0;
			}
			else if (tempx > screenWidth)
			{
				tempx = screenWidth;
			}

			if(y - pY > 0) //pacman above the ghost
			{
				tempy = pY - (further*size);
			}
			else
			{
				tempy = pY + (further*size);
			}

			if(tempy < 0)
			{
				tempy = 0;
			}
			else if (tempy > screenHeight)
			{
				tempy = screenHeight;
			}

			this->moveToCoordinates(tempx, tempy);
		}
		else
		{
			this->returnToCenter();
		}
		this->paint();
	}
}
