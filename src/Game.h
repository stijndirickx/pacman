#ifndef GAME_H_
#define GAME_H_

#include <time.h> //TODO Find out why?

#include "AbstractFactory.h"
#include "Config.h"
#include "Enemy.h"
#include "EventHandler.h"
#include "SDLEventHandler.h"
#include "House.h"

using namespace std;

namespace logic
{
	class Game
	{
		public:
			AbstractFactory* mAbstractFactory;
			Game(AbstractFactory* pAbstractFactory);
			virtual ~Game();
			void Start();

		protected:
			Config* mConfig;
			int animationSpeed;
			int countToAttacking;
			int fps;
			int mspf;
			int numOfEnemies;
	};
}

#endif /* GAME_H_ */
