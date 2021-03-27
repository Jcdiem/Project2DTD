#include "Engine.h"

Engine::Engine() = default;

Engine::~Engine() = default;

//Globals (SHOULD ALL BE PRIVATE)
Canvas *Engine::gameCanvas = nullptr;
SDL_Renderer *Engine::renderer = nullptr;
int *Engine::engineHeight = nullptr;
int *Engine::engineWidth = nullptr;

void Engine::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen, bool resizable, int threads) {
    int flags = 0;
    if (fullscreen) {
        flags += SDL_WINDOW_FULLSCREEN;
    }
    if (resizable) {
        flags += SDL_WINDOW_RESIZABLE;
    }
    if(threads > 1) {
        multithread = true;
    }

    this->threads = threads;

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "SDL Initialised" << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window) {
            std::cout << "Window initialized" << std::endl;
        } else {
            std::throw_with_nested(std::runtime_error(std::string("SDL_CreateWindow failed: %s\n").append(SDL_GetError())));
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
            TextureHandler::setRenderer(renderer);
            std::cout << "Renderer initialized" << std::endl;
        } else {
            std::throw_with_nested(std::runtime_error(std::string("SDL_CreateRenderer failed: %s\n").append(SDL_GetError())));
        }

        if(Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) != -1 ) {
            std::cout << "Audio system initialized" << std::endl;
        } else {
            std::throw_with_nested(std::runtime_error(std::string("Mixer init failed failed: %s\n").append(SDL_GetError())));
        }

        isRunning = true;
    } else {
        std::throw_with_nested(std::runtime_error(std::string("SDL_Init failed: %s\n").append(SDL_GetError())));
    }

    SDL_GetWindowSize(window, engineWidth, engineHeight);

    manager.setWW(width);
    manager.setWH(height);

    std::cout << "Generating level list" << std::endl;
    try {
        levelList = ObjectBuilder::genLevelList();
    }
    catch(...) {
        std::throw_with_nested(std::runtime_error("Level list generation failed."));
    }

    //TODO: Get entities from file
    std::cout << "Initializing tilemap canvas" << std::endl;
    gameCanvas = new Canvas();

    std::cout << "Generating objects for startup level" << std::endl;
    ObjectBuilder::genLevel(&manager, levelList[0]);


    std::cout << "--- Startup Complete ---" << std::endl;
}


void Engine::handleEvents() {
    SDL_PumpEvents();
}

void Engine::update() {
    manager.refresh();

    if(multithread) {
        manager.multithreaded_update(threads);
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
    std::cout << "--- Shutdown Initiated ---" << std::endl;
    SDL_DestroyWindow(window);
    std::cout << "Killed window" << std::endl;
    SDL_DestroyRenderer(renderer);
    std::cout << "Killed renderer" << std::endl;
    AudioHandler::cleanup();
    std::cout << "Cleaned up Sounds" << std::endl;

    Mix_Quit();
    IMG_Quit();
    SDL_Quit();

    std::cout << "Shutdown complete" << std::endl;
}

void Engine::quit() {
    isRunning = false;
}

SDL_Renderer *Engine::getRenderer() {
    return renderer;
}
