#include <vector>
#include <algorithm>
#include "ObjectManager.hpp"
#include "Object.hpp"
#include <iostream>

// Define the static instance
ObjectsManager* ObjectsManager::instance = nullptr;

ObjectsManager* ObjectsManager::getInstance()
{
    if (ObjectsManager::instance == nullptr)
    {
        ObjectsManager::instance = new ObjectsManager();
    }
    return ObjectsManager::instance;
}

std::vector<Object *>* ObjectsManager::getActiveObjects()
{
    return &this->activeObjects;
}

void ObjectsManager::handleObjectsInstances()
{
    for (auto obj : this->removedObjects)
    {
        delete obj;
    }
	this->removedObjects.clear();
    for(auto obj : this->toBeAddedObjects)
    {
        this->activeObjects.push_back(obj);
	}
	this->toBeAddedObjects.clear();
}

void ObjectsManager::addObject(Object *obj)
{
    ObjectsManager *manager = ObjectsManager::getInstance();
     manager->toBeAddedObjects.push_back(obj);
}

void ObjectsManager::deleteObject(Object* obj)
{
    ObjectsManager *manager = ObjectsManager::getInstance();
    auto &activeObjects = manager->activeObjects;

    activeObjects.erase(
        std::remove(activeObjects.begin(), activeObjects.end(), obj),
        activeObjects.end());

    manager->removedObjects.push_back(obj);
}