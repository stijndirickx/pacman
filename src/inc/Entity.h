#ifndef INC_ENTITY_H_
#define INC_ENTITY_H_

namespace Logic{
	class Entity{
	public:
		Entity();
		virtual ~Entity();
		virtual void Paint() = 0;
	private:
		int x;
		int y;
	};
}

#endif /* INC_ENTITY_H_ */
