#ifndef INC_ENTITY_H_
#define INC_ENTITY_H_

class Entity{
public:
	Entity();
	virtual ~Entity();
	virtual void Paint() = 0;
private:
	int x;
	int y;
};

#endif /* INC_ENTITY_H_ */
