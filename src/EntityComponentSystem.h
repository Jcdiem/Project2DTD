#ifndef PROJECT2DTD_ENTITYCOMPONENTSYSTEM_H
#define PROJECT2DTD_ENTITYCOMPONENTSYSTEM_H
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

// Design pattern by Vittorio Romeo
// https://vittorioromeo.info/

class Component;
class Entity;

using ComponentID = std::size_t;

//Gives out an incrementing ID For each time ran
inline ComponentID getComponentTypeId(){
    static ComponentID  lastID = 0; //Store the last ID
    return lastID++; //Give out the next ID
}

template <typename type> inline ComponentID getComponentTypeId() noexcept{
    static ComponentID typeID = getComponentTypeId(); //Get an ID from the ticketing system
    return typeID;
}

constexpr std::size_t maxComponents = 32; //Max classes an entity can have

using componentBitSet = std::bitset<maxComponents>; //Sets the bitmask for components
using componentArray = std::array<Component*,maxComponents>; //Array of pointers for components





//interface for Component
class Component{
public:
    Entity* entity;

    virtual void init(){}
    virtual void update(){}
    virtual void draw(){}

    virtual ~Component(){}

private:
};






//Entity interface
class Entity{
public:
    void update(){
        //iterate through all the components and tell them to draw/update
        for (auto& component : componentList) component->update();
        for (auto& component : componentList) component->draw();
    }
    void draw(){}
    bool isActive() const {
        return active;
    }
    void destroy(){
        active = false;
    }

    template<typename type> bool hasComponent() const{
        return compBitSet[getComponentTypeId < type >]; //Return : Does entity have type component?
    }

    template <typename type, typename... TypeArgs> //Follows to next line
    type& addComponent(TypeArgs&&... mArgs){
        type* component( //Make a component type
                new type(std::forward<TypeArgs>(mArgs)...) //Give it arguments
        );
        component->entity = this; //Set the components entity to this instance of an entity
        std::unique_ptr<Component> uniquePtr{component}; //Make a pointer for component
        componentList.emplace_back(std::move(uniquePtr));//Push the component to the back of the list of components

        compArray[getComponentTypeId<type>()] = component; //Add component to array of related components
        compBitSet[getComponentTypeId<type>()] = true; //Set the bit for this component being used with the entity (For masking)

        component->init();
        return *component;
    }

    template<typename type> type& getComponent() const{
        auto ptr(compArray[getComponentTypeId<type>()]); //Get the pointer of component in array
        return *static_cast<type*>(ptr); //return pointer of component
    }

private:
    bool active;
    std::vector<std::unique_ptr<Component>> componentList;

    componentArray compArray;
    componentBitSet compBitSet;

};

class Manager{
public:
    void update(){
        for (auto& entity : entityList) entity->update();
    }
    void draw(){
        for (auto& entity : entityList) entity->draw();
    }

    void refresh(){ //Delete inactive entities
        entityList.erase(std::remove_if(std::begin(entityList),std::end(entityList),
                                        [](const std::unique_ptr<Entity> &mEntity){
            return !mEntity->isActive();
        }),
               std::end(entityList));
    }

    Entity& addEntity(){
        Entity* entityPtr = new Entity();
        std::unique_ptr<Entity> uniquePtr(entityPtr);
        entityList.emplace_back(std::move(uniquePtr));
        return *entityPtr;
    }

private:
    std::vector<std::unique_ptr<Entity>> entityList; //List of entity pointers

};

#endif //PROJECT2DTD_ENTITYCOMPONENTSYSTEM_H