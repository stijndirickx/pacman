#ifndef GAME_H_
#define GAME_H_

#include <time.h>

#include "AbstractFactory.h"
#include "Config.h"
#include "Enemy.h"
#include "EventHandler.h"
#include "House.h"
#include "SDLEventHandler.h"

using namespace std;

namespace PACMAN
{
	class Game
	{
		public:
			AbstractFactory* aFactory;
			Game(AbstractFactory*& abstractFactory);
			virtual ~Game();

			void start();

		protected:
			Config* cFile;
			int fps;
			int mspf;
			int countToAttacking;
			int numOfEnemies;
			int animationSpeed;
	};
}

#endif
