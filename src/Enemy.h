#ifndef ENEMY_H_
#define ENEMY_H_

#include <math.h>
#include <iostream>

#include "AbstractFactory.h" //TODO NEW
#include "Entity.h"

namespace logic
{
	class Enemy : public Entity //TODO rename alot here
	{
		public:
			Enemy();
			virtual ~Enemy();

			bool getAttackingState();
			void setAttackingState(bool attack);
			bool getLivingState();
			void setLivingState(bool live);
			void resetEnemy();
			bool setFlashingState(bool flash);
			bool getFlashingState();
			void move();
			void returnToCenter();
			void moveTo(int pX, int pY);
			void moveToCoordinates(int pX, int pY);
			void moveInFront(int pX, int pY);

			virtual void paint() = 0;

		protected:
			int type = 0;
			bool attacking = true;
			bool flashing = false;
			bool living = true;
			int prevDir[4] = { 1, 1, 1, 1 };
			int dir[4] = { 1, 1, 1, 1 };
			int changeDir = 0;

			int ghostVel = 5; // velocity = tilesize / ghostVel
	};
}

#endif
