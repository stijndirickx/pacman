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
using namespace logic;

namespace graphics_SDL
{
	class SDLAbstractFactory : public AbstractFactory
	{
		public:
			SDLAbstractFactory();
			virtual ~SDLAbstractFactory();

			Enemy* createEnemy(int type);
			Player* createPlayer();
			Brick* createBrick(int x, int y, int size, int type);
			Context* createContext();
			EventHandler* createEventHandler();
			void createSDLHelper();

		protected:
			SDLHelper* helper;
	};
}

#endif
