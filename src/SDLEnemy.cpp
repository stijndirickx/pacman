#include "SDLEnemy.h"

namespace graphics_SDL
{
	SDLEnemy::SDLEnemy(int pType, SDL_Renderer* pRenderer, SDL_Surface* pSurface)
	{
		mRenderer = pRenderer;
		mSurface = pSurface;
		enemyTexture = SDL_CreateTextureFromSurface(mRenderer, mSurface);

		type = pType;

		enemySprites[0].w = 15;
		enemySprites[0].h = 15;
	}

	SDLEnemy::~SDLEnemy(){}

	void SDLEnemy::paint()
	{
		if(x == 0 && y == 0)
		{
			x = (windowWidth/2)-(floor(numOfEnemies/2) * size)+(type*size);
			y = (windowHeight/2);
		}

		enemySprites[0].y = 16;
		if(attacking)
		{
			switch(type)
			{
				case 0:
					enemySprites[0].x = 79;
					break;
				case 1:
					enemySprites[0].x = 94;
					break;
				case 2:
					enemySprites[0].x = 109;
					break;
				case 3:
					enemySprites[0].x = 124;
					break;
			}
		}
		else
		{
			if(mAliveState)
			{
				if(!flashing)
				{
					enemySprites[0].x = 139;
				}
				else
				{
					enemySprites[0].x = 154;
				}
			}
			else
			{
				enemySprites[0].x = 169;
			}
		}
		renderRect = {x, y, size, size};
		SDL_RenderCopy(mRenderer, enemyTexture, &enemySprites[0], &renderRect);
	}
}
