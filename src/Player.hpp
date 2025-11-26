#pragma once
#include "PhysicsObject2D.hpp"
#include <array>
#include "raylib.h"

class Player : public PhysicsObject2D
{
private:
    float force = 0.21f;

public:
    Player(float drag);
    void onStep() override;
    void render() override;
    void addForceToMovement(float force);

};