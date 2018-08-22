#include "SDLPlayer.h"

namespace graphics_SDL
{
	SDLPlayer::SDLPlayer(SDL_Renderer* pRenderer, SDL_Surface* pSurface)
	{
		mRenderer = pRenderer;
		mSurface = pSurface;
		playerTexture = SDL_CreateTextureFromSurface(mRenderer, mSurface);

		//TODO SPRITES
		for(int i = 0; i < 15; i++)
		{
			playerSprite[i] = {455+(16*i), 0, 15, 15};
		}
	}

	SDLPlayer::~SDLPlayer()
	{

	}

	void SDLPlayer::paint()
	{
		if(Entity::x == 0 && Entity::y == 0) //TODO check this
		{
			Entity::x = (Entity::screenWidth/2);
			Entity::y = floor(3*Entity::screenHeight/4);
		}

		renderRect = {Entity::x, Entity::y, Entity::w, Entity::h};
		SDL_RenderCopy(mRenderer, playerTexture, &playerSprite[frame], &renderRect);
	}

	void SDLPlayer::moveInDir(int direction) //TODO change code underneath
	{
		int velocity = Entity::w / pacmanVel;
		switch(direction)
		{
			case 1: //UP
				Entity::y -= velocity;
				playerSprite[0].x = 455;
				playerSprite[1].x = 471;
				playerSprite[0].y = 32;
				playerSprite[1].y = 32;
				break;

			case 2: //DOWN
				Entity::y += velocity;
				playerSprite[0].x = 455;
				playerSprite[1].x = 471;
				playerSprite[0].y = 48;
				playerSprite[1].y = 48;
				break;

			case 3: //LEFT
				Entity::x -= velocity;
				playerSprite[0].x = 455;
				playerSprite[1].x = 471;
				playerSprite[0].y = 16;
				playerSprite[1].y = 16;
				break;

			case 4: //RIGHT
				Entity::x += velocity;
				playerSprite[0].x = 455;
				playerSprite[1].x = 471;
				playerSprite[0].y = 0;
				playerSprite[1].y = 0;
				break;
		}
	}
}
