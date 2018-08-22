#include "Game.h"

namespace logic
{
	Game::Game(AbstractFactory* pAbstractFactory){
		mAbstractFactory = pAbstractFactory;
		mConfig = mAbstractFactory->getConfig();

		animationSpeed = mConfig->getAnimationSpeed();
		numOfEnemies = mConfig->getNumOfEnemies();
		fps = mConfig->getFps();
		mspf = 1000/fps;
		countToAttacking = 8000/mspf; //number of frames till 8s
	}

	Game::~Game()
	{
		//TODO empty deconstruct
	};


	void Game::Start(){

		House* house = mAbstractFactory->getHouse();
		Context* context = mAbstractFactory->createContext();
		context->setBrickSize(mConfig->getBrickSize()); //TODO expand context
		context->setLives(mConfig->getLives());
		context->setNumOfEnemies(numOfEnemies);

		Player* player = mAbstractFactory->createPlayer();
		Enemy* enemies[numOfEnemies];
		for(int i = 0; i < numOfEnemies; i++)
		{
			enemies[i] = mAbstractFactory->createEnemy(i);
		}

		EventHandler* eventHandler = mAbstractFactory->createEventHandler();

		int last_frame = 0;
		clock_t ticks = 0;
		int clock_ms = 0; //clock in ms
		int countingAttack = 0;
		bool quit = false;

		while(!quit)
		{
			while( eventHandler->pollEvent() != 0 )
			{
				if(eventHandler->quitEvent())
				{
					quit = true;
				}
				else if(eventHandler->keyDown())
				{
					if(eventHandler->getKeyDown() == 6) //pressed enter TODO, change to space
					{
						if(house->getNumOfPellets() > 0)
						{
							context->setPlaying(!context->getPlaying(), "Paused"); //TODO check string
							if(!player->isAlive())
							{
								player->setAlive(true);
								for(int j=0; j < numOfEnemies;j++)
								{
									enemies[j]->resetEnemy();
								}
								if(context->getLives() <= 0) //Game is lost
								{
									context->resetGame();
									context->setLives(mConfig->getLives());
									house->load();
								}
								player->setDirection(4);
							}
						}
						else
						{
							house->load();
							player->setAlive(true);
							player->setDirection(4);
							context->setPlaying(true, "Paused");
						}
					}
					else if (context->getPlaying())  //not changing direction while paused TODO
					{
						player->setDirection(eventHandler->getKeyDown());
					}
				}
			}

			if(!enemies[0]->getAttackingState()) //if ghosts vulnerable
			{
				if(countingAttack == 0)
				{
					countingAttack = countToAttacking;
				}
				else if(countingAttack == 1)
				{
					for(int i=0; i < numOfEnemies;i++) // set ghosts back to attacking
					{
						enemies[i]->setAttackingState(true);
					}
				}
			}

			if(house->getNumOfPellets() == 0)
			{
				context->setPlaying(false, "Winner");
			}

			ticks = clock(); //#clock ticks since running
			clock_ms = (ticks/(double)CLOCKS_PER_SEC)*1000.0; //#ms since running

			if(last_frame != clock_ms && clock_ms % mspf == 0)
			{
				last_frame = clock_ms; //make sure not multiple frames in same ms
				context->clearScreen();
				house->draw();
				if(context->getPlaying())
				{
					player->move();
					enemies[0]->moveTo(player->getX(), player->getY());
					enemies[1]->moveInFront(player->getX(), player->getY());
					player->gotCaptured(enemies, numOfEnemies);

					for(int i=2; i < numOfEnemies;i++)
					{
						enemies[i]->move();
					}
					context->playSound("chomp");
				}
				else
				{
					player->paint();
					for(int i=0; i < numOfEnemies;i++)
					{
						enemies[i]->paint();
					}
					context->playSound("beginning");
				}
				if(clock_ms % (animationSpeed*mspf) == 0) //every x frames animation
				{
					player->animate();
				}

				if(countingAttack > 0)
				{
					countingAttack--;
					if(countingAttack <= 30 && clock_ms % (animationSpeed*mspf) == 0)
					{
						for(int i=0; i < numOfEnemies;i++)
						{
							enemies[i]->setFlashingState(!enemies[i]->getFlashingState());
						}
					}
				}

				context->updateText();
				context->updateScreen();
			}
		}

		// Game ended
		for(int i = 0; i < numOfEnemies; i++)
		{
			delete enemies[i];
		}
		delete context;
		delete player;
		delete eventHandler;
	}
}

