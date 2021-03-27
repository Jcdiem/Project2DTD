#pragma once
#ifndef BUILD_AUDIOHANDLER_H
#define BUILD_AUDIOHANDLER_H

#include <map>
#include <iostream>

#include "SDL.h"
#include "SDL_mixer.h"

class AudioHandler {
public:
    static void loadSFX(const std::string& name, const std::string& path);
    static void loadMUS(const std::string& name, const std::string& path);

    static int playSFX(const std::string& name);
    static int playSFX(const std::string& name, int loops);
    static int playSFX(const std::string& name, int loops, int channel);
    static void playMUS(const std::string& name);
    static void playMUS(const std::string& name, int fadeTime);

    static void freeSFX(const std::string& name);
    static void freeMUS(const std::string& name);

    static void haltSFX(int channel);
    static void haltMUS();

    static void resumeSFX(int channel);
    static void resumeMUS();

    static bool playingSFX(int channel);
    static bool playingMUS();

    static void cleanup();
private:
    static std::map<std::string, Mix_Chunk*> SFXLibrary;
    static std::map<std::string, Mix_Music*> MUSLibrary;
};


#endif //BUILD_AUDIOHANDLER_H
