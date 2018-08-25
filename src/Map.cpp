/*
 * Map.cpp
 *
 *  Created on: Mar 14, 2018
 *      Author: ruben
 */

#include "Map.h"

namespace PACMAN {
	Map::Map(Factory* abstractFactory, string mapName, int size) {
		aFactory = abstractFactory;
		gContext = NULL;
		tileSize = size;
		numOfPellets = 0;
		numOfPelletsLeft = 0;
		map.open(mapName, std::ios::binary);
		if( map.fail() )
		{
			printf( "Unable to load map file!\n" );
		}

		char line[256];
		map.getline(line, 256); //get position at first line
		int lineLength = map.tellg()/2;

		map.seekg(0, ios::end); //to the end of the file
		totalTiles = map.tellg()/2; //get the number of tiles

		screenWidth = lineLength * tileSize;
		screenHeight = (totalTiles/lineLength) * tileSize;
	}

	Map::~Map() {
		delete [] destroyedTiles;
		for(int tile = 0; tile < totalTiles; tile++){
			delete tileSet[tile];
		}
		delete [] tileSet;
	}

	void Map::SetContext(GameContext* GameContext){
		gContext = GameContext;
		gContext->SetScreenWidth(screenWidth);
		gContext->SetScreenHeight(screenHeight);
		gContext->SetTotalTiles(totalTiles);
	}

	void Map::CreateMap() {
		map.seekg(0, ios::beg);
		int x = 0, y = 0;

		for(int tile = 0; tile < totalTiles; tile++){
			int tileType = 0;
			map >> tileType;
			tileSet[tile] = aFactory->CreateTile(x, y, tileType, tileSize, tileSize);
			if(tileType == 0){
				numOfPellets++;
			}
			x += tileSize;
			if(x >= screenWidth)
			{
				x = 0;
				y += tileSize;
			}
		}
		numOfPelletsLeft = (numOfPellets-15);
		map.close();
	}

	void Map::Load() {
		for(int tile = 0; tile < totalTiles; tile++){
			destroyedTiles[tile] = 0;
		}
		numOfPelletsLeft = numOfPellets;
	}

	void Map::Draw() {
		for(int tile = 0; tile < totalTiles; tile++){
			if(destroyedTiles[tile] != 1){
				tileSet[tile]->Visualize();
			}
		}
	}

	Tile** Map::GetTiles(){
		return tileSet;
	}

	void Map::DestroyTile(int tile){
		if(destroyedTiles[tile] != 1){
			int* tileBoxInt = tileSet[tile]->GetBoxInt();
			if(tileBoxInt[4] == 9){ // PELLET TODO get variable int of pellet
				gContext->PlaySound("eat");
				std::vector<Ghost*>ghosts = gContext->GetGhosts();
				for(size_t i = 0; i <= (ghosts.size()-1); i++){
					ghosts[i]->SetAttackingState(false);
				}
				destroyedTiles[tile] = 1;
			} else if(tileBoxInt[4] == 8){ // CHERRY
				gContext->PlaySound("eat");
				gContext->AddToScore(10);
				destroyedTiles[tile] = 1;
			} else if(tileBoxInt[4] == 0){ //PAC-DOT
				gContext->AddToScore(1);
				destroyedTiles[tile] = 1;
				numOfPelletsLeft--;
			}
			delete tileBoxInt;
		}
	}

	int Map::GetScreenWidth(){
		return screenWidth;
	}

	int Map::GetScreenHeight(){
		return screenHeight;
	}

	int Map::GetNumOfPellets(){
		return numOfPelletsLeft;
	}
}
