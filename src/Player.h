#ifndef PLAYER_H_
#define PLAYER_H_

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
			bool getAliveState();
			bool setAliveState(bool pAliveState);
			void animate();
			void move();
			void gotCaptured(Ghost* ghosts[], int numOfGhosts);

			virtual void paint() = 0;
			virtual void moveDir(int direction) = 0;

		protected:
			int pacmanVel = 3; // velocity = tilesize / pacmanVel
			bool aliveState = true;
			int direction = 4;
			int prevDirection = 4;
			int spriteSelector = 0;
	};
}

#endif
