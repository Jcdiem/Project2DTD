#pragma once
#ifndef P2D_LUAENGINE_H
#define P2D_LUAENGINE_H

#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>
#include <allegro5/allegro_audio.h>

#include "EntityWrapper.h"
#include "../AudioHandler.h"

class LuaEngine
{
public:
    LuaEngine();

    void initScript(const std::string& script);
    void runScript();

    sol::state* gLu();

    template<typename type>
    void newVar(std::string name, type value) {
        lua[name] = value;
    }

private:
    sol::state lua;
};


#endif //P2D_LUAENGINE_H
