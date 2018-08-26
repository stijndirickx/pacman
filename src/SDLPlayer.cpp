#include "SDLPlayer.h"

namespace PACMAN
{
	SDLPlayer::SDLPlayer(SDL_Renderer* pRenderer, SDL_Surface* pSurface)
	{
		mRenderer = pRenderer;
		mSurface = pSurface;
		playerTexture = SDL_CreateTextureFromSurface(mRenderer, mSurface);


		for(int i = 0; i <= 14; i++)
		{
			playerSprite[i].x = 37+(15*i);
			playerSprite[i].y = 0;
			playerSprite[i].w = 15;
			playerSprite[i].h = 15;
		}
	}

	SDLPlayer::~SDLPlayer() {}

	void SDLPlayer::paint()
	{
		if(mPosX == 0 && mPosY == 0)
		{
			mPosX = (screenWidth/2);
			mPosY = floor(3*screenHeight/4); //TODO better position here
		}
		renderRect = {mPosX, mPosY, mWidth, mHeight};
		SDL_RenderCopy(mRenderer, playerTexture, &playerSprite[frame], &renderRect);
	}

	void SDLPlayer::moveDir(int direction)
	{
		int velocity = mWidth / pacmanVel;
		switch(direction)
		{
			case 1: //UP
				mPosY -= velocity;
				playerSprite[0].y = 30;
				playerSprite[1].y = 30;
				playerSprite[2].y = 30;
				break;
			case 2: //DOWN
				mPosY += velocity;
				playerSprite[0].y = 45;
				playerSprite[1].y = 45;
				playerSprite[2].y = 45;
				break;
			case 3: //LEFT
				mPosX -= velocity;
				playerSprite[0].y = 15;
				playerSprite[1].y = 15;
				playerSprite[2].y = 15;
				break;
			case 4: //RIGHT
				mPosX += velocity;
				playerSprite[0].y = 0;
				playerSprite[1].y = 0;
				playerSprite[2].y = 0;
				break;
		}
	}
}

