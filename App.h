#pragma once
class App
{
private:
	const int screenWidth{1280};
	const int screenHeight{720};

	SDL_Window* window = SDL_CreateWindow("Top down shooter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		screenWidth, screenHeight, SDL_WINDOW_SHOWN);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	void initSDL();

	void prepareScene();
	void presentScene();

	void doInput();

	void loop();

public:
	void mainFunction();
	

};

