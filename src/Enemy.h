#ifndef ENEMY_H_
#define ENEMY_H_

#include <iostream>
#include <math.h>

#include "AbstractFactory.h"
#include "Entity.h"

using namespace std;

namespace logic
{
	class Enemy : public Entity
	{
		public:
			Enemy();
			virtual ~Enemy();

			bool getAttackingState();
			void setAttackingState(bool attack);
			bool getFlashingState();
			bool setFlashingState(bool flash);

			//From entity
			void reset();
			void move(int playerX, int playerY);

			virtual void paint() = 0;

		protected:
			void moveToCoordinates(int x, int y);
			int newPos(int pos, int coord);
			void reposition(int direction);
			void returnToCenter();

			//Movement AI controls
			bool hunting = false;
			int timeCaged = 0;
			int timeHunting = 0;
			int timeSameDir = 0;
			int timeRandoming = 0;
			int direction = 0;
			int prevDirection = 0;

			int type = 0;
			bool attacking = true;
			bool flashing = false;
	};
}

#endif
