#pragma once

#include <vector>

#include "Matrix.h"
#include "Vector.h"
#include "PhysicsObject.h"
#include "GameObject.h"

class GameObjectManager
{
public:
	GameObjectManager();
	~GameObjectManager();

	void AddObject(GameObject* new_object);
	void Update(float dt);
	void DrawObjects();


private:
	vector<GameObject*> object_list;
	Vector global_gravity;
};