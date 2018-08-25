/*
 * Wall.h
 *
 *  Created on: Mar 15, 2018
 *      Author: ruben
 */

#ifndef TILE_H_
#define TILE_H_
#include <iostream>
using namespace std;

namespace PACMAN {
	class Tile {
	public:
		Tile();
		virtual ~Tile();
		void SetTileType(int type);
		int* GetBoxInt();
		void RenderTile(int x, int y, int tileType, int width, int height);
		virtual void Visualize() = 0;
	protected:
		int boxInt [5];

		const int PATH = 0;
		const int WALL_VERT = 1;
		const int WALL_HORI = 2;
		const int WALL_COR_UP_LR = 3;
		const int WALL_COR_UP_RL = 4;
		const int WALL_COR_DOWN_RL = 5;
		const int WALL_COR_DOWN_LR = 6;
		const int CHERRY = 8;
		const int PELLET = 9;
	};
}
#endif /* TILE_H_ */
