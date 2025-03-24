#pragma once
#include "GameObject.h"
class Player : public GameObject
{
public:
	Player(float width, float height, Shader& shader);
	~Player();

	void Update(float dt) override;
};