#pragma once
#include <raylib.h>

class Object
{
public:
    virtual ~Object();
    virtual void onStep();
    virtual void render();

    void destroy();

    bool isOutofScreen();

protected:
    Vector2 position;
};