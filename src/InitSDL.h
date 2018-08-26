#ifndef INITSDL_H_
#define INITSDL_H_

#include <iostream>
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>
#include <sdl2/SDL_ttf.h>
#include <sdl2/SDL_mixer.h>

using namespace std;

namespace PACMAN
{
	class InitSDL
	{
		public:
			InitSDL(int screenWidth, int screenHeight, string spritesFile);
			virtual ~InitSDL();
			void ClearScreen();
			void UpdateScreen();
			void QuitVis();
			SDL_Renderer* GetRenderer();
			SDL_Surface* GetSurface();
			SDL_Texture* GetTileTexture();
			SDL_Renderer* GetVisibleRenderer();

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
