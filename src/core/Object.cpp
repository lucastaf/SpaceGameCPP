#include "Object.hpp"
#include "ObjectManager.hpp"
#include <raylib.h>

// Definitions for Object declared in Object.hpp
Object::~Object() {}

void Object::onStep() {}

void Object::render() {}

void Object::destroy()
{
    ObjectsManager::deleteObject(this);
}

bool Object::isOutofScreen()
{
    int width = GetScreenWidth();
    if (position.x < 0 || position.x > width)
    {
        return true;
    }
    int height = GetScreenHeight();
    if (position.y < 0 || position.y > height)
    {
        return true;
    }
    return false;
}