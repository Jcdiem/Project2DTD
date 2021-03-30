#pragma once
#ifndef P2D_POSITIONCOMPONENT_H
#define P2D_POSITIONCOMPONENT_H

#include <string>
#include <fstream>
#include <streambuf>
#include <utility>

#include "../EntityComponentSystem.h"
#include "../EntityWrapper.h"
#include "../LuaEngine.h"
#include "../Components.h"

class ScriptComponent : public Component {
public:
    explicit ScriptComponent(const std::string &path) {
        this->path = path;

        std::ifstream t(path);

        //Finding the end of file
        t.seekg(0, std::ios::end);
        script.reserve(t.tellg());
        t.seekg(0, std::ios::beg);
        //Finding the end of file

        script.assign((std::istreambuf_iterator<char>(t)),
                      std::istreambuf_iterator<char>());
    }

    void init() override {
        self = EntityWrapper(entity);
        if (entity->getParent())
            lua.newVar<EntityWrapper>("parent", self.getParent());
        lua.newVar("children", self.getChildren());

        lua.newVar("EW", self.getMan()->getWW());
        lua.newVar("EH", self.getMan()->getWH());
        lua.newVar<EntityWrapper>("self", self);
        lua.gLu()->set_function("search", &ScriptComponent::search, this);

        lua.initScript(script);
    }

    void update() override {
        //Update family before running script
        if (entity->getParent()) {
            lua.newVar<EntityWrapper>("parent", self.getParent());
        }
        lua.newVar("children", self.getChildren());

        lua.runScript();
    }

    std::vector<EntityWrapper> search(std::string name) {
        std::vector<EntityWrapper> result;
        for(Entity* entity : self.getMan()->search(std::move(name))) {
            result.emplace_back(entity);
        }
        return result;
    }

private:
    EntityWrapper self;
    EntityWrapper parent;

    std::string path;

    LuaEngine lua;
    std::string script;
};


#endif //P2D_POSITIONCOMPONENT_H
