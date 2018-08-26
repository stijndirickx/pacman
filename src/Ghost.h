#ifndef GHOST_H_
#define GHOST_H_

#include <iostream>
#include <math.h>

#include "Factory.h"
#include "Entity.h"

using namespace std;

namespace PACMAN
{
	class Ghost : public Entity
	{
		public:
			Ghost();
			virtual ~Ghost();
			bool GetAttackingState();
			void SetAttackingState(bool attack);
			bool GetLivingState();
			void SetLivingState(bool live);
			void ResetGhost();
			bool SetFlashingState(bool flash);
			bool GetFlashingState();
			void Move();
			void ReturnToCenter();
			void MoveTo(int x, int y);
			void MoveToCoordinates(int x, int y);
			void MoveInFront(int x, int y);

			virtual void Visualize() = 0;

		protected:
			int type;
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
