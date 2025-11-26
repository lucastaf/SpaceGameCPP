#include "PhysicsObject2D.hpp"
#include "core/Object.hpp"
#include "raylib.h"
#include <iostream>
#include "math.h"



PhysicsObject2D::PhysicsObject2D(float drag)
{
	this->drag = drag;
	this->rotation = 0.0f;
	this->velocity = { 0.0f, 0.0f };
}


void PhysicsObject2D::setPosition(Vector2 position)
{
	this->position = position;
}


void PhysicsObject2D::addForce(Vector2 delta)
{
	this->velocity.x += delta.x;
	this->velocity.y += delta.y;
}

void PhysicsObject2D::addForce(float x, float y)
{
	this->velocity.x += x;
	this->velocity.y += y;
}

Vector2 PhysicsObject2D::getPosition()
{
	return this->position;
}

void PhysicsObject2D::addDrag(float drag)
{
	this->drag += drag;
}

void PhysicsObject2D::handleDrag()
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

void PhysicsObject2D::onStep()
{
	this->position.x += this->velocity.x;
	this->position.y += this->velocity.y;
	handleDrag();
}
