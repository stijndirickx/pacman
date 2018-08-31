#ifndef ENTITY_H_
#define ENTITY_H_

#include "Brick.h"
#include "Context.h"

namespace logic
{
	class Context;
	class AbstractFactory;
	class Entity
	{
		public:
			Entity();
			virtual ~Entity();

			int* getCollisionBox();
			bool checkCollisions(); //uses protected method checkCollision

			void setAbstractFactory(AbstractFactory* pAbstractFactory );
			void setContext(Context* pContext);

			//Pos
			int getX();
			int getY();

			//Speed
			void setSpeed(int pSpeed);
			void speedUp(int factor);
			void slowDown(int factor);

			//State
			void setAliveState(bool pAliveState);
			bool getAliveState();

			virtual void reset() = 0;

		protected:
			bool checkCollision(int* entityBox, int* brickBox);

			//Variables
			AbstractFactory* mAbstractFactory = NULL;
			bool collision = false;
			int x = 0, y = 0;
			int* entityBox = new int [3];
			bool isPlayer = false; //Used for collision
			bool isCaged = true; //Used for collision
			int mSpeed = 1;
			int mAliveState = true;

			//From context ~ setContext function
			Context* mContext = NULL;
			int totalBricks = 0;
			int windowWidth = 0;
			int windowHeight = 0;
			int numOfEnemies = 0;
			int size = 0;
	};
}

#endif
