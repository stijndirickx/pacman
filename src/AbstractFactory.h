#ifndef ABSTRACTFACTORY_H_
#define ABSTRACTFACTORY_H_

#include "Config.h"
#include "Player.h"

using namespace std;

namespace logic
{
	class Context;
	class Enemy;
	class EventHandler;
	class House;
	class Player;
	class AbstractFactory
	{
		public:
			AbstractFactory();
			virtual ~AbstractFactory();

			Config* createConfig();
			House* createHouse();

			virtual Brick* createBrick(int x, int y, int size, int type) = 0;
			virtual Context* createContext() = 0;
			virtual Enemy* createEnemy(int type) = 0;
			virtual EventHandler* createEventHandler() = 0;
			virtual Player* createPlayer() = 0;
			virtual void createSDLHelper() = 0;

		protected:
			House* house;
			Context* context;
			Config* config;
	};
}

#endif
