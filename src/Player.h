#ifndef PLAYER_H_
#define PLAYER_H_

#include "Brick.h"
#include "Enemy.h"
#include "Entity.h"

using namespace std;

namespace logic
{
	class Enemy;
	class Player : public Entity
	{
		public:
			Player();
			virtual ~Player();

			//From entity
			void move();
			void reset();

			void animate();
			void gotHit(Enemy* enemies[], int numOfEnemies);
			void setDirection(int key);

			virtual void paint() = 0;
			virtual void moveDir(int direction) = 0;

		protected:
			int direction = 4;
			int prevDirection = 4;
			int spriteSelector = 0;
	};
}

#endif
