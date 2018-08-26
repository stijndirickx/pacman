#ifndef FACTORY_H_
#define FACTORY_H_

#include "Ghost.h"
#include "Tile.h"
#include "Config.h"
#include "GameContext.h"
#include "EventHandler.h"
#include <iostream>
#include <fstream>
#include <vector>

#include "Player.h"
using namespace std;

namespace PACMAN
{
	class Map;
	class Player;
	class Ghost;
	class GameContext;
	class EventHandler;
	class Factory
	{
		public:
			Factory();
			virtual ~Factory();

			Config* CreateConfig();
			Map* CreateMap();

			virtual Ghost* CreateGhost(int type) = 0;
			virtual Player* createPlayer() = 0;
			virtual Tile* CreateTile(int x, int y, int type, int width, int height) = 0;
			virtual void CreateVis() = 0;
			virtual GameContext* CreateGameContext() = 0;
			virtual EventHandler* CreateEventHandler() = 0;

		protected:
			Map* tileMap;
			GameContext* gContext;
			Config* cFile;
	};
}

#endif
