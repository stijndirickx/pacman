#include "SDLContext.h"

namespace graphics_SDL
{
	SDLContext::SDLContext(SDLHelper* pSDLHelper)
	{
		mSDLHelper = pSDLHelper;
		renderer = mSDLHelper->getRenderer();
		surface = mSDLHelper->getSurface();

		fontText = TTF_OpenFont("Fonts/emulogic.ttf", 10);
		fontTitle = TTF_OpenFont("Fonts/emulogic.ttf", 40);
		msgColor = {255, 255, 255}; //white
		msgTexture = NULL;
		msgSurface = NULL;

		startMix = Mix_LoadWAV("Assets/Sounds/pacman_beginning.wav");
		eatMix = Mix_LoadWAV("Assets/Sounds/pacman_eatghost.wav");
	}

	SDLContext::~SDLContext()
	{
		// TODO Auto-generated destructor stub
	}

	void SDLContext::updateText()
	{
		msgString = "Score: " + std::to_string(score);
		msgSurface = TTF_RenderText_Solid(fontText, msgString.c_str(), msgColor);
		msgTexture = SDL_CreateTextureFromSurface(renderer, msgSurface);
		msgRect = {20, 0, msgSurface->w, msgSurface->h};
		SDL_RenderCopy(renderer, msgTexture, NULL, &msgRect);
		SDL_DestroyTexture(msgTexture); //TODO MEMORY LEAKS OTHERWISE
		SDL_FreeSurface(msgSurface);

		msgString = "Lives: " + std::to_string(lives);
		surface = TTF_RenderText_Solid(fontText, msgString.c_str(), msgColor);
		msgTexture = SDL_CreateTextureFromSurface(renderer, msgSurface);
		msgRect = {screenWidth - msgSurface->w - 20, 0, msgSurface->w, msgSurface->h};
		SDL_RenderCopy(renderer, msgTexture, NULL, &msgRect);
		SDL_DestroyTexture(msgTexture);
		SDL_FreeSurface(msgSurface);

		if(!playing){
			msgSurface = TTF_RenderText_Solid(fontTitle, startText.c_str(), msgColor);
			msgTexture = SDL_CreateTextureFromSurface(renderer, msgSurface);
			msgRect = {screenWidth/2 - (msgSurface->w/2), screenHeight/2 - (msgSurface->h/2) - 40, msgSurface->w, msgSurface->h};
			SDL_RenderCopy(renderer, msgTexture, NULL, &msgRect);
			SDL_DestroyTexture(msgTexture);
			SDL_FreeSurface(msgSurface);

			msgSurface = TTF_RenderText_Solid(fontText, "Press 'enter' to play", msgColor);
			msgTexture = SDL_CreateTextureFromSurface(renderer, msgSurface);
			msgRect = {screenWidth/2 - (msgSurface->w/2), screenHeight/2 - (msgSurface->h/2), msgSurface->w, msgSurface->h};
			SDL_RenderCopy(renderer, msgTexture, NULL, &msgRect);
			SDL_DestroyTexture(msgTexture);
			SDL_FreeSurface(msgSurface);

			if(lives <= 0){
				msgString = "High score: " + std::to_string(hiScore);
				msgSurface = TTF_RenderText_Solid( fontText, msgString.c_str(), msgColor);
				msgTexture = SDL_CreateTextureFromSurface( renderer, msgSurface );
				msgRect = {screenWidth/2 - (msgSurface->w/2), screenHeight/2 - (msgSurface->h/2) + 20, msgSurface->w, msgSurface->h};
				SDL_RenderCopy(renderer, msgTexture, NULL, &msgRect);
				SDL_DestroyTexture(msgTexture);
				SDL_FreeSurface(msgSurface);
			}
		}
	}

	void SDLContext::playSound(string sound)
	{
		//TODO replace by switch
		if(sound == "chomp")
		{
			if(Mix_Playing(2) != 0)
			{
				Mix_HaltChannel(2);
				Mix_FreeChunk(startMix);
				startMix = Mix_LoadWAV("Assets/Sounds/pacman_chomp.wav");
			}
			if(Mix_Playing(1) == 0)
			{
				Mix_PlayChannel(1, startMix, 0);
			}
		}
		else if(sound == "beginning")
		{
			if(Mix_Playing(1) != 0)
			{
				Mix_HaltChannel(1);
				Mix_FreeChunk(startMix);
				startMix = Mix_LoadWAV("Assets/Sounds/pacman_beginning.wav");
			}
			if(Mix_Playing(2) == 0)
			{
				Mix_PlayChannel(2, startMix, 0);
			}
		}
		else if(sound == "death")
		{
			Mix_FreeChunk(eatMix);
			eatMix = Mix_LoadWAV("Assets/Sounds/pacman_death.wav");
			Mix_PlayChannel(-1, eatMix, 0);
		}
		else if(sound == "eatghost")
		{
			Mix_FreeChunk(eatMix);
			eatMix = Mix_LoadWAV("Assets/Sounds/pacman_eatghost.wav");
			Mix_PlayChannel(3, eatMix, 0);
		}
		else if(sound == "eatfruit")
		{
			Mix_FreeChunk(eatMix);
			eatMix = Mix_LoadWAV("Assets/Sounds/pacman_eatfruit.wav");
			Mix_PlayChannel(3, eatMix, 0);
		}

	}

	void SDLContext::clearScreen()
	{
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
		SDL_RenderClear(renderer);
	}

	void SDLContext::updateScreen()
	{
		SDL_Renderer* shownRenderer = mSDLHelper->getShownRenderer();
		shownRenderer = renderer;
		SDL_RenderPresent(shownRenderer);
	}

	void SDLContext::quitVisualization()
	{
		Mix_FreeChunk(startMix);
		startMix = NULL;
		Mix_FreeChunk(eatMix);
		eatMix = NULL;
		delete mSDLHelper; //TODO check if this still works without QUITVISUALIZATION METHOD
	}
}
