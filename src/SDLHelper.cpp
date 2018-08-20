#include "SDLHelper.h"

namespace graphics_SDL
{
	SDLHelper::SDLHelper(int windowWidth, int windowHeight)
	{
		if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
		{
			printf("SDLHelper couldn't construct, error: %s\n", SDL_GetError());
		}
		else{

		}

	}

	SDLHelper::~SDLHelper()
	{
		SDL_DestroyRenderer( renderer );
		renderer = NULL;

		SDL_DestroyRenderer( shownRenderer );
		shownRenderer = NULL;

		SDL_DestroyWindow( window );
		window = NULL;

		//Quit SDL subsystems
		TTF_Quit();
		Mix_Quit();
		IMG_Quit();
		SDL_Quit();
	}


	SDL_Renderer* SDLHelper::GetRenderer(void)
	{
		return renderer;
	}

	SDL_Renderer* SDLHelper::GetShownRenderer(void)
	{
		return shownRenderer;
	}

	SDL_Surface* SDLHelper::GetSurface(void)
	{
		return surface;
	}

	SDL_Texture* SDLHelper::GetTexture(void)
	{
		return texture;
	}

}
