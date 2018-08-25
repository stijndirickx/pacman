/*
 * FactorySDL.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "FactorySDL.h"

namespace PACMAN {
	FactorySDL::FactorySDL(){
		sdlInit = NULL;
	}

	FactorySDL::~FactorySDL(){
		delete sdlInit;
	}

	Ghost* FactorySDL::CreateGhost(int type){
		Ghost* ghost = new GhostSDL(type, sdlInit->GetRenderer(), sdlInit->GetSurface());
		ghost->SetFactory(this);
		ghost->SetGameContext(gContext);
		gContext->AddGhost(ghost);
		return ghost;
	}

	Pacman* FactorySDL::CreatePacman(){
		Pacman* pacman = new PacmanSDL(sdlInit->GetRenderer(), sdlInit->GetSurface());
		pacman->SetFactory(this);
		pacman->SetGameContext(gContext);

		return pacman;
	}

	Tile* FactorySDL::CreateTile(int x, int y, int type, int width, int height){
		Tile* tile = new TileSDL(sdlInit->GetRenderer(), sdlInit->GetTileTexture());
		tile->RenderTile(x, y, type, width, height);
		return tile;
	}

	void FactorySDL::CreateVis() {
		sdlInit = new InitSDL(tileMap->GetScreenWidth(), tileMap->GetScreenHeight());
	}

	GameContext* FactorySDL::CreateGameContext(){
		gContext = new GameContextSDL(sdlInit);
		gContext->SetMap(tileMap);
		tileMap->SetContext(gContext);
		return gContext;
	}

	EventHandler* FactorySDL::CreateEventHandler(){
		EventHandler* ev = new EventHandlerSDL();
		return ev;
	}
}
