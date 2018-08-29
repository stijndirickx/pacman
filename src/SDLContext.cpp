#include "SDLContext.h"

namespace graphics_SDL
{
	SDLContext::SDLContext(SDLHelper* pHelper)
	{
		mHelper = pHelper;
		renderer = mHelper->getRenderer();
		surface = mHelper->getSurface();

		fontText = TTF_OpenFont("Assets/Fonts/Starjedi.ttf", 16);
		fontTitle = TTF_OpenFont("Assets/Fonts/Starjedi.ttf", 40);
		msgColor = {255, 220, 220}; //Salmon pink

		music = Mix_LoadWAV("Assets/Sounds/c++man_beginning.wav");
		sound = Mix_LoadWAV("Assets/Sounds/c++man_eatghost.wav");
	}

	SDLContext::~SDLContext()
	{
		Mix_FreeChunk(music);
		music = NULL;
		Mix_FreeChunk(sound);
		sound = NULL;
		delete mHelper;
	}

	void SDLContext::updateText()
	{
		renderText(fontText, "Score: " + std::to_string(score), 20, 0, 0);
		renderText(fontText, "Lives: " + std::to_string(lives), windowWidth - 20, 0, 1);

		if(!playing)
		{
			renderText(fontTitle, displayString, windowWidth/2 , windowHeight/2  - 60, 2);
			renderText(fontText, "Press 'space' to play", windowWidth/2, windowHeight/2 - 20, 2);

			if(lives <= 0)
			{
				renderText(fontText, "Hiscore: " + std::to_string(highScore), windowWidth/2, windowHeight/2 + 20, 2);
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

	void SDLContext::playSound(int soundId) //Check Assets/Sounds/legend.txt for id's of WAV file
	{
		Mix_FreeChunk(sound);
		switch(soundId)
		{
			case 4:
				sound = Mix_LoadWAV("Assets/Sounds/c++man_death.wav");
				break;
			case 5:
				sound = Mix_LoadWAV("Assets/Sounds/c++man_eatfruit.wav");
				break;
			case 6:
				sound = Mix_LoadWAV("Assets/Sounds/c++man_eatghost.wav");
				break;
			case 7:
				sound = Mix_LoadWAV("Assets/Sounds/c++man_eateclipse.wav");
				break;
		}
		Mix_PlayChannel(soundId, sound, 0);
	}

	void SDLContext::playMusic(int musicId) //Check Assets/Sounds/legend.txt for id's of WAV file
	{
		int notplayA=1;int notplayB=3;
		string musicString;
		switch(musicId)
		{
			case 1:
				notplayA=2;
				musicString = "Assets/Sounds/c++man_beginning.wav";
				break;
			case 2:
				musicString = "Assets/Sounds/c++man_chomp.wav";
				break;
			case 3:
				notplayB=2;
				musicString = "Assets/Sounds/c++man_intermission.wav";
				break;
		}

		if((Mix_Playing(notplayA) != 0)||(Mix_Playing(notplayB) != 0)) //other track is playing
		{
			if(Mix_Playing(notplayA) != 0) 	//stop playing track
			{
				Mix_HaltChannel(notplayA);
			}
			else							//stop playing track
			{
				Mix_HaltChannel(notplayB);
			}
			Mix_FreeChunk(music);		//Free chunk from this track
			music = Mix_LoadWAV(musicString.c_str()); //Load new WAV
		}

		if(Mix_Playing(musicId) == 0) //Check if right track isnt playing yet, if so start playing
		{
			Mix_PlayChannel(musicId, music, 0);
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
