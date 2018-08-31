#ifndef SDLABSTRACTFACTORY_H_
#define SDLABSTRACTFACTORY_H_

#include "AbstractFactory.h"
#include "SDLBrick.h"
#include "SDLContext.h"
#include "SDLEnemy.h"
#include "SDLEventHandler.h"
#include "SDLHelper.h"
#include "SDLPlayer.h"

using namespace logic;

namespace graphics_SDL
{
	class SDLAbstractFactory : public AbstractFactory
	{
		public:
			SDLAbstractFactory();
			virtual ~SDLAbstractFactory();

			Brick* createBrick(int x, int y, int size, int type);
			Context* createContext();
			Enemy* createEnemy(int type);
			EventHandler* createEventHandler();
			Player* createPlayer();
			void createSDLHelper();

		protected:
			SDLHelper* helper;
	};
}

#endif
