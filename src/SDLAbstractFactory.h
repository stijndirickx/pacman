#ifndef SDLABSTRACTFACTORY_H_
#define SDLABSTRACTFACTORY_H_

#include "AbstractFactory.h"
#include "SDLBrick.h"
#include "SDLContext.h"
#include "SDLEnemy.h"
#include "SDLEventHandler.h"
#include "SDLHelper.h"
#include "SDLPlayer.h"

using namespace std;

namespace PACMAN
{
	class SDLAbstractFactory : public AbstractFactory
	{
		public:
			SDLAbstractFactory();
			virtual ~SDLAbstractFactory();

			Enemy* createEnemy(int type);
			Player* createPlayer();
			Brick* createBrick(int x, int y, int type, int width, int height);
			Context* createContext();
			EventHandler* createEventHandler();
			void createVis();

		protected:
			PACMAN::SDLHelper* helper;
	};
}

#endif
