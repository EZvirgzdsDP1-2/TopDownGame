#include <SDL.h>
#include <SDL_image.h>
#include <cassert>
#include <iostream>
#include <cstdlib>

#include <Windows.h>

#include "App.h"



void App::initSDL()
{
	int rendererFlags{ SDL_RENDERER_ACCELERATED };
	int windowFlags{ 0 };

	SDL_Init(SDL_INIT_EVERYTHING);

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		assert("Couldn't initalize SDL!");
	}

	if (!window)
	{
		assert("Error 26 app");
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	if (!renderer)
	{
		assert("error 33 app");
	}

}


void App::prepareScene()
{
	SDL_SetRenderDrawColor(renderer, 3, 156, 90, 55);

	SDL_RenderClear(renderer);
}

void App::presentScene()
{
	SDL_RenderPresent(renderer);
}

void App::doInput()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			exit(1);
			break;

		default:
			break;
		}
	}
}

void App::loop()
{
	while (true) 
	{ 
		prepareScene();

		doInput();

		presentScene();
		
		SDL_Delay(16); 
	}
}

void App::mainFunction()
{
	initSDL();
	loop();
}
