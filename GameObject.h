#pragma once

#include "app.h"

class GameObject
{
private:
	int playerHealth{60};
	int playerDamage{20};

	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
public:
	GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y);
	~GameObject();

	SDL_Rect getPlayerRect();

	void characterMovement();
	void mousePosition();
	void update();
	void render();

	void getPlayerLocation(int *x, int *y);

	void deletePlayerTexture();
};

