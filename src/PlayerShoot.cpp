#include "PlayerShoot.hpp"
#include "core/Object.hpp"
#include <iostream>


PlayerShoot::PlayerShoot(Vector2 position, float direction)
{
	this->position = position;
	this->direction = direction;
}

void PlayerShoot::onStep()
{
	position.x += cos(direction) * 5;
	position.y += sin(direction) * 5;
	if (isOutofScreen()) {
		destroy();
	}
}

void PlayerShoot::render()
{
	DrawCircle(position.x, position.y, 4, RED);
}
