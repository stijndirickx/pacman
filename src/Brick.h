#ifndef BRICK_H_
#define BRICK_H_

#include <iostream>

using namespace std;

namespace logic
{
	class Brick
	{
		public:
			Brick();
			virtual ~Brick();

			void setType(int type);
			int* getProp();
			void renderBrick(int x, int y, int size, int type);

			virtual void paint() = 0;

		protected:
			int brickProp [4]; //x, y , size, type
	};
}
#endif
