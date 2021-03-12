#include "Engine.h"

Engine::Engine() = default;

Engine::~Engine() = default;

//Globals (SHOULD ALL BE PRIVATE)
Canvas *Engine::gameCanvas = nullptr;
SDL_Renderer *Engine::renderer = nullptr;
int *Engine::engineHeight = nullptr;
int *Engine::engineWidth = nullptr;

void Engine::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen, bool resizable, bool multithread) {
    int flags = 0;
    if (fullscreen) {
        flags += SDL_WINDOW_FULLSCREEN;
    }
    if (resizable) {
        flags += SDL_WINDOW_RESIZABLE;
    }

    this->multithread = multithread;

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "SDL Initialised" << std::endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window) {
            std::cout << "Window made properly" << std::endl;
        } else {
            std::throw_with_nested(std::runtime_error(std::string("SDL_CreateWindow failed: %s\n").append(SDL_GetError())));
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            TextureHandler::setRenderer(renderer);
            std::cout << "Renderer completed properly" << std::endl;
        } else {
            std::throw_with_nested(std::runtime_error(std::string("SDL_CreateRenderer failed: %s\n").append(SDL_GetError())));
        }

        isRunning = true;
    } else {
        std::throw_with_nested(std::runtime_error(std::string("SDL_Init failed: %s\n").append(SDL_GetError())));
    }

    SDL_GetWindowSize(window, engineWidth, engineHeight);

    manager.setWW(width);
    manager.setWH(height);

    try {
        levelList = ObjectBuilder::genLevelList();
    }
    catch(...) {
        std::throw_with_nested(std::runtime_error("Level list generation failed."));
    }

    //TODO: Get entities from file
    gameCanvas = new Canvas();

    ObjectBuilder::genObjs(&manager, levelList[0]);
}


void Engine::handleEvents() {
    SDL_PumpEvents();
}

void Engine::update() {
    manager.refresh();

    if(multithread) {
        manager.multithreaded_update();
    } else {
        manager.update();
    }
}

void Engine::render() {
    SDL_RenderClear(renderer);

    //WE ARE USING PAINTERS; FIRST ON LIST IS FIRST TO BE DRAWN, NEXT ON LIST IS DRAWN OVER TOP
    // (Background first, foreground last)
    gameCanvas->draw();
    manager.draw();


    //End rendering
    SDL_RenderPresent(renderer);
}

void Engine::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    printf("Shutdown complete");
}

void Engine::quit() {
    isRunning = false;
}

SDL_Renderer *Engine::getRenderer() {
    return renderer;
}
