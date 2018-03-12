#include <sdl2/SDL.h>
#include "SDLPacman.h"
#include "AbstractFactory.h"

#ifndef SDLFACTORY_H_
#define SDLFACTORY_H_

class SDLFactory : public AbstractFactory{
public:
	SDLFactory();
	virtual ~SDLFactory();
	Pacman* createPacman();
private:
	bool init();
	bool loadMedia();
	void close();
	SDL_Window* gWindow = NULL;
	SDL_Surface* gScreenSurface = NULL;
	SDL_Surface* gHelloWorld = NULL;
};

#endif /* SDLFACTORY_H_ */
