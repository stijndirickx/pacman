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

			int getX();
			int getY();

			void setAbstractFactory(AbstractFactory* pAbstractFactory );
			bool checkCollisions();
			bool checkCollision(int* entityBox, int* brickBox);
			int* getCollisionBox();
			void setContext(Context* pContext);

			void setSpeed(int pSpeed);
			void speedUp(int factor);
			void slowDown(int factor);

			void setAliveState(bool pAliveState);
			bool getAliveState();

		protected:
			AbstractFactory* mAbstractFactory = NULL;

			//From context ~ setContext function
			Context* mContext = NULL;
			int totalBricks = 0;
			int windowWidth = 0;
			int windowHeight = 0;
			int numOfEnemies = 0;
			int size = 0;


			bool collision = false;
			int x = 0, y = 0;
			int* entityBox = new int [3];
			bool isPlayer = false;
			int mSpeed = 1;
			int mAliveState = true;
	};
}

#endif
