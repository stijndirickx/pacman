#ifndef GAME_H_
#define GAME_H_

#include <SDL2/SDL.h> 		//TODO DELETE THIS, SEPRATE SDL/LOGIC
#include <SDL2/SDL_image.h> //TODO DELETE THIS, SEPRATE SDL/LOGIC
#include <string> 			//TODO DELETE THIS PART OF LOADTEXTURE

namespace Logic{
	class Game{
	public:
		Game(AbstractFactory* abstractFactory);
		virtual ~Game();
		void Start();

	private:
		AbstractFactory* f;


		SDL_Texture* loadTexture( std::string path ); //TODO SPLIT SDL


		SDL_Renderer* _renderer = NULL;				//TODO SPLIT SDL
		SDL_Texture* _TextureBob = NULL;
		SDL_Texture* _TextureGrass = NULL;
	};
}

#endif /* GAME_H_ */
