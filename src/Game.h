#ifndef GAME_H_
#define GAME_H_

#include <time.h>

#include "Factory.h"
#include "Ghost.h"
#include "Map.h"
#include "Config.h"
#include "EventHandlerSDL.h"
#include "EventHandler.h"

using namespace std;

namespace PACMAN
{
	class Game
	{
		public:
			Factory* aFactory;
			Game(Factory*& abstractFactory);
			virtual ~Game();
			void Start();

		protected:
			Config* cFile;
			int fps;
			int mspf;
			int countToAttacking;
			int numOfGhosts;
			int animationSpeed;
	};
}

#endif
