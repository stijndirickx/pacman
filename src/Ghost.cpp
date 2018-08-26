#include "Ghost.h"

namespace PACMAN
{
	Ghost::Ghost()
	{
		type = 0;
	}

	Ghost::~Ghost() {}

	bool Ghost::GetAttackingState()
	{
		return attacking;
	}

	void Ghost::SetAttackingState(bool attack)
	{
		if(living)
		{
			attacking = attack;
			flashing = false;
		}
	}

	bool Ghost::GetLivingState()
	{
		return living;
	}

	void Ghost::SetLivingState(bool live)
	{
		living = live;
	}

	void Ghost::ResetGhost()
	{
		x = (screenWidth/2)-(floor(numOfGhosts/2) * size)+(type*size);
		y = (screenHeight/2);
		living = true;
		attacking = true;
	}

	bool Ghost::GetFlashingState()
	{
		return flashing;
	}

	bool Ghost::SetFlashingState(bool flash)
	{
		flashing = flash;
		return flashing;
	}

	void Ghost::Move() //RANDOM MOVEMENT
	{
		int velocity = size / ghostVel;
		if(living)
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

			if(this->CheckCollisions()) //not possible to go to direction
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

					if(this->CheckCollisions())
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
			this->ReturnToCenter();
		}

		if(x < -30) //ghost went to far
		{
			x = screenWidth;
		}

		if(y > screenWidth)
		{
			y = -30;
		}

		this->Visualize();
	}

	void Ghost::ReturnToCenter()
	{
		int tempx = (screenWidth/2);
		int tempy = (screenHeight/2);

		this->MoveToCoordinates(tempx, tempy);

		if(x == tempx && y == tempy)
		{
			living = true;
			attacking = true;
			flashing = false;
		}
	}

	void Ghost::MoveToCoordinates(int coordx, int coordy)
	{
		int tempx = x;
		int tempy = y;
		int velocity = size / ghostVel;

		if(x - coordx > 0) //TRY HORIZONTALLY;
		{
			x -= velocity;
		}
		else if (x - coordx < 0)
		{
			x += velocity;
		}

		if(this->CheckCollisions())
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

		if(this->CheckCollisions())
		{
			y = tempy;
		}

		if(y == tempy && x == tempx)
		{
			//this->Move();
		}
	}

	void Ghost::MoveTo(int x, int y)
	{
		if(living)
		{
			this->MoveToCoordinates(x, y);
		}
		else
		{
			this->ReturnToCenter();
		}
		this->Visualize();
	}

	void Ghost::MoveInFront(int pX, int pY)
	{
		if(living)
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

			this->MoveToCoordinates(tempx, tempy);
		}
		else
		{
			this->ReturnToCenter();
		}
		this->Visualize();
	}
}
