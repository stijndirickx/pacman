#ifndef ENTITY_H_
#define ENTITY_H_

#include <iostream>

#include "Brick.h"
#include "Context.h"

using namespace std;

namespace logic
{
	class Context;
	class AbstractFactory; //Forward declaration so the compiler knows what Factory is --> to use CheckCollision
	class Entity
	{
		public:
			Entity();
			virtual ~Entity();

			void setAbstractFactory(AbstractFactory* fac);
			bool checkCollisions();
			int* getCollisionBox();
			void setContext(Context* pContext);

			void setSpeed(int pSpeed);
			void setAliveState(bool pAliveState);
			bool getAliveState();

		protected:
			AbstractFactory* aFactory;
			Context* mContext;
			bool collision;
			int x, y, size;
			int* entityBox = new int [4];
			bool isPac = false;
			int totalTiles = 0;
			int screenWidth = 0;
			int screenHeight = 0;
			int numOfEnemies = 0;

			int mSpeed = 1;
			int mAliveState = true;
	};
}

#endif
