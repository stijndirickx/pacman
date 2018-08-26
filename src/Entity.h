#ifndef ENTITY_H_
#define ENTITY_H_

#include <iostream>
#include "Tile.h"
#include "GameContext.h"
using namespace std;

namespace PACMAN
{
	class GameContext;
	class Factory; //Forward declaration so the compiler knows what Factory is --> to use CheckCollision
	class Entity
	{
		public:
			Entity();
			virtual ~Entity();
			void SetFactory(Factory* fac);
			bool CheckCollisions();
			int* GetCollisionBox();
			void SetGameContext(GameContext* gameContext);

		protected:
			Factory* aFactory;
			GameContext* gContext;
			bool collision;
			int mPosX, mPosY;
			int mWidth, mHeight;
			int* entityBox = new int [4];
			bool isPac = false;
			int totalTiles = 0;
			int screenWidth = 0;
			int screenHeight = 0;
			int numOfGhosts = 0;
	};
}

#endif
