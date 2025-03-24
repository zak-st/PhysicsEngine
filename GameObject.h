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

	virtual void Update(float dt);
	void Draw();

	PhysicsObject* GetPhysics();
	Sprite* GetSprite();
	glm::vec2 GetPosition();

	void SetPhysics(PhysicsObject* other);
	void SetSprite(Sprite* other);
	void SetPosition(glm::vec2& other);

private:
	PhysicsObject* physics;
	Sprite* sprite;
	glm::vec2 position;
};
