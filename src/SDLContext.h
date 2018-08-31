#ifndef SDLCONTEXT_H_
#define SDLCONTEXT_H_

#include "Context.h"
#include "SDLHelper.h"

using namespace logic;

namespace graphics_SDL
{
	class SDLContext : public Context
	{
		public:
			SDLContext(SDLHelper* pHelper);
			virtual ~SDLContext();

			void playSound(int soundId);
			void playMusic(int musicId);

			void clearScreen();
			void updateScreen();
			void updateText();

		protected:
			void renderText(TTF_Font* font, string msgTxt, int x, int y, int option);
			SDLHelper* mHelper;
			SDL_Renderer* renderer;
			SDL_Surface* surface;

			Mix_Chunk* music;
			Mix_Chunk* sound;

			TTF_Font* fontText;
			TTF_Font* fontTitle;
			SDL_Color msgColor;
	};
}

#endif
