#include "game.hpp"
#include <SDL2/SDL_image.h>
#include <iostream>

SDL_Texture* texture = nullptr;
SDL_Rect textureRect;

Game::Game(){}

Game::~Game(){}

void Game::init(const char *title, int xPos, int yPos, int width, int height, bool fullscreen){   
    int flags = 0;
    if(fullscreen == true){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cerr << "ERROR: could not initialize SDL! " << SDL_GetError() << std::endl;
        return;
    }

    gWindow = SDL_CreateWindow(title, xPos, yPos, width, height, flags);

    if(!gWindow){
        std::cerr << "ERROR: could not initialize the window! " << SDL_GetError() << std::endl;
        clean();
        return;
    }

    gRenderer = SDL_CreateRenderer(gWindow, -1, 0);

    if(!gRenderer){
        std::cerr << "ERROR: could not initialize the renderer! " << SDL_GetError() << std::endl;
        clean();
        return;
    }

    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 0);

    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        std::cerr << "ERROR: could not initialize SDL_image! " << IMG_GetError() << std::endl;
        clean();
        return;
    }

    texture = IMG_LoadTexture(gRenderer, "preview.png");
    if (!texture) {
        std::cerr << "ERROR: could not load texture! " << IMG_GetError() << std::endl;
        clean();
        return;
    }

    textureRect.x = 0;
    textureRect.y = 0;
    textureRect.w = 150;
    textureRect.h = 150;

    isRunning = true;
}

void Game::update(){
}

void Game::render(){
    SDL_RenderClear(gRenderer);
    SDL_RenderCopy(gRenderer, texture, NULL, &textureRect);
    SDL_RenderPresent(gRenderer);
}

void Game::handleEvents(){
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

void Game::clean(){
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    SDL_Quit();

    std::cout << "SUCCESS: Game successfully cleaned!" << std::endl;
}

bool Game::running(){
    return isRunning;
}
