#ifndef Game_hpp
#define Game_hpp

#include <SDL2/SDL.h>
#include <stdio.h>

class Game {
    private:
        SDL_Window* gWindow = NULL;
        SDL_Surface* gScreenSurface = NULL;
        SDL_Surface* gHelloWorld = NULL;
        SDL_Window *window = NULL;
        SDL_Renderer *renderer = NULL;
        bool gRuntime = true;
    public:
        void init();
        bool loadMedia();
        void close();
        void setRuntime();
        bool getRuntime();

};

#endif