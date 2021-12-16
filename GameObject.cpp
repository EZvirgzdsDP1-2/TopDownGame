#include <iostream>
#include <cmath>

#include "GameObject.h"
#include "TextureManager.h"

SDL_Point Pcenter{32, 32};
int Delta_x{ 0 };
int Delta_y{ 0 };

int mouseX{ 0 };
int mouseY{ 0 };

double Pangle{};

GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y)
{
	renderer = ren;
	objTexture = TextureManager::LoadTexture(texturesheet, ren);

	Pxpos = x;
	Pypos = y;
}

GameObject::~GameObject()
{
}

void GameObject::playerMovement()
{
    const Uint8* state = SDL_GetKeyboardState(nullptr);

    if (state[SDL_SCANCODE_W])
    {
        if (Pypos >= 0 and Pypos - 2 > 0)
        {
            Pypos -= 2;
        }
        else
        {
            Pypos == 0;
        }

    }
    if (state[SDL_SCANCODE_S])
    {
        if (Pypos <= 656 and Pypos + 2 < 656)
        {
            Pypos += 2;
        }
        else
        {
            Pypos == 656;
        }
    }
    if (state[SDL_SCANCODE_A])
    {
        if (Pxpos >= 0 and Pxpos - 2 > 0)
        {
            Pxpos -= 2;
        }
        else
        {
            Pxpos == 0;
        }
    }
    if (state[SDL_SCANCODE_D])
    {
        if (Pxpos <= 1216 and Pxpos + 2 < 1216)
        {
            Pxpos += 2;
        }
        else
        {
            Pxpos == 1216;
        }
    }
}

void GameObject::mousePosition()
{
   

    SDL_GetMouseState(&mouseX, &mouseY);

    Delta_x = Pxpos - mouseX;
    Delta_y = Pypos - mouseY;

    Pangle = (atan2(Delta_y, Delta_x) * 180.0000) / 3.14159265;
    
    
    //SDL_RenderCopyEx(renderer, objTexture,nullptr, &destRect, angle, &center, SDL_FLIP_NONE);

    //std::cout << "Mouse coordinates: " << mouseX << " " << mouseY << '\n';
}

void GameObject::playerUpdate()
{
    playerMovement();
    mousePosition();

	PsrcRect.h = 65;
	PsrcRect.w = 65;
	PsrcRect.x = 0;
	PsrcRect.y = 0;

	PdestRect.x = Pxpos;
	PdestRect.y = Pypos;
	PdestRect.w = PsrcRect.w;
	PdestRect.h = PsrcRect.h;
}

void GameObject::playerRender()
{
    SDL_RenderCopyEx(renderer, objTexture, &PsrcRect, &PdestRect, Pangle, &Pcenter, SDL_FLIP_NONE);
	
    SDL_RenderPresent(renderer);
    //SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}

EnemyGameObject::EnemyGameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y)
{
    renderer = ren;
    objTexture = TextureManager::LoadTexture(texturesheet, ren);

    Expos = x;
    Eypos = y;
}

void EnemyGameObject::enemyRender()
{
    SDL_RenderCopy(renderer, objTexture, &EsrcRect, &EdestRect);
}

void EnemyGameObject::enemyUpdate()
{
    enemyMovement();
    EsrcRect.h = 65;
    EsrcRect.w = 65;
    EsrcRect.x = 0;
    EsrcRect.y = 0;

    EdestRect.x = Expos;
    EdestRect.y = Eypos;
    EdestRect.w = EsrcRect.w;
    EdestRect.h = EsrcRect.h;
}

void EnemyGameObject::enemyMovement()
{
    const Uint8* state = SDL_GetKeyboardState(nullptr);

    if (state[SDL_SCANCODE_UP])
    {
        if (Eypos >= 0 and Eypos - 2 > 0)
        {
            Eypos -= 2;
        }
        else
        {
            Eypos == 0;
        }

    }
    if (state[SDL_SCANCODE_DOWN])
    {
        if (Eypos <= 656 and Eypos + 2 < 656)
        {
            Eypos += 2;
        }
        else
        {
            Eypos == 656;
        }
    }
    if (state[SDL_SCANCODE_LEFT])
    {
        if (Expos >= 0 and Expos - 2 > 0)
        {
            Expos -= 2;
        }
        else
        {
            Expos == 0;
        }
    }
    if (state[SDL_SCANCODE_RIGHT])
    {
        if (Expos <= 1216 and Expos + 2 < 1216)
        {
            Expos += 2;
        }
        else
        {
            Expos == 1216;
        }
    }
}
