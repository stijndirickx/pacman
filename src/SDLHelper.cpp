#include "SDLHelper.h"

namespace graphics_SDL
{
	SDLHelper::SDLHelper(int windowWidth, int windowHeight)
	{
		if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
		{
			printf("SDLHelper couldn't construct, error: %s\n", SDL_GetError());
		}
		else
		{
			if( !SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
			{
				printf("Warning: Linear texture filtering not enabled!");
			}
			window = SDL_CreateWindow("EclipseMan", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
			if(window == NULL)
			{
				printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			}
			else
			{
				renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
				shownRenderer = renderer;
				int imgFlags = IMG_INIT_PNG;

				//Initialize SDL_image
				if(!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				}
				else
				{
					screenSurface = SDL_GetWindowSurface(window);
				}

				//Initialize SDL_ttf
				if(TTF_Init() < 0)
				{
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
				}

				//Initialize SDL_mixer
				if(Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0)
				{
					printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
				}

				surface = IMG_Load("Assets/sprites.png");
				SDL_SetColorKey(surface, SDL_TRUE, 0x000000);
				texture = SDL_CreateTextureFromSurface(renderer, surface);
			}
		}
	}

	SDLHelper::~SDLHelper()
	{
		SDL_DestroyRenderer(renderer);
		renderer = NULL;

		SDL_DestroyRenderer(shownRenderer);
		shownRenderer = NULL;

		SDL_DestroyWindow(window);
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

	SDL_Renderer* SDLHelper::getShownRenderer()
	{
		return shownRenderer;
	}

	SDL_Surface* SDLHelper::getSurface()
	{
		return surface;
	}

	SDL_Texture* SDLHelper::getTexture()
	{
		return texture;
	}

}
