#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>

#include "Factory.h"
#include "Entity.h"
#include "Ghost.h"

using namespace std;

namespace PACMAN
{
	class Ghost;
	class Player : public Entity
	{
		public:
		Player();
			virtual ~Player();

			int getX();
			int getY();
			void setDirection(int key);
			bool getLiving();
			bool setLiving(bool alive);
			void animate();
			void move();
			void gotCaptured(Ghost* ghosts[], int numOfGhosts);

			virtual void paint() = 0;
			virtual void moveDir(int direction) = 0;

		protected:
			int pacmanVel = 5; // velocity = tilesize / pacmanVel
			bool living = true;
			int direction = 4;
			int prevDirection = 4;
			int frame = 0;
	};
}

#endif
