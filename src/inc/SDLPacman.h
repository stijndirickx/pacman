#ifndef INC_SDLPACMAN_H_
#define INC_SDLPACMAN_H_
#include "Pacman.h"

class SDLPacman:public Pacman{
public:
	virtual ~SDLPacman();
	SDLPacman();
	void Paint();
};

#endif /* INC_SDLPACMAN_H_ */
