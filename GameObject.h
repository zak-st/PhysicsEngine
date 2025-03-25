#pragma once


#include "PhysicsObject.h"
#include "Sprite.h"
#include "Shader.h"
#include "Collider.h"

class GameObject
{
public:
	GameObject();
	GameObject(float s_width, float s_height, Shader& shader, bool has_collider, const string& name = "Unnamed");
	~GameObject();

	virtual void Update(float dt);
	void Draw();

	PhysicsObject* GetPhysics();
	Sprite* GetSprite();
	glm::vec2 GetPosition();
	Collider* GetCollider();
	string GetName() { return name; }

	void SetPhysics(PhysicsObject* other);
	void SetSprite(Sprite* other);
	void SetPosition(glm::vec2& other);
	void SetCollider(Collider* other);
	void SetName(const string& other) { name = other; }

private:
	PhysicsObject* physics;
	Sprite* sprite;
	Collider* collider;
	glm::vec2 position;
	string name;
};
