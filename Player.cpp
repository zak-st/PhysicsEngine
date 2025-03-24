#include "Player.h"
#include "GameObject.h"
#include "InputManager.h"
#include <iostream>
#include <GLFW/glfw3.h>
Player::Player(float width, float height, Shader& shader) : GameObject(width, height, shader)
{

}
Player::~Player()
{

}

void Player::Update(float dt)
{
    GetPhysics()->Update(dt);

    if (InputManager::IsKeyPressed(GLFW_KEY_A)) {
        GetPhysics()->ApplyForce(Vector(-5.0f, 0.0f));
    }
    if (InputManager::IsKeyPressed(GLFW_KEY_D)) {
        GetPhysics()->ApplyForce(Vector(5.0f, 0.0f));
    }
    glm::vec2 new_pos(GetPhysics()->GetPosition().x, GetPhysics()->GetPosition().y);
    SetPosition(new_pos);
}