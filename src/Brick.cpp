#include "Brick.h"

namespace logic
{
	Brick::Brick()
	{

	}

	Brick::~Brick()
	{

	}

	void Brick::createBrick(int x, int y, int width, int height, int type)
	{

		//if(type == PATH){
			//TODO extra possible adjustments on bricks
		//}

		//brickInfo = {x, y, width, height, type};
		brickInfo[0] = x;
		brickInfo[1] = y;
		brickInfo[2] = width;
		brickInfo[3] = height;
		brickInfo[4] = type;
		this->visualize();
	}

	int* Brick::readBrickInfo()
	{
		return brickInfo;
	}

	void Brick::updateBrickType(int type)
	{
		brickInfo[4] = type;
	}
}
