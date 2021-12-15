#include <iostream>
#include <cmath>

#include "GameObject.h"
#include "TextureManager.h"

SDL_Point center{30, 30};
int Delta_x{ 0 };
int Delta_y{ 0 };

int mouseX{ 0 };
int mouseY{ 0 };

double angle{};

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
   

    SDL_GetMouseState(&mouseX, &mouseY);

    Delta_x = xpos - mouseX;
    Delta_y = ypos - mouseY;

    angle = (atan2(Delta_y, Delta_x) * 180.0000) / 3.14159265;
    
    
    //SDL_RenderCopyEx(renderer, objTexture,nullptr, &destRect, angle, &center, SDL_FLIP_NONE);

    //std::cout << "Mouse coordinates: " << mouseX << " " << mouseY << '\n';
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
    SDL_RenderCopyEx(renderer, objTexture, &srcRect, &destRect, angle, &center, SDL_FLIP_NONE);
	
    SDL_RenderPresent(renderer);
    //SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}
