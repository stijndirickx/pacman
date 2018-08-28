#include "Brick.h"

namespace logic
{
	Brick::Brick() {}
	Brick::~Brick() {}

	void Brick::setType(int type)
	{
		boxInt[4] = type;
	}

	void Brick::renderTile(int x, int y, int tileType, int width, int height)
	{
/*		if (tileType == 25)
		{
			int defWidth = width;
			width = defWidth * 0.75; // only 3/4 size of square
			height = width; //still a little square border box
			x = x+((defWidth-width)/2); //center of square
			y = y+((defWidth-width)/2);
		}
		else */
		if (tileType == 2)   // PAC DOT
		{
			int defWidth = width;
			width = defWidth * 0.75; // only 1/4 size of square
			height = width; //still a little square border box
			x = x+((defWidth-width)/2); //center of square
			y = y+((defWidth-height)/2);
		}

		boxInt[0] = x;
		boxInt[1] = y;
		boxInt[2] = width;
		boxInt[3] = height;
		boxInt[4] = tileType;

		this->paint();
	}

	int* Brick::getBoxInt()
	{
		return boxInt;
	}
}
