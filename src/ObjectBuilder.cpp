#include "ObjectBuilder.h"

#include <utility>

std::vector<std::string> ObjectBuilder::genLevelList() {
    std::vector<std::string> levelList;
    nlohmann::json file;

    try {
        file = nlohmann::json::parse(std::fstream("assets/levels/levelList.json"), nullptr, true, true)["levels"];
    }
    catch(nlohmann::json::exception &e) {
        std::throw_with_nested(std::runtime_error("Level list could not be found or it was improperly formatted."));
    }

    for (auto level = file.begin(); level != file.end(); ++level)
    {
        try{
            levelList.emplace_back(std::string(level.value()));
        }
        catch(...) {
            std::cout << "Failed to get object path, does it exist?" << std::endl;
        }
    }

    return levelList;
}

void ObjectBuilder::genLevel(Manager* man, std::string levelPath) {
    nlohmann::json file;
    try {
        file = nlohmann::json::parse(std::fstream(levelPath), nullptr, true, true);
    } catch(nlohmann::json::exception &e) {
        std::throw_with_nested(std::runtime_error("Level file could not be found or it was improperly formatted."));
    }

    nlohmann::json objects = file["objects"];
    nlohmann::json sfx = file["sfx"];
    nlohmann::json music = file["music"];

    for(auto sf = sfx.begin(); sf != sfx.end(); ++sf){
        AudioHandler::loadSFX(sf.key(), sf.value());
    }

    for(auto mus = music.begin(); mus != music.end(); ++mus){
        AudioHandler::loadMUS(mus.key(), mus.value());
    }

    //Sounds come first so they can be accessed by init scripts

    for(auto obj = objects.begin(); obj != objects.end(); ++obj){
        recurseChildren(man, obj, nullptr);
    }
}

Entity* ObjectBuilder::recurseChildren(Manager* man, auto root, Entity* parent) {
    try {
        Entity* entity = objFromJson(man, root.value()["self"], root.key(), parent);

        if(root->contains("values")) {
            for (auto val = root.value()["values"].begin(); val != root.value()["values"].end(); ++val) {
                DataComponent* data = &entity->getComponent<DataComponent>();
                if(val.key() == "x")
                    data->x = val.value();
                else if(val.key() == "y")
                    data->y = val.value();
                else if(val.key() == "w")
                    data->w = val.value();
                else if(val.key() == "h")
                    data->h = val.value();
                else if(val.key() == "rotX")
                    data->rotX = val.value();
                else if(val.key() == "rotY")
                    data->rotY = val.value();
                else if(val.key() == "rot")
                    data->rot = val.value();
                else if(val.key() == "vflip")
                    data->vflip = val.value();
                else if(val.key() == "hflip")
                    data->hflip = val.value();
                else if(val.key() == "hidden")
                    data->hidden = val.value();
            }
        }

        if(root->contains("children")) {
            for (auto child = root.value()["children"].begin(); child != root.value()["children"].end(); ++child) {
                try {
                    auto childEntity = recurseChildren(man, child, entity);
                    entity->addChild(childEntity);
                } catch(...) {
                    std::cout << "Failed to create child of object: " << root.key() << std::endl;
                }
            }
        }

        try{
            entity->init();
        } catch(...) {
            std::cout << "During initialization of object " << entity->getName() << " an error occured." << std::endl;
        }

        return entity;
    }
    catch(...) {
        std::cout << "Failed to create object from " << root.value() << ", either object is malformed or does not exist." << std::endl;
    }

    return nullptr;
}

Entity* ObjectBuilder::objFromJson(Manager* man, std::string path, std::string name, Entity* parent) {
    auto& curObj = man->addEntity();

    curObj.setName(std::move(name));

    if(parent) {
        curObj.setParent(parent);
    }

    nlohmann::json file;

    try {
        file = nlohmann::json::parse(std::fstream(path), nullptr, true, true).front();
    }
    catch(nlohmann::json::exception &e) {
        std::throw_with_nested(std::runtime_error(path.append(" could not be found...")));
    }

    nlohmann::json components = file["components"];
    nlohmann::json values = file["values"];

    curObj.addComponent<DataComponent>();

    for(auto component = components.begin(); component != components.end(); ++component)
    {
        if(component.key() == "ScriptComponent") {
            auto scriptPath = component.value()["path"].get<std::string>();
            curObj.addComponent<ScriptComponent>(scriptPath);
        }
        if(component.key() == "SpriteComponent") {
            std::vector<animToolkit::animation*> animArray;
            for(auto anim = component->begin(); anim != component->end(); anim++) {
                auto* curAnim = new animToolkit::animation;

                //Req'd properties
                curAnim->addByPath(anim.value()["path"].get<std::string>());
                curAnim->width = anim.value()["width"].get<int>();
                curAnim->height = anim.value()["height"].get<int>();


                //Optional properties
                if(anim.value().contains("frames")) {
                    curAnim->frames = anim.value()["frames"].get<int>();
                } else {
                    curAnim->frames = 1;
                }
                if(anim.value().contains("framerate")) {
                    curAnim->framerate = anim.value()["framerate"].get<int>();
                } else {
                    curAnim->framerate = 1;
                }
                if(anim.value().contains("dwidth")) {
                    curAnim->dwidth = anim.value()["dwidth"].get<int>();
                } else {
                    curAnim->dwidth = curAnim->width;
                }
                if(anim.value().contains("dheight")) {
                    curAnim->dheight = anim.value()["dheight"].get<int>();
                } else {
                    curAnim->dheight = curAnim->height;
                }

                animArray.emplace_back(curAnim);
            }
            curObj.addComponent<SpriteComponent>(animArray);
        }
    }

    return &curObj;
}