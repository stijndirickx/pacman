#ifndef ABSTRACTFACTORY_H_
#define ABSTRACTFACTORY_H_

#include "EventHandler.h"
#include "Player.h"
//#include "Window.h"

namespace logic{
	class Player;
	//class Window;
	class EventHandler;
	class AbstractFactory
	{
	public:
		AbstractFactory();
		virtual ~AbstractFactory();



		//virtual Window* createWindow()=0;
		virtual Player* createPlayer()=0;
		virtual EventHandler* createEventHandler()=0;
	};
}


#endif
