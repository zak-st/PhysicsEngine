#pragma once


#include "PhysicsObject.h"
#include "Sprite.h"

class GameObject
{
public:
	GameObject();
	GameObject(float s_width, float s_height);
	~GameObject();

	void Update(float dt);
	void Draw();

	PhysicsObject* GetPhysics();
	Sprite* GetSprite();

private:
	PhysicsObject* physics;
	Sprite* sprite;
};
