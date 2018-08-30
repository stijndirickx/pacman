#include "Enemy.h"

namespace logic
{
	Enemy::Enemy(){}
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

		//Uncomment for slowdown while vulnerable
		/*if(!attack){
			this->slowDown(2);
		}
		else{
			this->speedUp(2);
		}*/
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

	void Enemy::reset()
	{
		x = (windowWidth/2)-(floor(numOfEnemies/2) * size)+(type*size);
		y = (windowHeight/2);
		mAliveState = true;
		attacking = true;
		flashing = false;
		isCaged = true;
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

			if(!hunting) //its random moving
			{
				if(timeSameDir > rand()%10 + 10) //too long in same direction
				{
					direction = rand()%4 + 1; //change direction
					timeSameDir = 0; //reset time for new direction
				}
				timeSameDir++;
				reposition(direction);

				if(this->checkCollisions()) //not possible to go to direction, get new direction
				{
					x = oldx;
					y = oldy;
					reposition(prevDirection); //Try previous direction, to keep moving as enemy

					if(this->checkCollisions())
					{
						x = oldx;
						y = oldy;
						direction = rand()%(4) + 1; //if stuck again, change direction
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
					if(isCaged && timeCaged > (50*type)) //Force enemies out of cage, one by one
					{
						moveToCoordinates(windowWidth/2, windowHeight/2 - 4 * size); //Go out cage
					}
					else
					{
						moveToCoordinates(playerX, playerY);	//Hunt the player
						timeHunting++;
					}
				}
				else //stop the hunting
				{
					hunting = false;
					timeHunting = 0;
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

	void Enemy::reposition(int direction)
	{
		switch(direction)
		{
			case 1: //Down
				y -= mSpeed;
				break;
			case 2: //Up
				y += mSpeed;
				break;
			case 3: //Left
				x -= mSpeed;
				break;
			case 4: //Right
				x += mSpeed;
				break;
		}
	}

	void Enemy::returnToCenter()
	{
		int posx = (windowWidth/2);
		int posy = (windowHeight/2);
		this->moveToCoordinates(posx, posy);

		if(x == posx && y == posy)
		{
			reset();
		}
	}

	void Enemy::moveToCoordinates(int coordx, int coordy)
	{
		//Check x
		int oldx = x;
		x = newPos(x, coordx); //Left or right
		if(this->checkCollisions())
		{
			x = oldx;
		}

		//Check y
		int oldy = y;
		y = newPos(y, coordy); //Up or down
		if(this->checkCollisions())
		{
			y = oldy;
		}
	}

	int Enemy::newPos(int pos, int coord)
	{
		if(pos - coord > 0)
		{
			pos -= mSpeed;
		}
		else if(pos - coord < 0)
		{
			pos += mSpeed;
		}
		return pos;
	}
}
