#ifndef PROJECT2DTD_ENGINE_H
#define PROJECT2DTD_ENGINE_H
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "EntityType.h"
#include "TextureMap.h"
#include <random>
#include <ctime>
#include <iostream>
#include <vector>

class Engine {
public:
    Engine();
    ~Engine();


    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen, bool resizable);

    //void loadEntity(EntityType* entity);

    void pushSpriteSheet(SDL_Texture* texture);

    void handleEvents();
    static void update();
    static void render();
    void clean();
    bool running() {
        return isRunning;
    }
    static int* getEngineWidth();
    static int* getEngineHeight();

    static SDL_Renderer *getRenderer();

private:
    bool isRunning;
    SDL_Window *window;
    static SDL_Renderer *renderer;
    int* engineWidth;
    int* engineHeight;
};

#endif //PROJECT2DTD_ENGINE_H
