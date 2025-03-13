#include "GameObject.h"
#include "InputManager.h"
#include <iostream>
#include <GLFW/glfw3.h>

GameObject::GameObject()
{
	physics = new PhysicsObject();
	sprite = nullptr;
}

GameObject::GameObject(float s_width, float s_height, Shader& shader)
{
	physics = new PhysicsObject();
	sprite = new Sprite(s_width, s_height, shader);
	position = glm::vec2(0.0f, 0.0f);
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

	//remove for override player class soon
	if (InputManager::IsKeyPressed(GLFW_KEY_A)) {
		physics->ApplyForce(Vector(-5.0f, 0.0f));
	}
	if (InputManager::IsKeyPressed(GLFW_KEY_D)) {
		physics->ApplyForce(Vector(5.0f, 0.0f));
	}

	position.x = physics->GetPosition().x;
	position.y = physics->GetPosition().y;

	std::cout << "GameObject Position: (" << position.x << ", " << position.y << ")" << std::endl;
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