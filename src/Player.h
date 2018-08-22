#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>

#include "AbstractFactory.h"
#include "Entity.h"
#include "Enemy.h"

using namespace std;

namespace logic
{
	class Enemy;
	class Player : public Entity
	{
		public:
			Player();
			virtual ~Player();

			void animate();
			int getX();
			int getY();
			void gotCaptured(Enemy* enemies[], int numOfEnemies);
			bool isAlive();
			void move();
			void setDirection(int key);
			bool setAlive(bool pAlive);

			virtual void paint() = 0;
			virtual void moveInDir(int direction) = 0;

		protected:
			int pacmanVel = 5; // velocity = tilesize / pacmanVel
			bool mAlive = true;
			int direction = 4;
			int prevDirection = 4;
			int frame = 0; //player has different frames
	};
}

#endif
