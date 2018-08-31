#include "Brick.h"

namespace logic
{
	Brick::Brick() {}
	Brick::~Brick() {}


	int* Brick::getProp()
	{
		return brickProp;
	}

	void Brick::renderBrick(int x, int y, int size, int type)
	{
		if (type == 2)   //Resize the Plus-brick
		{
			x = x+(size/4); // Center x-axis
			y = y+(size/4); // Center y-axis
			size = size * 0.5; //Make smaller
		}

		brickProp[0] = x;
		brickProp[1] = y;
		brickProp[2] = size;
		brickProp[3] = type;

		this->paint();
	}


	void Brick::setType(int type) //See Assets/Maps/legend.txt for typeIDs
	{
		brickProp[3] = type;
	}
}
