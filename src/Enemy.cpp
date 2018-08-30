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
		if(mAliveState)
		{
			int tempx = x;
			int tempy = y;
			if(changeDir >= rand()%(10) + 10) //after x movements change direction
			{
				dir[type] = rand()%(4) + 1;
				changeDir = 0;
			}
			changeDir++;

			switch(dir[type])
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
					x = tempx;
					y = tempy;

					switch(prevDir[type])
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
		this->paint();
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
		int tempx = x;
		int tempy = y;

		if(x - coordx > 0) //TRY HORIZONTALLY;
		{
			x -= mSpeed;
		}
		else if (x - coordx < 0)
		{
			x += mSpeed;
		}

		if(this->checkCollisions())
		{
			x = tempx;
		}


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
			y = tempy;
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
			else if (tempx > windowWidth)
			{
				tempx = windowWidth;
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
			else if (tempy > windowHeight)
			{
				tempy = windowHeight;
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
