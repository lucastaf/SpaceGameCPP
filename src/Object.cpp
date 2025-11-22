#include <iostream>
#include "utils.cpp"
#include "ObjectManager.hpp"
#include "Object.hpp"

class Object
{
public:
    virtual ~Object() {}
    virtual void onStep() {};
    virtual void render() {};

    void destroy()
    {
        ObjectsManager::deleteObject(this);
    }

    bool isOutofScreen()
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

protected:
    Vector2 position;
};