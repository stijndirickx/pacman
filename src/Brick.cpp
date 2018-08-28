#include "Brick.h"

namespace logic
{
	Brick::Brick() {}
	Brick::~Brick() {}

	void Brick::setType(int type)
	{
		brickProp[3] = type;
	}

	void Brick::renderBrick(int x, int y, int size, int type)
	{
		if (type == 2)   // = Plus
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

	int* Brick::getProp()
	{
		return brickProp;
	}
}
