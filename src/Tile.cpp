/*
 * Wall.cpp
 *
 *  Created on: Mar 15, 2018
 *      Author: ruben
 */

#include "Tile.h"

namespace PACMAN {
	Tile::Tile() {
	}

	Tile::~Tile() {
		// TODO Auto-generated destructor stub
	}

	void Tile::SetTileType(int type){
		boxInt[4] = type;
	}

	void Tile::RenderTile(int x, int y, int tileType, int width, int height) {
		if (tileType == PELLET){
			int defWidth = width;
			width = defWidth * 0.75; // only 3/4 size of square
			height = width; //still a little square border box
			x = x+((defWidth-width)/2); //center of square
			y = y+((defWidth-width)/2);

		} else if (tileType == PATH) { // PAC DOT
			int defWidth = width;
			width = defWidth * 0.25; // only 1/4 size of square
			height = width; //still a little square border box
			x = x+((defWidth-width)/2); //center of square
			y = y+((defWidth-height)/2);
		}

		boxInt[0] = x;
		boxInt[1] = y;
		boxInt[2] = width;
		boxInt[3] = height;
		boxInt[4] = tileType;

		this->Visualize();
	}

	int* Tile::GetBoxInt()
	{
		return boxInt;
	}
}
