#include "Game.h"
#include <fstream>

namespace PACMAN
{
	Game::Game(Factory*& abstractFactory)
	{
		aFactory = abstractFactory;

		cFile = aFactory->CreateConfig();
		numOfGhosts = cFile->getEnemiesCount();
		animationSpeed = cFile->getFpa(); //every x frames sprite change
		fps = cFile->getFps();
		mspf = 1000/fps; //ms per f: 30FPS --> every 33.3 ms a frame
		countToAttacking = 8000 / mspf; // 8 sec / ms per frame = # frames to go
	}

	Game::~Game(){}

	void Game::Start()
	{
		Map* map = aFactory->CreateMap();
		GameContext* gContext = aFactory->CreateGameContext();
		gContext->SetTileSize(cFile->getBrickSize());
		gContext->SetLives(cFile->getLivesCount());
		gContext->SetNumOfGhosts(numOfGhosts);

		Player* player = aFactory->createPlayer();
		player->setSpeed(cFile->getPlayerSpeed());
		Ghost* ghosts[numOfGhosts];
		for(int i = 0; i < numOfGhosts; i++)
		{
			ghosts[i] = aFactory->CreateGhost(i);
		}

		EventHandler* ev = aFactory->CreateEventHandler();
		int last_frame = 0;
		clock_t ticks = 0;
		int clock_ms = 0; //clock in ms
		int countingAttack = 0;
		bool quit = false;

		while(!quit)
		{
			while(ev->PollEvent() != 0)
			{
				//User requests quit
				if(ev->QuitEvent())
				{
					quit = true;
				}
				else if(ev->KeyDown())
				{
					if(ev->GetKeyDown() == 6) //pressed enter
					{
						if(map->GetNumOfPellets() > 0)
						{
							gContext->SetPlaying(!gContext->GetPlaying(), "Paused");
							if(!player->getAliveState())
							{
								player->setAliveState(true);
								for(int j=0; j < numOfGhosts;j++)
								{
									ghosts[j]->ResetGhost();
								}
								if(gContext->GetLives() <= 0)
								{
									gContext->ResetGame();
									gContext->SetLives(cFile->getLivesCount());
									map->Load();
								}
								player->setDirection(4);
							}
						}
						else
						{
							map->Load();
							player->setAliveState(true);
							player->setDirection(4);
							gContext->SetPlaying(true, "Paused");
						}
					}
					else if (gContext->GetPlaying()) //not changing direction while paused
					{
						player->setDirection(ev->GetKeyDown());
					}
				}
			}

			if(!ghosts[0]->GetAttackingState()) //if ghosts vulnerable
			{
				if(countingAttack == 0)
				{
					countingAttack = countToAttacking;
				}
				else if(countingAttack == 1)
				{
					for(int j=0; j < numOfGhosts;j++) // set ghosts back to attacking
					{
						ghosts[j]->SetAttackingState(true);
					}
				}
			}

			if(map->GetNumOfPellets() == 0)
			{
				gContext->SetPlaying(false, "Winner");
			}

			ticks = clock(); //#clock ticks since running
			clock_ms = (ticks/(double)CLOCKS_PER_SEC)*1000.0; //#ms since running

			if(last_frame != clock_ms && clock_ms % mspf == 0)
			{
				last_frame = clock_ms; //make sure not multiple frames in same ms

				gContext->ClearScreen();
				map->Draw();
				if(gContext->GetPlaying())
				{
					player->move();
					ghosts[0]->MoveTo(player->getX(), player->getY());
					ghosts[1]->MoveInFront(player->getX(), player->getY());
					player->gotCaptured(ghosts, numOfGhosts);
					for(int j=2; j < numOfGhosts;j++)
					{
						ghosts[j]->Move();
					}
					gContext->PlaySound("pacman");
				}
				else
				{
					player->paint();
					for(int j=0; j < numOfGhosts;j++)
					{
						ghosts[j]->Visualize();
					}
					gContext->PlaySound("beginning");
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
						for(int j=0; j < numOfGhosts;j++)
						{
							ghosts[j]->SetFlashingState(!ghosts[j]->GetFlashingState());
						}
					}
				}

				gContext->UpdateText();
				gContext->UpdateScreen();
			}
		}

		// Game ended
		for(int i = 0; i < numOfGhosts; i++)
		{
			delete ghosts[i];
		}
		gContext->QuitVis();
		delete player;
		delete ev;
	}
}

