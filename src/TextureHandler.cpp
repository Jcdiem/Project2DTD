#include "TextureHandler.h"

SDL_Renderer* TextureHandler::renderer = nullptr;

void TextureHandler::setRenderer(SDL_Renderer *ren) {
    renderer = ren;
}

SDL_Texture* TextureHandler::loadTexture(const std::string& filename) {
    SDL_Surface* tempSurface = IMG_Load(filename.c_str());

    //Detect error in image loading.
    if(!tempSurface) {
        std::cout << "IMG_Load: " << IMG_GetError() << std::endl;
        std::cout << "Loading fallback image" << std::endl;
        tempSurface = IMG_Load("assets/textures/null.png");
    }

    SDL_Texture* retTex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    return retTex;
}

void TextureHandler::Draw(SDL_Texture *texture, SDL_Rect src, SDL_Rect dest) {
    SDL_RenderCopy(renderer, texture, &src, &dest);
}

void TextureHandler::Draw(SDL_Texture *texture, SDL_Rect src, SDL_Rect dest, double angle) {
    SDL_RenderCopyEx(renderer, texture, &src, &dest, angle, NULL, SDL_FLIP_NONE);
}

void TextureHandler::Draw(SDL_Texture *texture, SDL_Rect src, SDL_Rect dest, double angle, SDL_RendererFlip flip) {
    SDL_RenderCopyEx(renderer, texture, &src, &dest, angle, NULL, flip);
}

void TextureHandler::Draw(SDL_Texture *texture, SDL_Rect src, SDL_Rect dest, double angle, SDL_Point center, SDL_RendererFlip flip) {
    SDL_RenderCopyEx(renderer, texture, &src, &dest, angle, &center, flip);
}