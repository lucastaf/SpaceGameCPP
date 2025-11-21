#pragma once

#include "Object.h"
#include <vector>
#include <algorithm>

class ObjectsManager
{
private:
    ObjectsManager() {}
    std::vector<Object *> activeObjects;
    static ObjectsManager *instance;

public:
    static ObjectsManager *getInstance()
    {
        if (ObjectsManager::instance == NULL)
        {
            ObjectsManager::instance = new ObjectsManager();
        }
        return ObjectsManager::instance;
    }
    auto getActiveObjects()
    {
        return this->activeObjects;
    }

    static void addObject(Object *obj)
    {
        ObjectsManager *manager = ObjectsManager::getInstance();
        manager->activeObjects.push_back(obj);
    }

    static void deleteObject(Object *obj)
    {
        ObjectsManager *manager = ObjectsManager::getInstance();
        auto &activeObjects = manager->activeObjects;

        activeObjects.erase(
            std::remove(activeObjects.begin(), activeObjects.end(), obj),
            activeObjects.end());
        delete obj;
    }
};

ObjectsManager *ObjectsManager::instance = nullptr;