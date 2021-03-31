#pragma once
#ifndef P2D_AUDIOHANDLER_H
#define P2D_AUDIOHANDLER_H

#include <map>
#include <vector>
#include <string>

#include <iostream>

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

namespace AudioHandler {
    namespace {
        std::string err;
        std::map<std::string, ALLEGRO_SAMPLE*> SFXLibrary;
        std::map<std::string, std::string> MUSLibrary; //Music is streamed from the disk vs samples which stay loaded

        std::vector<ALLEGRO_SAMPLE_ID*> activeSFX;
        ALLEGRO_AUDIO_STREAM* activeMUS; //Currently one audio stream max, will be updated to allow for more so we can transition nice and good :)
    }

    //Core
    int init();
    void kill();
    void cleanDead();
    std::string what();
    //Core

    //Playback
    ALLEGRO_SAMPLE_ID* playSFX(const std::string& name);
    ALLEGRO_SAMPLE_ID* playSFX(const std::string& name, float gain);
    ALLEGRO_SAMPLE_ID* playSFX(const std::string& name, float gain, float pan);
    void haltSFX(ALLEGRO_SAMPLE_ID* sfxID);

    void playMUS(const std::string&);
    void haltMUS();
    bool playingMUS();
    //Playback

    //Loading + Unloading
    void loadSFX(std::string name, std::string path);
    void loadMUS(std::string name, std::string path);
    //Loading + Unloading
}


#endif //P2D_AUDIOHANDLER_H
