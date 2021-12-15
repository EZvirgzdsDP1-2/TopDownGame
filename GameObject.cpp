#include <iostream>

#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y)
{
	renderer = ren;
	objTexture = TextureManager::LoadTexture(texturesheet, ren);

	xpos = x;
	ypos = y;
}

GameObject::~GameObject()
{
}

void GameObject::characterMovement()
{
    const Uint8* state = SDL_GetKeyboardState(nullptr);

    if (state[SDL_SCANCODE_W])
    {
        if (ypos >= 0 and ypos - 4 > 0)
        {
            ypos -= 4;
        }
        else
        {
            ypos == 0;
        }

    }
    if (state[SDL_SCANCODE_S])
    {
        if (ypos <= 656 and ypos + 4 < 656)
        {
            ypos += 4;
        }
        else
        {
            ypos == 656;
        }
    }
    if (state[SDL_SCANCODE_A])
    {
        if (xpos >= 0 and xpos - 4 > 0)
        {
            xpos -= 4;
        }
        else
        {
            xpos == 0;
        }
    }
    if (state[SDL_SCANCODE_D])
    {
        if (xpos <= 1216 and xpos + 4 < 1216)
        {
            xpos += 4;
        }
        else
        {
            xpos == 1216;
        }
    }
}

void GameObject::mousePosition()
{
    int mouseX{ 0 };
    int mouseY{ 0 };

    Uint32 buttons = SDL_GetMouseState(&mouseX, &mouseY);

    std::cout << "Mouse coordinates: " << mouseX << " " << mouseY << '\n';
}

void GameObject::update()
{
    characterMovement();
    mousePosition();

	srcRect.h = 65;
	srcRect.w = 65;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
}

void GameObject::render()
{
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}
