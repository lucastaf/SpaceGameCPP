#include "core/Object.hpp"
#include <iostream>

class PlayerShoot : public Object
{
private:
    float direction;

public:
    PlayerShoot(Vector2 position, float direction)
    {
        this->position = position;
        this->direction = direction;
    }

    void onStep() override
    {
        position.x += cos(direction) * 5;
        position.y += sin(direction) * 5;
        if(isOutofScreen()){
            destroy();
        }
    }

    void render() override
    {
        DrawCircle(position.x, position.y, 4, RED);
    }
};