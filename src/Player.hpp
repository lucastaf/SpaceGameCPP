#pragma once

#include "PhysicsObject2D.hpp"

class Player : public PhysicsObject2D
{
public:
   Player(float drag);

   void addForceToMovement(float force);
};