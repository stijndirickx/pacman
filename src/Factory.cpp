/*
 * Factory.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "Factory.h"

namespace PACMAN {
	Factory::Factory() {
		tileMap = NULL;
		cFile = NULL;
		gContext = NULL;
	}

	Factory::~Factory() {
		delete tileMap;
		delete gContext;
		delete cFile;
	}

	Config* Factory::CreateConfig() {
		cFile = new Config();
		return cFile;
	}

	Map* Factory::CreateMap() {
		tileMap = new Map(this, cFile->GetMapName(), cFile->GetTileSize());
		this->CreateVis();
		tileMap->CreateMap();
		return tileMap;
	}
}
