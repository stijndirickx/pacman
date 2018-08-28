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
			int* getBoxInt();
			void renderTile(int x, int y, int tileType, int width, int height);

			virtual void paint() = 0;

		protected:
			int boxInt [5];
	};
}
#endif
