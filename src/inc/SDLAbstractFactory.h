#ifndef SDLABSTRACTFACTORY_H_
#define SDLABSTRACTFACTORY_H_
#include "SDLPlayer.h"
#include "AbstractFactory.h"

using namespace Logic;

namespace Graphics{
	class SDLAbstractFactory:public AbstractFactory{
	public:
		SDLAbstractFactory();
		~SDLAbstractFactory();
		Player* createPacman();
	};
}



#endif /* SDLFACTORY_H_ */
