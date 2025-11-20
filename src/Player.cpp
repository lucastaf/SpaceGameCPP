#include "PhysicsObject2D.cpp"
#include <iostream>

class Player : public PhysicsObject2D
{
private:
   float force = 0.21f;

public:
   Player(float drag) : PhysicsObject2D(drag) {}
   void onStep() override
   {
      PhysicsObject2D::onStep();
      if (IsKeyDown(KEY_RIGHT))
         this->addForce(force, 0);
      if (IsKeyDown(KEY_LEFT))
         this->addForce(-force, 0);
      if (IsKeyDown(KEY_UP))
         this->addForce(0, -force);
      if (IsKeyDown(KEY_DOWN))
         this->addForce(0, force);

#ifdef DEBUG
      if (IsKeyDown(KEY_A))
         this->addDrag(-0.001f);
      if (IsKeyDown(KEY_S))
         this->addDrag(0.001f);

      if (IsKeyDown(KEY_Z))
         this->addForceToMovement(-0.001f);
      if (IsKeyDown(KEY_X))
         this->addForceToMovement(0.001f);
#endif
   }

   void addForceToMovement(float force)
   {
      this->force += force;
   }
};