#include "SDLContext.h"

namespace PACMAN
{
	SDLContext::SDLContext(SDLHelper* pHelper)
	{
		mHelper = pHelper;
		sdlRendererTemp = mHelper->getRenderer();
		loadedSurface = mHelper->getSurface();

		font = TTF_OpenFont("Assets/Fonts/emulogic.ttf", 10);
		fontBig = TTF_OpenFont("Assets/Fonts/emulogic.ttf", 40);
		white = {255, 255, 255};
		messageTexture = NULL;
		textSurface = NULL;

		pacMusic = Mix_LoadWAV("Assets/Sounds/pacman_beginning.wav");
		pacSound = Mix_LoadWAV("Assets/Sounds/pacman_eatghost.wav");
	}

	SDLContext::~SDLContext() {}

	void SDLContext::updateText()
	{
		printTxt = "Score: " + std::to_string(score);
		textSurface = TTF_RenderText_Solid(font, printTxt.c_str(), white);
		messageTexture = SDL_CreateTextureFromSurface(sdlRendererTemp, textSurface);

		messageRect = {20, 0, textSurface->w, textSurface->h};
		SDL_RenderCopy(sdlRendererTemp, messageTexture, NULL, &messageRect);
		SDL_DestroyTexture(messageTexture); // MEMORY LEAKS OTHERWISE
		SDL_FreeSurface(textSurface);

		printTxt = "Lives: " + std::to_string(lives);
		textSurface = TTF_RenderText_Solid(font, printTxt.c_str(), white);
		messageTexture = SDL_CreateTextureFromSurface(sdlRendererTemp, textSurface);

		messageRect = {screenWidth - textSurface->w - 20, 0, textSurface->w, textSurface->h};
		SDL_RenderCopy(sdlRendererTemp, messageTexture, NULL, &messageRect);
		SDL_DestroyTexture(messageTexture);
		SDL_FreeSurface(textSurface);

		if(!playing)
		{
			textSurface = TTF_RenderText_Solid(fontBig, startText.c_str(), white);
			messageTexture = SDL_CreateTextureFromSurface(sdlRendererTemp, textSurface);
			messageRect = {screenWidth/2 - (textSurface->w/2), screenHeight/2 - (textSurface->h/2) - 40, textSurface->w, textSurface->h};
			SDL_RenderCopy(sdlRendererTemp, messageTexture, NULL, &messageRect);
			SDL_DestroyTexture(messageTexture);
			SDL_FreeSurface(textSurface);

			textSurface = TTF_RenderText_Solid(font, "Press 'enter' to play", white);
			messageTexture = SDL_CreateTextureFromSurface(sdlRendererTemp, textSurface);
			messageRect = {screenWidth/2 - (textSurface->w/2), screenHeight/2 - (textSurface->h/2), textSurface->w, textSurface->h};
			SDL_RenderCopy(sdlRendererTemp, messageTexture, NULL, &messageRect);
			SDL_DestroyTexture(messageTexture);
			SDL_FreeSurface(textSurface);

			if(lives <= 0)
			{
				printTxt = "High score: " + std::to_string(highScore);
				textSurface = TTF_RenderText_Solid(font, printTxt.c_str(), white);
				messageTexture = SDL_CreateTextureFromSurface(sdlRendererTemp, textSurface);
				messageRect = {screenWidth/2 - (textSurface->w/2), screenHeight/2 - (textSurface->h/2) + 20, textSurface->w, textSurface->h};
				SDL_RenderCopy(sdlRendererTemp, messageTexture, NULL, &messageRect);
				SDL_DestroyTexture(messageTexture);
				SDL_FreeSurface(textSurface);
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
		SDL_SetRenderDrawColor(sdlRendererTemp, 0x00, 0x00, 0x00, 0x00);
		SDL_RenderClear(sdlRendererTemp);
	}

	void SDLContext::updateScreen()
	{
		SDL_Renderer* sdlRenderer = mHelper->getVisibleRenderer();
		sdlRenderer = sdlRendererTemp;
		SDL_RenderPresent(sdlRenderer);
	}

	void SDLContext::quitVis()
	{
		Mix_FreeChunk(pacMusic);
		pacMusic = NULL;
		Mix_FreeChunk(pacSound);
		pacSound = NULL;
		mHelper->quitVis();
	}
}



