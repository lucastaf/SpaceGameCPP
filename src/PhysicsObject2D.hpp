#include "core/Object.hpp"
#include "raylib.h"
#include <iostream>
#include "math.h"

class PhysicsObject2D : public Object
{
protected:
    float rotation;

    void setPosition(Vector2 position);

public:
    PhysicsObject2D(float drag);

    void onStep() override;

    void addForce(Vector2 delta);

    void addForce(float x, float y);

    Vector2 getPosition();

    void addDrag(float drag);
}