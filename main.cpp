#include "game.hpp"

Game *game = nullptr;

enum keyPress{
    KEY_PRESS_UP,
    KEY_PRESS_DOWN,
    KEY_PRESS_RIGHT,
    KEY_PRESS_LEFT
};

int main(int argc, char** argv){
    game = new Game();
    game->init("Cemetery Outburst", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 800, false);

    while(game->running()){
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();
    return 0;
}