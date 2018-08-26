#ifndef SDLPLAYER_H_
#define SDLPLAYER_H_

#include <iostream>
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>

#include "Factory.h"
#include "FactorySDL.h"
#include "Player.h"

using namespace std;

namespace PACMAN
{
	class FactorySDL;
	class SDLPlayer : public Player
	{
		public:
		SDLPlayer(SDL_Renderer* pRenderer, SDL_Surface* pSurface);
			virtual ~SDLPlayer();

			void paint();
			void move();
			void animate();
			void moveDir(int direction);
			void setDirection(int key);
			void gotCaptured(Ghost* ghosts[], int NUM_OF_GHOSTS);

		protected:
			SDL_Renderer* mRenderer;
			SDL_Surface* mSurface;

			SDL_Rect playerSprite[15]; 			//0-2 alive, 3-15 dead
			SDL_Texture* playerTexture = NULL;
			SDL_Rect renderRect;
	};
}

#endif
