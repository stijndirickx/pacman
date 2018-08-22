#ifndef SDLHELPER_H_
#define SDLHELPER_H_

#include <iostream> //TODO NEW

#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>
#include <sdl2/SDL_mixer.h>
#include <sdl2/SDL_ttf.h>

using namespace std; //TODO NEW

namespace graphics_SDL
{
	class SDLHelper
	{
		public:
			SDLHelper(int windowWidth, int windowHeight);
			virtual ~SDLHelper();

			SDL_Renderer* getRenderer();
			SDL_Renderer* getShownRenderer();
			SDL_Surface* getSurface();
			SDL_Texture* getTexture();

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
