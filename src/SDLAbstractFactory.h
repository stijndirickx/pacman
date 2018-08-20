#ifndef SDLABSTRACTFACTORY_H_
#define SDLABSTRACTFACTORY_H_
#include "SDLPlayer.h"
//#include "SDLWindow.h"
#include "AbstractFactory.h"

using namespace logic;

namespace graphics_SDL{
	class SDLAbstractFactory:public AbstractFactory{
	public:
		SDLAbstractFactory();
		~SDLAbstractFactory();
		Player* createPlayer();
		//Window* createWindow();
	};
}



#endif /* SDLFACTORY_H_ */
