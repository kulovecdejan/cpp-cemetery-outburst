#ifndef Game_hpp
#define Game_hpp

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keyboard.h>
#include <iostream>

class Game {
    private:
        SDL_Window *gWindow;
        SDL_Renderer *gRenderer;
        bool isRunning;
    public:
        Game();
        ~Game();

        void init(const char *title, int xPos, int yPos, int width, int height, bool fullscreen);
        void handleEvents();
        void update();
        void render();
        void clean();
        bool running();
};

#endif