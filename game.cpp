#include "game.hpp"

Game::Game(){

}

Game::~Game(){

}

void Game::init(const char *title, int xPos, int yPos, int width, int height, bool fullscreen){   
    int flags = 0;
    if(fullscreen == true){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if (SDL_Init(SDL_INIT_EVERYTHING)!= 0){
        std::cerr << "ERROR: could not initialize SDL!" << std::endl;
        return;
    }

    gWindow = SDL_CreateWindow(title, xPos, yPos, width, height, flags);

    if(!gWindow){
        std::cerr << "ERROR: could not initialize the window!" << std::endl;
        SDL_Quit();
        return;
    }

    gRenderer = SDL_CreateRenderer(gWindow, -1, 0);

    if(!gRenderer){
        std::cerr << "ERROR: could not initialize the renderer!" << std::endl;
        SDL_DestroyWindow(gWindow);
        SDL_Quit();
        return;
    }

    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 0);
    isRunning = true;
}

void Game::update(){

}

void Game::render(){
    SDL_RenderClear(gRenderer);
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
    SDL_DestroyWindow(gWindow);
    SDL_DestroyRenderer(gRenderer);
    SDL_Quit();

    std::cout << "SUCCESS: Game successfully cleaned!" << std::endl;
}

bool Game::running(){
    return isRunning;
}