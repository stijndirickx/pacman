#ifndef BRICK_H_
#define BRICK_H_

namespace logic
{
	class Brick
	{
		public:
			Brick();
			virtual ~Brick();

			int* getProp();
			void renderBrick(int x, int y, int size, int type);
			void setType(int type);

			virtual void paint() = 0;

		protected:
			int brickProp [4]; //x, y , size, type
	};
}
#endif
