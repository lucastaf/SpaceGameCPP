#pragma once

#include <iostream>
#include "utils.h"

class Object
{
public:
    virtual ~Object() {}
    virtual void onStep();
    virtual void render();
};

// Provide a default implementation for the virtual method so the vtable
// and symbol are emitted at link time.
void Object::onStep()
{
    // default: do nothing
}

void Object::render()
{
}