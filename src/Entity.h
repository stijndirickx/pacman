#ifndef INC_ENTITY_H_
#define INC_ENTITY_H_

namespace logic{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();
		virtual void Paint() = 0;
	protected: //derived classes can access
		int x;
		int y;
	};
}

#endif /* INC_ENTITY_H_ */
