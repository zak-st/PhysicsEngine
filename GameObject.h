#pragma once


#include "PhysicsObject.h"
#include "Sprite.h"
#include "Shader.h"

class GameObject
{
public:
	GameObject();
	GameObject(float s_width, float s_height, Shader& shader);
	~GameObject();

	void Update(float dt);
	void Draw();

	PhysicsObject* GetPhysics();
	Sprite* GetSprite();

private:
	PhysicsObject* physics;
	Sprite* sprite;
	glm::vec2 position;
};
