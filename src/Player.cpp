#include "Player.hpp"
#include "PlayerShoot.hpp"
#include "utils.cpp"
#include "core/ObjectManager.hpp"
#include <iostream>

Player::Player(float drag) : PhysicsObject2D(drag)
{
	Vector2 centerPosition = { (float)GetScreenWidth() / 2.0f, (float)GetScreenHeight() / 2.0f };
	this->setPosition(centerPosition);
}

void Player::onStep()
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
	if (IsKeyPressed(KEY_SPACE)) {
   		PlayerShoot* playerShoot = new PlayerShoot(this->position, this->rotation);
		ObjectsManager::addObject(playerShoot);
	}
}

void Player::render()
{
	std::array<Vector2, 3> points = utils::getEquilateralTriangle(getPosition().x, getPosition().y, rotation, 25.0f, 1.7f);
	DrawTriangle(points[2], points[1], points[0], RED);
}

void Player::addForceToMovement(float force)
{
	this->force += force;
}
