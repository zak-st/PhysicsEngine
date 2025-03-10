#pragma once
#include "Vector.h"
#include "Matrix.h"
#include "PhysicsObject.h"

class Physics
{
public:
	Physics();
	~Physics();

	Vector CalcVelocity(const Vector& vel, const Vector& acc, float dt);
	Vector CalcPosition(const Vector& vel, const Vector& pos, float dt);

private:

};

Physics::Physics()
{
}

Physics::~Physics()
{
}
