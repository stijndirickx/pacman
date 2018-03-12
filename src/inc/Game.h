#ifndef GAME_H_
#define GAME_H_

class Game{
public:
	Game(AbstractFactory* abstractFactory);
	void Start();
private:
	AbstractFactory* f;
};

#endif /* GAME_H_ */
