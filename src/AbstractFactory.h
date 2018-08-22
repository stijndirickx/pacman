#ifndef ABSTRACTFACTORY_H_
#define ABSTRACTFACTORY_H_

#include <iostream>
#include <fstream>
#include <vector>

#include "Brick.h"
#include "Config.h"
#include "Context.h"
#include "Enemy.h"
#include "EventHandler.h"
//#include "House.h"
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

			Config* getConfig();
			House* getHouse();

			virtual Brick* createBrick(int x, int y, int width, int heigth, int type)=0;
			virtual Context* createContext() = 0;
			virtual Enemy* createEnemy(int type) = 0;
			virtual EventHandler* createEventHandler() = 0;
			virtual Player* createPlayer() = 0;
			virtual void createVisualization() = 0;

		protected:
			Config* mConfig;
			Context* mContext;
			House* mHouse;
	};
}

#endif
