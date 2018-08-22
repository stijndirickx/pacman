#ifndef ENTITY_H_
#define ENTITY_H_

#include <iostream>

//#include "AbstractFactory.h"
#include "Brick.h"
#include "Context.h"

using namespace std;

namespace logic
{
	class AbstractFactory; //TODO del?
	class Context;			//TODO del?
	class Entity
	{
		public:
			Entity();
			virtual ~Entity();

			bool checkCollisions();
			int* getCollisionBox();
			void setAbstractFactory(AbstractFactory* pAbstractFactory);
			void setContext(Context* pContext);

		protected:
			AbstractFactory* mAbstractFactory;
			Context* mContext;
			int x = 0, y = 0, w = 0, h = 0;
			int* box = new int [4];
			bool collision = false;
			bool isPlayer = false;
			int totalBricks = 0;
			int screenWidth = 0;
			int screenHeight = 0;
			int numOfEnemies = 0;
	};
}

#endif
