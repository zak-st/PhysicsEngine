#pragma once
#include "GameObject.h"
class Player : public GameObject
{
public:
	Player(float width, float height, Shader& shader, bool collider, const string& name = "Player");
	~Player();

	void Update(float dt) override;
};