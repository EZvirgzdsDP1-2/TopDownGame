#include "App.h"

#include "TextureManager.h"
#include "GameObject.h"
#include "ECS.h"
#include "Components.h"

GameObject* player;
GameObject* enemy;
Manager manager;
auto& newPlayer(manager.addEntity());

void App::init(const char* title, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_screenWidth, m_screenHeight, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 3, 156, 90, 55);
		}

		isRunning = true;
	}
	//
	player = new GameObject("assets/redditor.png", renderer, 0, 0);
	enemy = new GameObject("assets/dumbshit.png", renderer, 150, 60);
	newPlayer.addComponent<PoisitionComponent>();
}

void App::runApp()
{
	frameStart = SDL_GetTicks();

	handleEvent();
	update();
	render();

	frameTime = SDL_GetTicks() - frameStart;

	if (frameDelay > frameTime)
	{
		SDL_Delay(frameDelay - frameTime);
	}
}


void App::update()
{
	player->update();
	enemy->update();
	manager.update();
	std::cout << newPlayer.getComponent<PoisitionComponent>().x() << ","
		<< newPlayer.getComponent<PoisitionComponent>().y() << std::endl;
}

void App::render()
{
	SDL_RenderClear(renderer);
	player->render();
	enemy->render();

	SDL_RenderPresent(renderer);
}

void App::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void App::handleEvent()
{
	SDL_Event event;

	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

App::App()
{
}

App::~App()
{
}