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
			void move();

			void returnToCenter();
			void moveTo(int x, int y);
			void moveToCoordinates(int x, int y);
			void moveInFront(int x, int y);

			virtual void paint() = 0;

		protected:
			int type;
			bool attacking = true;
			bool flashing = false;

			int prevDir[4] = { 1, 1, 1, 1 };
			int dir[4] = { 1, 1, 1, 1 };
			int changeDir = 0;
	};
}

#endif
