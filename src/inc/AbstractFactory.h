#ifndef ABSTRACTFACTORY_H_
#define ABSTRACTFACTORY_H_

#include "Player.h"
#include "EventHandler.h"
//#include <Window.h>

namespace Logic{
	class AbstractFactory{
	public:
		AbstractFactory();
		virtual ~AbstractFactory();

//		virtual Window* createWindow()=0;
		virtual Player* createPacman()=0;
		//virtual EventHandler* createEventHandler()=0;
	};
}


#endif
