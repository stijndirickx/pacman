#ifndef SDLABSTRACTFACTORY_H_
#define SDLABSTRACTFACTORY_H_

#include "AbstractFactory.h"
#include "SDLBrick.h"
#include "SDLContext.h"
#include "SDLEnemy.h"
#include "SDLEventHandler.h"
#include "SDLPlayer.h"
#include "SDLHelper.h"

using namespace std;
using namespace logic;

namespace graphics_SDL
{
	class SDLAbstractFactory:public AbstractFactory
	{
		public:
			SDLAbstractFactory();
			~SDLAbstractFactory();

			Brick* createBrick(int x, int y, int width, int height, int type);
			Context* createContext();
			Enemy* createEnemy(int type);
			EventHandler* createEventHandler();
			Player* createPlayer();

			void createVisualization(); //TODO check if this can be ctor

		protected:
			SDLHelper* mSDLHelper;
	};
}

#endif
