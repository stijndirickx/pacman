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
		if(x == 0 && y == 0) //default setting when factory was unknown.
		{
			x = (screenWidth/2)-(floor(numOfEnemies/2) * size)+(type*size);
			y = (screenHeight/2);
		}

		enemySprites[0].y = 15;

		if(attacking)
		{
			if(type == 0)
			{
				enemySprites[0].x = 82;
			}
			else if (type == 1)
			{
				enemySprites[0].x = 97;
			}
			else if (type == 2)
			{
				enemySprites[0].x = 112;
			}
			else
			{
				enemySprites[0].x = 127;
			}
		}
		else
		{
			if(living)
			{
				if(!flashing)
				{
					enemySprites[0].x = 142;
				}
				else
				{
					enemySprites[0].x = 157;
				}
			}
			else
			{
				enemySprites[0].x = 172;
			}
		}
		renderRect = {x, y, size, size};
		SDL_RenderCopy(mRenderer, enemyTexture, &enemySprites[0], &renderRect);
	}
}
