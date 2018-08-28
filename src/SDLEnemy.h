#ifndef SDLENEMY_H_
#define SDLENEMY_H_

#include <iostream>
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>

#include "AbstractFactory.h"
#include "Enemy.h"

using namespace std;

namespace PACMAN
{
	class SDLEnemy : public Enemy
	{
		public:
			SDLEnemy(int type, SDL_Renderer* pRenderer, SDL_Surface* pSurface);
			virtual ~SDLEnemy();

			void paint();

		protected:
			SDL_Renderer* mRenderer;
			SDL_Surface* mSurface;

			SDL_Rect enemySprites[3];
			SDL_Texture* enemyTexture = NULL;
			SDL_Rect renderRect;
	};
}

#endif
