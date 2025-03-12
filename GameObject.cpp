#include "GameObject.h"

GameObject::GameObject()
{
	physics = new PhysicsObject();
	sprite = nullptr;
}

GameObject::GameObject(float s_width, float s_height)
{
	physics = new PhysicsObject();
	sprite = new Sprite(s_width, s_height);
}
GameObject::~GameObject()
{
	delete physics;
	if (sprite)
	{
		delete sprite;
	}
}

void GameObject::Update(float dt)
{

}
void GameObject::Draw()
{

}

PhysicsObject* GameObject::GetPhysics()
{
	return physics;
}
Sprite* GameObject::GetSprite()
{
	return sprite;
}