#ifndef GAME_H_
#define GAME_H_

namespace Logic{
	class Game{
	public:
		Game(AbstractFactory* abstractFactory);
		virtual ~Game();
		void Start();
	private:
		AbstractFactory* f;
	};
}

#endif /* GAME_H_ */
