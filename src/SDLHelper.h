#ifndef SDLHELPER_H_
#define SDLHELPER_H_

#include <iostream>
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>
#include <sdl2/SDL_ttf.h>
#include <sdl2/SDL_mixer.h>

using namespace std;

namespace graphics_SDL
{
	class SDLHelper
	{
		public:
			SDLHelper(int windowWidth, int windowHeight, string spritesFile);
			virtual ~SDLHelper();

			SDL_Texture* getBrickTexture();
			SDL_Renderer* getRenderer();
			SDL_Renderer* getShownRenderer();
			SDL_Surface* getSurface();

		protected:
			SDL_Renderer* renderer;
			SDL_Renderer* shownRenderer;
			SDL_Surface* screenSurface;
			SDL_Surface* surface;
			SDL_Texture* texture;
			SDL_Window* window;
	};
}

#endif
