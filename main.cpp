#include "game.hpp"

int main(int argc, char** argv){
    Game game = Game();

    game.init();
    game.loadMedia();

    while(game.getRuntime()){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    game.setRuntime();
                    break;
                default:
                    break;
            }
        }
    }
    return 0;
}