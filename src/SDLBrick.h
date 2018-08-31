#ifndef SDLBRICK_H_
#define SDLBRICK_H_

#include <sdl2/SDL_image.h>

#include "Brick.h"

using namespace logic;

namespace graphics_SDL
{
	class SDLBrick : public Brick
	{
		public:
			SDLBrick(SDL_Renderer* pRenderer, SDL_Texture* pTexture);
			virtual ~SDLBrick();

			void paint();

		protected:
			SDL_Renderer* mRenderer;
			SDL_Texture* mTexture;

			SDL_Rect brickSprite;
			SDL_Rect brickRect;
	};
}

#endif
