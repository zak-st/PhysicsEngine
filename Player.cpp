#include "Player.h"
#include "GameObject.h"
#include "InputManager.h"
#include <iostream>
#include <GLFW/glfw3.h>
Player::Player(float width, float height, Shader& shader, bool collider, const string& name) : GameObject(width, height, shader, true, name)
{

}
Player::~Player()
{

}

void Player::Update(float dt)
{
    GameObject::Update(dt);

    // Then handle input
    if (InputManager::IsKeyPressed(GLFW_KEY_A)) {
        GetPhysics()->ApplyForce(Vector(-5.0f, 0.0f));
    }
    if (InputManager::IsKeyPressed(GLFW_KEY_D)) {
        GetPhysics()->ApplyForce(Vector(5.0f, 0.0f));
    }
}