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
		msgTexture = NULL;
		msgSurface = NULL;

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
		//left top
		printTxt = "Score: " + std::to_string(score);
		msgSurface = TTF_RenderText_Solid(fontText, printTxt.c_str(), msgColor);
		msgTexture = SDL_CreateTextureFromSurface(renderer, msgSurface);

		msgRect = {20, 0, msgSurface->w, msgSurface->h};
		SDL_RenderCopy(renderer, msgTexture, NULL, &msgRect);
		SDL_DestroyTexture(msgTexture);
		SDL_FreeSurface(msgSurface);

		//right top
		printTxt = "Lives: " + std::to_string(lives);
		msgSurface = TTF_RenderText_Solid(fontText, printTxt.c_str(), msgColor);
		msgTexture = SDL_CreateTextureFromSurface(renderer, msgSurface);

		msgRect = {windowWidth - msgSurface->w - 20, 0, msgSurface->w, msgSurface->h};
		SDL_RenderCopy(renderer, msgTexture, NULL, &msgRect);
		SDL_DestroyTexture(msgTexture);
		SDL_FreeSurface(msgSurface);

		if(!playing)
		{
			msgSurface = TTF_RenderText_Solid(fontTitle, displayString.c_str(), msgColor);
			msgTexture = SDL_CreateTextureFromSurface(renderer, msgSurface);
			msgRect = {windowWidth/2 - (msgSurface->w/2), windowHeight/2 - (msgSurface->h/2) - 40, msgSurface->w, msgSurface->h};
			SDL_RenderCopy(renderer, msgTexture, NULL, &msgRect);
			SDL_DestroyTexture(msgTexture);
			SDL_FreeSurface(msgSurface);

			msgSurface = TTF_RenderText_Solid(fontText, "Press 'space' to play", msgColor);
			msgTexture = SDL_CreateTextureFromSurface(renderer, msgSurface);
			msgRect = {windowWidth/2 - (msgSurface->w/2), windowHeight/2 - (msgSurface->h/2), msgSurface->w, msgSurface->h};
			SDL_RenderCopy(renderer, msgTexture, NULL, &msgRect);
			SDL_DestroyTexture(msgTexture);
			SDL_FreeSurface(msgSurface);

			if(lives <= 0)
			{
				printTxt = "High score: " + std::to_string(highScore);
				msgSurface = TTF_RenderText_Solid(fontText, printTxt.c_str(), msgColor);
				msgTexture = SDL_CreateTextureFromSurface(renderer, msgSurface);
				msgRect = {windowWidth/2 - (msgSurface->w/2), windowHeight/2 - (msgSurface->h/2) + 20, msgSurface->w, msgSurface->h};
				SDL_RenderCopy(renderer, msgTexture, NULL, &msgRect);
				SDL_DestroyTexture(msgTexture);
				SDL_FreeSurface(msgSurface);
			}
		}
	}

	void SDLContext::playSound(string sound)
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
