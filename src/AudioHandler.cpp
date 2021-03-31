#include "AudioHandler.h"

int AudioHandler::init() {
    if(!al_install_audio()) {
        err = "Audio init failure";
        return 1;
    }

    if(!al_init_acodec_addon()) {
        err = "Codec init failure";
        return 1;
    }

    if(!al_reserve_samples(32)) {
        err = "Sample reserve failed";
        return 1;
    }654

    return 0;
}

void AudioHandler::kill() {
    for(auto & SFX : SFXLibrary) {
        al_destroy_sample(SFX.second);
    }
//    for(auto & mus : activeMUS) {
//        al_destroy_audio_stream(mus);
//    } Not needed now since only one can exist
    al_destroy_audio_stream(activeMUS);
    for(auto & sfxID : activeSFX) {
        delete sfxID;
    }
}

void AudioHandler::cleanDead() { //Remove dangling audio mus and sfx
//    for(auto sfxID = activeSFX.begin(); sfxID != activeSFX.end(); sfxID++) {
//        activeSFX.erase(sfxID);
//    }

//    for(auto mus = activeMUS.begin(); mus != activeMUS.end(); mus++) {
//        if(!*mus) {
//            activeMUS.erase(mus);
//        }
//    } Not needed now since only one can exist
}

std::string AudioHandler::what() {
    return err;
}

ALLEGRO_SAMPLE_ID* AudioHandler::playSFX(const std::string& name) {
    al_play_sample(SFXLibrary[name], 1.0, ALLEGRO_AUDIO_PAN_NONE, 1.0, ALLEGRO_PLAYMODE_ONCE, nullptr);
}

ALLEGRO_SAMPLE_ID* AudioHandler::playSFX(const std::string& name, float gain) {
    al_play_sample(SFXLibrary[name], gain, ALLEGRO_AUDIO_PAN_NONE, 1.0, ALLEGRO_PLAYMODE_ONCE, nullptr);
}

ALLEGRO_SAMPLE_ID* AudioHandler::playSFX(const std::string& name, float gain, float pan) {
    al_play_sample(SFXLibrary[name], gain, pan, 1.0, ALLEGRO_PLAYMODE_ONCE, nullptr);
}

void AudioHandler::haltSFX(ALLEGRO_SAMPLE_ID* sfxID) {
//    al_stop_sample(sfxID);
}

void AudioHandler::playMUS(const std::string& name) {
}

void AudioHandler::haltMUS() {
    al_destroy_audio_stream(activeMUS);
}

bool AudioHandler::playingMUS() {
    if(activeMUS) {
        return al_get_audio_stream_playing(activeMUS);
    }
    return false;
}

void AudioHandler::loadSFX(std::string name, std::string path) {
    SFXLibrary[name] = al_load_sample(path.c_str());
}

void AudioHandler::loadMUS(std::string name, std::string path) {
    MUSLibrary[name] = path;
}