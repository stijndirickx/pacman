#include "Factory.h"

namespace PACMAN
{
	Entity::Entity()
	{
		collision = false;
		aFactory = NULL;
		gContext = NULL;

		x = 0;
		y = 0;
		size = 0;
	}

	Entity::~Entity()
	{
		delete entityBox;
	}

	void Entity::SetGameContext(GameContext* gameContext)
	{
		gContext = gameContext;
		totalTiles = gContext->GetTotalTiles();
		screenWidth = gContext->GetScreenWidth();
		screenHeight = gContext->GetScreenHeight();
		size = gContext->GetTileSize();
		numOfGhosts = gContext->GetNumOfGhosts();
	}

	void Entity::SetFactory(Factory* fac)
	{
		aFactory = fac;
	}

	int* Entity::GetCollisionBox()
	{
		entityBox[0] = x;
		entityBox[1] = y;
		entityBox[2] = size;
		entityBox[3] = size;
		return entityBox;
	}


	bool Entity::CheckCollisions()
	{
		Tile** tileSet = gContext->GetMapTiles();

		collision = false;
		int* tileBoxInt = 0;

		for(int j = 0; j < totalTiles; j++) //CHECK TILES
		{
			tileBoxInt = tileSet[j]->GetBoxInt();

			bool tempCollide = gContext->CheckCollision(this->GetCollisionBox(), tileBoxInt);

			if(!collision && tempCollide)
			{
				if(tileBoxInt[4] >= 5 && tileBoxInt[4] <= 24) //is wall
				{
					collision = true;
				}
				if(isPac) //entity is pacman
				{
					gContext->DestroyTile(j);
				}
			}
		}

		delete tileBoxInt;
		return collision;
	}
}
