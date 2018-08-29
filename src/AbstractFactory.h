#ifndef ABSTRACTFACTORY_H_
#define ABSTRACTFACTORY_H_

//#include <iostream>
//#include <fstream>
//#include <vector>

//#include "Brick.h"
#include "Config.h"
//#include "Context.h"
#include "Enemy.h"
//#include "EventHandler.h"
#include "Player.h"

using namespace std;

namespace logic
{
	class House;
	class Player;
	class Enemy;
	class Context;
	class EventHandler;
	class AbstractFactory
	{
		public:
			AbstractFactory();
			virtual ~AbstractFactory();

			Config* createConfig();
			House* createHouse();

			virtual Enemy* createEnemy(int type) = 0;
			virtual Player* createPlayer() = 0;
			virtual Brick* createBrick(int x, int y, int size, int type) = 0;
			virtual void createSDLHelper() = 0;
			virtual Context* createContext() = 0;
			virtual EventHandler* createEventHandler() = 0;

		protected:
			House* house;
			Context* context;
			Config* config;
	};
}

#endif
