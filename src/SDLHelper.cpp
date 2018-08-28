#include "SDLHelper.h"

namespace graphics_SDL
{
	SDLHelper::SDLHelper(int windowWidth, int windowHeight, string spritesFile)
	{
		if( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
		{
			printf("[SDLHelper]: SDL problem initializing - %s\n", SDL_GetError());
		}
		else
		{
			if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
			{
				printf("[SDLHelper]: Couldn't enable linear texture filtering");
			}
			window = SDL_CreateWindow("C++Man", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
			if(window == NULL)
			{
				printf("[SDLHelper]: Wasn't able to create window - %s\n", SDL_GetError());
			}
			else
			{
				renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
				shownRenderer = renderer;
				int imgFlags = IMG_INIT_PNG;

				//Initialize SDL_image
				if(!(IMG_Init(imgFlags)&imgFlags))
				{
					printf("[SDLHelper]: Wasn't able to init SDL_image - %s\n", IMG_GetError());
				}
				else
				{
					screenSurface = SDL_GetWindowSurface(window);
				}

				//Initialize SDL_ttf
				if(TTF_Init() < 0)
				{
					printf("[SDLHelper]: Wasn't able to init SDL_ttf - %s\n", TTF_GetError());
				}

				//Initialize SDL_mixer
				if( Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) // 44,1kHz, 1024 bit chunks
				{
					printf("[SDLHelper]: Wasn't able to init SDL_mixer - %s\n", Mix_GetError());
				}

				surface = IMG_Load(spritesFile.c_str());
				SDL_SetColorKey(surface, SDL_TRUE, 0x000000 );
				texture = SDL_CreateTextureFromSurface(renderer, surface);
			}
		}

	}

	SDLHelper::~SDLHelper()
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyRenderer(shownRenderer);
		SDL_DestroyWindow(window);
		renderer = NULL;
		shownRenderer = NULL;
		window = NULL;

		//Quit SDL subsystems
		TTF_Quit();
		Mix_Quit();
		IMG_Quit();
		SDL_Quit();
	}

	SDL_Renderer* SDLHelper::getRenderer()
	{
		return renderer;
	}

	SDL_Surface* SDLHelper::getSurface()
	{
		return surface;
	}

	SDL_Texture* SDLHelper::getBrickTexture()
	{
		return texture;
	}

	SDL_Renderer* SDLHelper::getShownRenderer()
	{
		return shownRenderer;
	}
}
