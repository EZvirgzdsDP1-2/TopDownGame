#include <iostream>
#include <sdl.h>

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window = SDL_CreateWindow("Penids", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 700, SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_SetRenderDrawColor(renderer, 3, 156, 90, 55);

    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);

    SDL_Delay(5000);

    return 0;
}