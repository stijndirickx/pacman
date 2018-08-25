/*
 * Pacman.h
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#ifndef PACMAN_H_
#define PACMAN_H_

#include <iostream>
#include "Factory.h"
#include "Entity.h"
#include "Ghost.h"
using namespace std;

namespace PACMAN {
	class Ghost;
	class Pacman : public Entity {
	public:
		Pacman();
		virtual ~Pacman();
		int GetX();
		int GetY();
		void SetDirection(int key);
		bool GetLiving();
		bool SetLiving(bool alive);
		void Animate();
		void Move();
		void GotCaptured(Ghost* ghosts[], int numOfGhosts);

		virtual void Visualize() = 0;
		virtual void MoveInDir(int direction) = 0;
	protected:
		int pacmanVel = 5; // velocity = tilesize / pacmanVel
		bool living = true;
		int direction = 4;
		int prevDirection = 4;
		int frame = 0;
	};
}

#endif /* PACMAN_H_ */
