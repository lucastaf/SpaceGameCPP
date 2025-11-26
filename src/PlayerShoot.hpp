#pragma once

#include "core/Object.hpp"
#include <iostream>

class PlayerShoot : public Object
{
private:
    float direction;

public:
    PlayerShoot(Vector2 position, float direction);

    void onStep() override;

    void render() override;

};