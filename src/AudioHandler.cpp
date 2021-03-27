#include "AudioHandler.h"

std::map<std::string, Mix_Chunk*> AudioHandler::SFXLibrary;
std::map<std::string, Mix_Music*> AudioHandler::MUSLibrary;

void AudioHandler::loadSFX(const std::string& name, const std::string& path) {
    SFXLibrary[name] = Mix_LoadWAV(path.c_str());
}

void AudioHandler::loadMUS(const std::string& name, const std::string& path) {
    MUSLibrary[name] = Mix_LoadMUS(path.c_str());
}

void AudioHandler::cleanup() {
    for (auto const& [key, val] : MUSLibrary) {
        Mix_FreeMusic(val);
        MUSLibrary.erase(key);
    }
    for (auto const& [key, val] : SFXLibrary) {
        Mix_FreeChunk(val);
        SFXLibrary.erase(key);
    }
}

int AudioHandler::playSFX(const std::string& name) {
    return Mix_PlayChannel(-1, SFXLibrary[name], 0);
}

int AudioHandler::playSFX(const std::string& name, int loops) {
    return Mix_PlayChannel(-1, SFXLibrary[name], loops - 1);
}

int AudioHandler::playSFX(const std::string& name, int loops, int channel) {
    return Mix_PlayChannel(channel, SFXLibrary[name], loops - 1);
}

void AudioHandler::freeSFX(const std::string& name) {
    Mix_FreeChunk(SFXLibrary[name]);
    SFXLibrary.erase(name);
}

void AudioHandler::haltSFX(int channel) {
    Mix_Pause(channel);
}

void AudioHandler::resumeSFX(int channel) {
    Mix_Resume(channel);
}

bool AudioHandler::playingSFX(int channel) {
    return Mix_Playing(channel);
}

void AudioHandler::playMUS(const std::string& name) {
    Mix_PlayMusic(MUSLibrary[name], -1);
}

void AudioHandler::playMUS(const std::string& name, int fadeTime) {
    if(Mix_PlayingMusic()) {
        Mix_FadeOutMusic(fadeTime);
    }
    Mix_FadeInMusic(MUSLibrary[name], -1, fadeTime);
}

void AudioHandler::freeMUS(const std::string& name) {
    Mix_FreeMusic(MUSLibrary[name]);
    MUSLibrary.erase(name);
}

void AudioHandler::haltMUS() {
    Mix_PauseMusic();
}

void AudioHandler::resumeMUS() {
    Mix_ResumeMusic();
}

bool AudioHandler::playingMUS() {
    return Mix_PlayingMusic();
}
