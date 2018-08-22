#ifndef SDLPLAYER_H_
#define SDLPLAYER_H_

#include <iostream>
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>

#include "AbstractFactory.h"
#include "Player.h"
#include "SDLAbstractFactory.h"

using namespace std;
using namespace logic;

namespace graphics_SDL
{
	class SDLAbstractFactory; //TODO check
	class SDLPlayer: public Player
	{
		public:
			SDLPlayer(SDL_Renderer* pRenderer, SDL_Surface* pSurface);
			~SDLPlayer();

			void moveInDir(int direction);
			void paint();

		protected:
			SDL_Renderer* mRenderer;
			SDL_Surface* mSurface;

			SDL_Rect playerSprite[15];
			SDL_Texture* playerTexture = NULL;
			SDL_Rect renderRect;
	};
}

#endif
