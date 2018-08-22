#include "Enemy.h"

namespace logic
{
	Enemy::Enemy()
	{

	}

	Enemy::~Enemy()
	{

	}

	bool Enemy::getAttackingState()
	{
		return attacking;
	}

	void Enemy::setAttackingState(bool attack)
	{
		if(living)
		{
			attacking = attack;
			flashing = false;
		}
	}

	bool Enemy::getLivingState()
	{
		return living;
	}

	void Enemy::setLivingState(bool live)
	{
		living = live;
	}

	void Enemy::resetEnemy()
	{
		x = (screenWidth/2)-(floor(numOfEnemies/2) * w)+(type*w);
		y = (screenHeight/2);
		living = true;
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

	void Enemy::move(){ //TODO REALLY STUDY THIS RANDOM MOVEMENT
		int velocity = w / ghostVel;

		if(living)
		{
			int tempX = x;
			int tempY = y;
			if(changeDir >= 15 )		//after x movements change direction
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
				x = tempX;
				y = tempY;

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
					x = tempX;
					y = tempY;
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
		if(x > screenWidth)
		{
			x = -30;
		}

		this->paint();
	}

	void Enemy::returnToCenter()
	{
		int tempX = (screenWidth/2);
		int tempY = (screenHeight/2);
		this->moveToCoordinates(tempX, tempY);
		if(x == tempX && y == tempY)
		{
			living = true;
			attacking = true;
			flashing = false;
		}
	}

	void Enemy::moveToCoordinates(int pX, int pY){
		int tempX = x;
		int tempY = y;
		int velocity = w / ghostVel;

		//TRY HORIZONTALLY
		if(x - pX > 0)
		{
			x -= velocity;
		}
		else if (x - pX < 0)
		{
			x += velocity;
		}
		if(this->checkCollisions())
		{
			x = tempX;
		}

		//TRY VERTICALLY
		if(y - pY > 0)
		{
			y -= velocity;
		}
		else if (y - pY < 0)
		{
			y += velocity;
		}
		if(this->checkCollisions())
		{
			y = tempY;
		}

		if(y == tempY && x == tempX) //TODO why is this still here?
		{
			//this->Move();
		}
	}

	void Enemy::moveTo(int pX, int pY)
	{
		if(living)
		{
			this->moveToCoordinates(pX, pY);
		}
		else
		{
			this->returnToCenter();
		}
		this->paint();
	}

	void Enemy::moveInFront(int pX, int pY) //TODO del comments
	{
		if(living)
		{
			int tempX, tempY;
			int further = 4;
			if(x - pX > 0) //pacman to the left of the ghost
			{
				tempX = pX - (further*w);
			}
			else
			{
				tempX = pX + (further*w);
			}

			if(tempX < 0)
			{
				tempX = 0;
			}
			else if (tempX > screenWidth)
			{
				tempX = screenWidth;
			}

			if(y - pY > 0) //pacman above the ghost
			{
				tempY = pY - (further*h);
			}
			else
			{
				tempY = pY + (further*h);
			}

			if(tempY < 0)
			{
				tempY = 0;
			}
			else if (tempY > screenHeight)
			{
				tempY = screenHeight;
			}

			this->moveToCoordinates(tempX, tempY);
		}

		else
		{
			this->returnToCenter();
		}
		this->paint();
	}
}
