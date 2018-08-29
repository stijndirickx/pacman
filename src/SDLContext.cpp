#include "SDLContext.h"

namespace graphics_SDL
{
	SDLContext::SDLContext(SDLHelper* pHelper)
	{
		mHelper = pHelper;
		renderer = mHelper->getRenderer();
		surface = mHelper->getSurface();

		fontText = TTF_OpenFont("Assets/Fonts/emulogic.ttf", 10);
		fontTitle = TTF_OpenFont("Assets/Fonts/emulogic.ttf", 40);
		msgColor = {255, 255, 255}; //White

		pacMusic = Mix_LoadWAV("Assets/Sounds/pacman_beginning.wav");
		pacSound = Mix_LoadWAV("Assets/Sounds/pacman_eatghost.wav");
	}

	SDLContext::~SDLContext()
	{
		Mix_FreeChunk(pacMusic);
		pacMusic = NULL;
		Mix_FreeChunk(pacSound);
		pacSound = NULL;
		delete mHelper;
	}

	void SDLContext::updateText()
	{
		renderText(fontText, "Score: " + std::to_string(score), 20, 0, 0);
		renderText(fontText, "Lives: " + std::to_string(lives), windowWidth - 20, 0, 1);

		if(!playing)
		{
			renderText(fontTitle, displayString, windowWidth/2 , windowHeight/2  - 40, 2);
			renderText(fontText, "Press 'space' to play", windowWidth/2, windowHeight/2, 2);

			if(lives <= 0)
			{
				renderText(fontText, "High score: " + std::to_string(highScore), windowWidth/2, windowHeight/2 + 20, 2);
			}
		}
	}

	void SDLContext::renderText(TTF_Font* font, string msgTxt, int x, int y, int option)
	{
		SDL_Rect msgRect;
		SDL_Surface* msgSurface = TTF_RenderText_Solid(font, msgTxt.c_str(), msgColor);
		SDL_Texture* msgTexture = SDL_CreateTextureFromSurface(renderer, msgSurface);

		switch(option)
		{
			case 0: //left align
				msgRect = {x,y, msgSurface->w, msgSurface->h};
				break;
			case 1: //right align
				msgRect = {x - msgSurface->w,y, msgSurface->w, msgSurface->h};
				break;
			case 2: //centered
				msgRect = {x - (msgSurface->w/2), y - (msgSurface->h/2), msgSurface->w, msgSurface->h};
				break;
		}

		SDL_RenderCopy(renderer, msgTexture, NULL, &msgRect);
		SDL_DestroyTexture(msgTexture);
		SDL_FreeSurface(msgSurface);
	}

	void SDLContext::playSound(string sound) //TODO clean this
	{
		if(sound == "pacman")
		{
			if(Mix_Playing(2) != 0)
			{
				Mix_HaltChannel(2);
				Mix_FreeChunk(pacMusic);
				pacMusic = Mix_LoadWAV("Assets/Sounds/pacman_chomp.wav");
			}

			if( Mix_Playing(1) == 0)
			{
				Mix_PlayChannel(1, pacMusic, 0);
			}
		}
		else if(sound == "beginning")
		{
			if(Mix_Playing(1) != 0)
			{
				Mix_HaltChannel(1);
				Mix_FreeChunk(pacMusic);
				pacMusic = Mix_LoadWAV("Assets/Sounds/pacman_beginning.wav");
			}

			if(Mix_Playing(2) == 0)
			{
				Mix_PlayChannel(2, pacMusic, 0);
			}
		}
		else if(sound == "dead")
		{
			Mix_FreeChunk(pacSound);
			pacSound = Mix_LoadWAV("Assets/Sounds/pacman_death.wav");
			Mix_PlayChannel(-1, pacSound, 0);
		}
		else if(sound == "kill")
		{
			Mix_FreeChunk(pacSound);
			pacSound = Mix_LoadWAV("Assets/Sounds/pacman_eatghost.wav");
			Mix_PlayChannel(3, pacSound, 0);
		}
		else if(sound == "eat")
		{
			Mix_FreeChunk(pacSound);
			pacSound = Mix_LoadWAV("Assets/Sounds/pacman_eatfruit.wav");
			Mix_PlayChannel(3, pacSound, 0);
		}

	}

	void SDLContext::clearScreen()
	{
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
		SDL_RenderClear(renderer);
	}

	void SDLContext::updateScreen()
	{
		SDL_Renderer* shownRenderer = mHelper->getShownRenderer();
		shownRenderer = renderer;
		SDL_RenderPresent(shownRenderer);
	}
}
