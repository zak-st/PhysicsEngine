#include "PhysicsObject.h"
#include <iostream>

PhysicsObject::PhysicsObject()
{
    mass = 1.0f;
}
PhysicsObject::~PhysicsObject()
{

}

void PhysicsObject::ApplyForce(const Vector& force)
{
    if (mass == 0)
    {
        return;
    }
    Vector new_acceleration(force.x / mass, force.y / mass, force.z / mass);
    acceleration = acceleration + new_acceleration;
}
void PhysicsObject::Update(float dt)
{
    if (dt == 0)
    {
        return;
    }
    velocity = velocity + (acceleration * dt);

    position = position + (velocity * dt);

    acceleration.Clear();

    std::cout << "Physics Position: (" << position.x << ", " << position.y
        << ") Velocity: (" << velocity.x << ", " << velocity.y << ")" << std::endl;
}

Vector PhysicsObject::GetPosition() const 
{
    return position;
}
Vector PhysicsObject::GetVelocity() const 
{
    return velocity;
}
float PhysicsObject::GetMass() const 
{
    return mass;
}

void PhysicsObject::SetPosition(const Vector& other)
{
    position = other;
}
void PhysicsObject::SetVelocity(const Vector& other)
{
    velocity = other;
}
void PhysicsObject::SetMass(const float other)
{
    mass = other;
}