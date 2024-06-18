#include "game.hpp"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

void Game::init(){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Error: SDL failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
    }

    window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if(!window){
        printf("Error: Failed to open window\nSDL Error: '%s'\n", SDL_GetError());
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer){
        printf("Error: Failed to crearte renderer\nSDL Error: '%s'\n", SDL_GetError());
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

bool Game::loadMedia(){
    gHelloWorld = SDL_LoadBMP("preview.png");

    if (gHelloWorld == NULL)
    {
        printf("Error: Failed to renderer the image\nSDL Error: '%s'\n", SDL_GetError());
        return false;
    }
    SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
    return true;
}

void Game::close(){
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    SDL_Quit();
}

void Game::setRuntime(){
    gRuntime = !gRuntime;
}

bool Game::getRuntime(){
    return gRuntime;
}