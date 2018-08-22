#ifndef BRICK_H_
#define BRICK_H_

#include <iostream> //TODO NEW

using namespace std; //TODO NEW

namespace logic
{
	class Brick
	{
		public:
			Brick();
			virtual ~Brick();

			void createBrick(int x, int y, int width, int height, int type);
			int* readBrickInfo();
			void updateBrickType(int type);

			virtual void visualize() = 0;

		protected:
			int brickInfo [5]; //(x,y,width,height,type)

			const int PATH = 0;
			const int WALL_UP_LEFT = 1;		//topleft corner
			const int WALL_UP_DOWN = 2;		//vertical
			const int WALL_UP_RIGHT = 3;	//topright corner
			const int WALL_DOWN_LEFT = 4;	//leftbottom corner
			const int WALL_DOWN_RIGHT = 5; 	//rightbottom corner
			const int WALL_LEFT_RIGHT = 6;
			const int FOOD_REGULAR = 7;
			const int FOOD_BONUS = 8;
			const int OPEN = 9;				//todo look into this, not used in SDLBrick
	};
}

#endif
