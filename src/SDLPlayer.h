#ifndef SDLPLAYER_H_
#define SDLPLAYER_H_

#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>

#include "Player.h"

namespace PACMAN
{
	class SDLPlayer : public Player
	{
		public:
			SDLPlayer(SDL_Renderer* pRenderer, SDL_Surface* pSurface);
			virtual ~SDLPlayer();

			void paint();
			void moveDir(int direction);

		protected:
			SDL_Renderer* mRenderer;
			SDL_Surface* mSurface;

			SDL_Rect playerSprites[15]; 			//0-2 alive, 3-15 dead
			SDL_Texture* playerTexture = NULL;
			SDL_Rect renderRect;
	};
}

#endif
