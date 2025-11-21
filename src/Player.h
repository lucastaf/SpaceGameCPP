#pragma once

#include "PhysicsObject2D.h"
#include <iostream>

class Player : public PhysicsObject2D
{
private:
   float force = 0.21f;

public:
   Player(float drag) : PhysicsObject2D(drag)
   {
      Vector2 centerPosition = {(float)GetScreenWidth() / 2.0f, (float)GetScreenHeight() / 2.0f};
      this->setPosition(centerPosition);
   }

   void onStep() override
   {
      PhysicsObject2D::onStep();
      if (IsKeyDown(KEY_RIGHT))
         this->rotation += 0.03f;
      if (IsKeyDown(KEY_LEFT))
         this->rotation -= 0.03f;
      if (IsKeyDown(KEY_UP))
         this->addForce(cos(rotation) * force, sin(rotation) * force);
      if (IsKeyDown(KEY_DOWN))
         this->addForce(-cos(rotation) * force, -sin(rotation) * force);
   }

   void render() override
   {
      std::array<Vector2, 3> points = getEquilateralTriangle(getPosition().x, getPosition().y, rotation, 25.0f, 1.7f);
      DrawTriangle(points[2], points[1], points[0], RED);
   }

   void addForceToMovement(float force)
   {
      this->force += force;
   }
};