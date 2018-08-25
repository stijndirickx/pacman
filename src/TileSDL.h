#ifndef TILESDL_H_
#define TILESDL_H_

#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>
#include "Tile.h"

using namespace std;

namespace PACMAN
{
	class TileSDL : public Tile
	{
		public:
			TileSDL(SDL_Renderer* sdlRendererTEMP, SDL_Texture* tileTexture);
			virtual ~TileSDL();

			void Visualize();

		protected:
			SDL_Renderer* sdlRenderer;
			SDL_Texture* texture;

			SDL_Rect brickSprite;
			SDL_Rect brickRect;
	};
}

#endif
