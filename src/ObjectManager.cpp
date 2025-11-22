#include <vector>
#include <algorithm>
#include "ObjectManager.hpp"
#include "Object.hpp"

// Forward declaration to ensure 'Object' is known for pointer declarations
// (helps when there are circular includes or ordering issues)

class ObjectsManager
{
private:
    ObjectsManager() {}
    std::vector<Object *> activeObjects;
    static ObjectsManager *instance;

public:
    static ObjectsManager *getInstance()
    {
        if (ObjectsManager::instance == nullptr)
        {
            ObjectsManager::instance = new ObjectsManager();
        }
        return ObjectsManager::instance;
    }
    std::vector<Object *> *getActiveObjects()
    {
        return &this->activeObjects;
    }

    static void addObject(Object *obj)
    {
        ObjectsManager *manager = ObjectsManager::getInstance();
        manager->activeObjects.push_back(obj);
    }

    // Declaration only. Implementation provided in ObjectManager.cpp
    static void deleteObject(Object* obj)
    {
        ObjectsManager *manager = ObjectsManager::getInstance();
        auto &activeObjects = manager->activeObjects;

        activeObjects.erase(
            std::remove(activeObjects.begin(), activeObjects.end(), obj),
            activeObjects.end());
        delete obj;
    }
};