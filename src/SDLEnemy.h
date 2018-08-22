#ifndef SDLENEMY_H_
#define SDLENEMY_H_

#include <iostream>
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>

#include "AbstractFactory.h"
#include "Enemy.h"

using namespace std;
using namespace logic;

namespace graphics_SDL
{
	class SDLEnemy : public Enemy
	{
		public:
			SDLEnemy(SDL_Renderer* pRenderer, SDL_Surface* pSurface, int pType);
			virtual ~SDLEnemy();

			void paint();

		protected:
			SDL_Renderer* mRenderer;
			SDL_Surface* mSurface;

			SDL_Rect enemySprite[3];
			SDL_Texture* enemyTexture = NULL;
			SDL_Rect renderRect;
	};
}

#endif
