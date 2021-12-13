#pragma once
#include "App.h"

class TextureManager
{
private:

public: 
	static SDL_Texture* LoadTexture(const char* texture, SDL_Renderer* ren);
};

