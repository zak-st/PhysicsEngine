#pragma once
#include "Matrix.h"
#include "Vector.h"


class PhysicsObject
{
public:
	PhysicsObject();
	~PhysicsObject();

	void ApplyForce(const Vector& force);
	void Update(float dt)
	{
		//temp implementation
		return;
	}

private:
	Vector position, velocity, acceleration;
	float mass;
};