#ifndef GHOSTSDL_H_
#define GHOSTSDL_H_

#include <iostream>
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>

#include "Ghost.h"
#include "Factory.h"

using namespace std;

namespace PACMAN
{
	class GhostSDL : public Ghost
	{
		public:
			GhostSDL(int ghostType, SDL_Renderer* sdlRendererTEMP, SDL_Surface* loadedSurface);
			virtual ~GhostSDL();
			void Visualize();

		protected:
			SDL_Renderer* sdlRenderer;
			SDL_Surface* surface;

			SDL_Rect ghostSprite[3];
			SDL_Texture* ghostTexture = NULL;
			SDL_Rect renderQuadG;
	};
}

#endif
