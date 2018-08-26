#ifndef FACTORYSDL_H_
#define FACTORYSDL_H_

#include "Factory.h"
#include "PacmanSDL.h"
#include "GhostSDL.h"
#include "TileSDL.h"
#include "GameContextSDL.h"
#include "initSDL.h"
#include "EventHandlerSDL.h"

using namespace std;

namespace PACMAN
{
	class FactorySDL : public Factory
	{
		public:
			FactorySDL();
			virtual ~FactorySDL();

			Ghost* CreateGhost(int type);
			Pacman* CreatePacman();
			Tile* CreateTile(int x, int y, int type, int width, int height);
			GameContext* CreateGameContext();
			EventHandler* CreateEventHandler();
			void CreateVis();

		protected:
			PACMAN::InitSDL* sdlInit;
	};
}

#endif
