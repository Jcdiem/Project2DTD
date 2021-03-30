#pragma once
#ifndef P2D_TEXTUREHANDLER_H
#define P2D_TEXTUREHANDLER_H

#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class TextureHandler {
public:
    static void setRenderer(SDL_Renderer* ren);
    static SDL_Texture* loadTexture(const std::string& filename);
    static void Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest);
    static void Draw(SDL_Texture *texture, SDL_Rect src, SDL_Rect dest, double angle);
    static void Draw(SDL_Texture *texture, SDL_Rect src, SDL_Rect dest, double angle, SDL_RendererFlip flip);
    static void Draw(SDL_Texture *texture, SDL_Rect src, SDL_Rect dest, double angle, SDL_Point center, SDL_RendererFlip flip);
private:
    static SDL_Renderer* renderer;
};


#endif //P2D_TEXTUREHANDLER_H
