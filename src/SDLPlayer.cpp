#include "SDLPlayer.h"

namespace graphics_SDL
{
	SDLPlayer::SDLPlayer(SDL_Renderer* pRenderer, SDL_Surface* pSurface)
	{
		//Init renderer, surface and texture
		mRenderer = pRenderer;
		mSurface = pSurface;
		playerTexture = SDL_CreateTextureFromSurface(mRenderer, mSurface);

		//Making sprites rect
		for(int i = 0; i <= 14; i++)
		{
			playerSprites[i].x = 34+(15*i);
			playerSprites[i].y = 1;
			playerSprites[i].w = 15;
			playerSprites[i].h = 15;
		}
	}

	SDLPlayer::~SDLPlayer() {}

	void SDLPlayer::paint()
	{
		if(x == 0 && y == 0)
		{
			reset();
			//this->moveDir(4);
		}
		renderRect = {x, y, size, size};
		SDL_RenderCopy(mRenderer, playerTexture, &playerSprites[spriteSelector], &renderRect);
	}

	void SDLPlayer::moveDir(int direction)
	{
		//direction: 1 = up, 2 = down, 3 = left, 4 = right
		for(int i=0; i< 3 ; i++)
		{
			playerSprites[i].y = 1+(direction-1)*15;
		}

		switch(direction)
		{
			case 1:
				y -= mSpeed;
				break;
			case 2:
				y += mSpeed;
				break;
			case 3:
				x -= mSpeed;
				break;
			case 4:
				x += mSpeed;
				break;
		}
	}
}
