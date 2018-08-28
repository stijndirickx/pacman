#ifndef SDLCONTEXT_H_
#define SDLCONTEXT_H_

#include <iostream>
#include <sdl2/SDL_ttf.h>
#include <sdl2/SDL_mixer.h>

#include "Context.h"
#include "SDLHelper.h"

using namespace std;
using namespace logic;

namespace graphics_SDL
{
	class SDLContext : public Context
	{
		public:
			SDLContext(SDLHelper* pHelper);
			virtual ~SDLContext();

			void updateText();
			void playSound(string sound);
			void clearScreen();
			void updateScreen();
			void quitVis();

		protected:
			SDLHelper* mHelper;

			SDL_Renderer* sdlRendererTemp;
			SDL_Surface* loadedSurface;

			TTF_Font* font;
			TTF_Font* fontBig;
			SDL_Color white;
			SDL_Surface* textSurface;
			SDL_Texture* messageTexture;
			SDL_Rect messageRect;
			std::string printTxt = "";

			Mix_Chunk *pacMusic;
			Mix_Chunk *pacSound;
	};
}

#endif
