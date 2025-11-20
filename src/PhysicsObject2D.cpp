#include "Object.cpp"
#include "raylib.h"
#include <iostream>
#include "math.h"

class PhysicsObject2D : public Object
{
private:
   Vector2 position;
   Vector2 velocity;
   float drag;

public:
   PhysicsObject2D(float drag)
   {
      this->drag = drag;
   }

   void onStep() override
   {
      this->position.x += this->velocity.x;
      this->position.y += this->velocity.y;
      std::cout << this->drag << " " << this->velocity.x << "\n";
      handleDrag();
   }

   void addForce(Vector2 delta)
   {
      this->velocity.x += delta.x;
      this->velocity.y += delta.y;
   }

   void addForce(float x, float y)
   {
      this->velocity.x += x;
      this->velocity.y += y;
   }

   Vector2 getPosition()
   {
      return this->position;
   }

   void addDrag(float drag){
      this->drag += drag;
   }

private:
   void handleDrag()
   {
      if (abs(this->velocity.x) > 0.01f)
      {
         this->velocity.x *= drag;
      }
      else
         this->velocity.x = 0;

      if (abs(this->velocity.y) > 0.01f)
      {
         this->velocity.y *= drag;
      }
      else
         this->velocity.y = 0;
   }
};