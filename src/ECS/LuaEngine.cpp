#include "LuaEngine.h"

LuaEngine::LuaEngine() {
    lua.open_libraries(sol::lib::base);
    lua.open_libraries(sol::lib::math);

    sol::usertype<EntityWrapper> entity_data =
            lua.new_usertype<EntityWrapper>("entity", sol::no_constructor);

    //Data Variables
    entity_data["x"] = sol::property(&EntityWrapper::getX, &EntityWrapper::setX);
    entity_data["y"] = sol::property(&EntityWrapper::getY, &EntityWrapper::setY);
    entity_data["realX"] = sol::property(&EntityWrapper::getRealX);
    entity_data["realY"] = sol::property(&EntityWrapper::getRealY);
    entity_data["w"] = sol::property(&EntityWrapper::getW, &EntityWrapper::setW);
    entity_data["h"] = sol::property(&EntityWrapper::getH, &EntityWrapper::setH);
    entity_data["rot"] = sol::property(&EntityWrapper::getRot, &EntityWrapper::setRot);
    entity_data["rotX"] = sol::property(&EntityWrapper::getRotX, &EntityWrapper::setRotX);
    entity_data["rotY"] = sol::property(&EntityWrapper::getRotY, &EntityWrapper::setRotY);
    entity_data["vflip"] = sol::property(&EntityWrapper::getVFlip, &EntityWrapper::setVFlip);
    entity_data["hflip"] = sol::property(&EntityWrapper::getHFlip, &EntityWrapper::setHFlip);
    entity_data["hidden"] = sol::property(&EntityWrapper::getHidden, &EntityWrapper::setHidden);

    //Methods
    entity_data["resetRotPos"] = &EntityWrapper::resetRotPos;
    entity_data["playAnim"] = &EntityWrapper::playAnim;
    entity_data["addBinding"] = &EntityWrapper::addBinding;
    entity_data["isPressed"] = &EntityWrapper::isPressed;
    entity_data["refreshBindings"] = &EntityWrapper::refreshBindings;
    entity_data["kill"] = &EntityWrapper::kill;
    entity_data["getParent"] = &EntityWrapper::getParent;
    entity_data["setParent"] = &EntityWrapper::setParent;
    entity_data["getChildren"] = &EntityWrapper::getChildren;
    entity_data["addChild"] = &EntityWrapper::addChild;

    sol::usertype<AudioHandler> sound_manager =
            lua.new_usertype<AudioHandler>("sound_manager", sol::no_constructor);

    sound_manager["playSFX"] = sol::overload(
            sol::resolve<int(const std::string&)>(&AudioHandler::playSFX),
            sol::resolve<int(const std::string&, int)>(&AudioHandler::playSFX),
            sol::resolve<int(const std::string&, int, int)>(&AudioHandler::playSFX));
    sound_manager["playMUS"] = sol::overload(
            sol::resolve<void(const std::string&)>(&AudioHandler::playMUS),
            sol::resolve<void(const std::string&, int)>(&AudioHandler::playMUS));

    sound_manager["freeSFX"] = &AudioHandler::freeSFX;
    sound_manager["freeMUS"] = &AudioHandler::freeMUS;

    sound_manager["haltSFX"] = &AudioHandler::haltSFX;
    sound_manager["haltMUS"] = &AudioHandler::haltMUS;

    sound_manager["resumeSFX"] = &AudioHandler::resumeSFX;
    sound_manager["resumeMUS"] = &AudioHandler::resumeMUS;

    sound_manager["playingSFX"] = sol::property(&AudioHandler::playingSFX);
    sound_manager["playingMUS"] = sol::property(&AudioHandler::playingMUS);

}

void LuaEngine::initScript(const std::string& script) {
    lua.script(script, &sol::script_pass_on_error); //Just try your best buddy :(

    try {
        lua.script("init()", &sol::script_default_on_error);
    }
    catch (const sol::error &e) {
        std::cout << "An unexpected error has occurred:\n    " << e.what() << std::endl;
    }
}

void LuaEngine::runScript() {
    try {
        lua.script("main()", &sol::script_default_on_error);
    }
    catch (const sol::error &e) {
        std::cout << "an unexpected error has occurred:\n" << e.what() << std::endl;
    }
}

sol::state *LuaEngine::gLu() {
    return &lua;
}