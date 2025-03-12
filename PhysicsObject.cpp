#include "PhysicsObject.h"

PhysicsObject::PhysicsObject()
{

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
    acceleration.x += force.x / mass;
    acceleration.y += force.y / mass;
    acceleration.z += force.z / mass;
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