#include "SDLHelper.h"

namespace PACMAN
{
	SDLHelper::SDLHelper(int screenWidth, int screenHeight, string spritesFile)
	{
		if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0 )
		{
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			if(!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ))
			{
				printf( "Warning: Linear texture filtering not enabled!" );
			}
			sdlWindow = SDL_CreateWindow( "C++Man", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN );
			if( sdlWindow == NULL )
			{
				printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			}
			else
			{
				sdlRendererTEMP = SDL_CreateRenderer( sdlWindow, -1, SDL_RENDERER_ACCELERATED );
				sdlRenderer = sdlRendererTEMP;
				int imgFlags = IMG_INIT_PNG;
				//Initialize SDL_image
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
				}
				else
				{
					sdlScreenSurface = SDL_GetWindowSurface( sdlWindow );
				}

				//Initialize SDL_ttf
				if(TTF_Init() < 0)
				{
					printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", IMG_GetError() );
				}

				//Initialize SDL_mixer
				if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) // standard frq = 44100, hardware channels = 2 (stereo), sample size = audio chunks
				{
					printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
				}

				//this->ClearScreen();

				loadedSurface = IMG_Load(spritesFile.c_str());
				SDL_SetColorKey(loadedSurface, SDL_TRUE, 0x000000 );

				tileTexture = SDL_CreateTextureFromSurface(sdlRendererTEMP, loadedSurface);
			}
		}

	}

	SDLHelper::~SDLHelper() {}

	SDL_Renderer* SDLHelper::getRenderer()
	{
		return sdlRendererTEMP;
	}

	SDL_Surface* SDLHelper::getSurface()
	{
		return loadedSurface;
	}

	SDL_Texture* SDLHelper::getBrickTexture()
	{
		return tileTexture;
	}

	SDL_Renderer* SDLHelper::getVisibleRenderer()
	{
		return sdlRenderer;
	}

	void SDLHelper::quitVis()
	{
		SDL_DestroyRenderer(sdlRendererTEMP);
		SDL_DestroyRenderer(sdlRenderer);
		SDL_DestroyWindow(sdlWindow);
		sdlRendererTEMP = NULL;
		sdlRenderer = NULL;
		sdlWindow = NULL;

		//Quit SDL subsystems
		TTF_Quit();
		Mix_Quit();
		IMG_Quit();
		SDL_Quit();
	}
}
