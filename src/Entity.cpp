/*
 * Entity.cpp
 *
 *  Created on: Apr 2, 2018
 *      Author: ruben
 */

#include "Factory.h"

namespace PACMAN {
	Entity::Entity() {
		collision = false;
		aFactory = NULL;
		gContext = NULL;


		mPosX = 0;
		mPosY = 0;
		mWidth = 0;
		mHeight = 0;
	}

	Entity::~Entity() {
		delete entityBox;
	}

	void Entity::SetGameContext(GameContext* gameContext){
		gContext = gameContext;
		totalTiles = gContext->GetTotalTiles();
		screenWidth = gContext->GetScreenWidth();
		screenHeight = gContext->GetScreenHeight();
		mWidth = gContext->GetTileSize();
		mHeight = gContext->GetTileSize();
		numOfGhosts = gContext->GetNumOfGhosts();
	}

	void Entity::SetFactory(Factory* fac){
		aFactory = fac;
	}

	int* Entity::GetCollisionBox(){
		entityBox[0] = mPosX;
		entityBox[1] = mPosY;
		entityBox[2] = mWidth;
		entityBox[3] = mHeight;

		return entityBox;
	}


	bool Entity::CheckCollisions(){
		Tile** tileSet = gContext->GetMapTiles();

		collision = false;
		int* tileBoxInt = 0;

		for(int j = 0; j < totalTiles; j++){ //CHECK TILES
			tileBoxInt = tileSet[j]->GetBoxInt();

			bool tempCollide = gContext->CheckCollision(this->GetCollisionBox(), tileBoxInt);

			if(!collision && tempCollide){
				if(tileBoxInt[4] > 0 && tileBoxInt[4] <= 6){ //is wall
					collision = true;
				}
				if(isPac){ //entity is pacman
					gContext->DestroyTile(j);
				}
			}
		}

		delete tileBoxInt;
		return collision;
	}
}
