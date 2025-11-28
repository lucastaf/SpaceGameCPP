#pragma once

#include <vector>
#include "Object.hpp"

class ObjectsManager
{
private:
    ObjectsManager() {}
    std::vector<Object *> activeObjects;
	std::vector<Object*> toBeAddedObjects;
	std::vector<Object*> removedObjects;
    static ObjectsManager *instance;

public:
    static ObjectsManager *getInstance();
    std::vector<Object *> *getActiveObjects();
	void handleObjectsInstances();

    static void addObject(Object *obj);

    // Declaration only. Implementation provided in ObjectManager.cpp
    static void deleteObject(Object* obj);
};