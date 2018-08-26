#ifndef FACTORYSDL_H_
#define FACTORYSDL_H_

#include "Factory.h"
#include "GhostSDL.h"
#include "TileSDL.h"
#include "GameContextSDL.h"
#include "initSDL.h"
#include "EventHandlerSDL.h"
#include "SDLPlayer.h"

using namespace std;

namespace PACMAN
{
	class FactorySDL : public Factory
	{
		public:
			FactorySDL();
			virtual ~FactorySDL();

			Ghost* CreateGhost(int type);
			Player* createPlayer();
			Tile* CreateTile(int x, int y, int type, int width, int height);
			GameContext* CreateGameContext();
			EventHandler* CreateEventHandler();
			void CreateVis();

		protected:
			PACMAN::InitSDL* sdlInit;
	};
}

#endif
