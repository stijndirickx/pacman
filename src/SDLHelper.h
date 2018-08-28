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
			SDLHelper(int screenWidth, int screenHeight, string spritesFile);
			virtual ~SDLHelper();
			void clearScreen();
			void updateScreen();
			void quitVis();
			SDL_Renderer* getRenderer();
			SDL_Surface* getSurface();
			SDL_Texture* getBrickTexture();
			SDL_Renderer* getVisibleRenderer();

		protected:
			SDL_Renderer* sdlRendererTEMP;
			SDL_Renderer* sdlRenderer;
			SDL_Surface* loadedSurface;
			SDL_Window* sdlWindow;
			SDL_Surface* sdlScreenSurface;

			SDL_Texture* tileTexture;
	};
}

#endif
