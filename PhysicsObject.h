#pragma once
#include "Matrix.h"
#include "Vector.h"
#include "Sprite.h"


class PhysicsObject
{
public:
	PhysicsObject();

	~PhysicsObject();

	void ApplyForce(const Vector& force);
	void Update(float dt);

	Vector GetPosition() const;
	Vector GetVelocity() const;
	float GetMass() const;

	void SetPosition(const Vector& other);
	void SetVelocity(const Vector& other);
	void SetMass(const float other);



private:
	Vector position;
	Vector velocity;
	Vector acceleration;
	float mass;

	Sprite* sprite;
};