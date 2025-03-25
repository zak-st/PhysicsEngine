#include "GameObject.h"
#include "InputManager.h"
#include <iostream>
#include <GLFW/glfw3.h>

GameObject::GameObject()
{
	physics = new PhysicsObject();
	sprite = nullptr;
}

GameObject::GameObject(float s_width, float s_height, Shader& shader, bool has_collider, const string& name) : name(name)
{
	physics = new PhysicsObject();
	sprite = new Sprite(s_width, s_height, shader);
	position = glm::vec2(0.0f, 0.0f);
	if (has_collider)
	{
		collider = new Collider(s_width, s_height);
	}
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
	physics->Update(dt);

	position = glm::vec2(physics->GetPosition().x, physics->GetPosition().y);
	if (collider)
	{
		collider->Update(position);
	}

}
void GameObject::Draw()
{
	if (!sprite) return;

	sprite->GetShader()->Use();

	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(position.x, position.y, 0.0f));

	glm::mat4 projection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
	sprite->GetShader()->SetMatrix4("model", model);
	sprite->GetShader()->SetMatrix4("projection", projection);

	sprite->Render();
}

PhysicsObject* GameObject::GetPhysics()
{
	return physics;
}
Sprite* GameObject::GetSprite()
{
	return sprite;
}
glm::vec2 GameObject::GetPosition()
{
	return position;
}

Collider* GameObject::GetCollider()
{
	return collider;
}

void GameObject::SetPhysics(PhysicsObject* other)
{
	physics = other;
}
void GameObject::SetSprite(Sprite* other)
{
	sprite = other;
}
void GameObject::SetPosition(glm::vec2& other)
{
	position = other;
}

void GameObject::SetCollider(Collider* other)
{
	collider = other;
}