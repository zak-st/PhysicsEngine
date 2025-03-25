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

	const vector<GameObject*>& GetObjects() const { return object_list; };

	void AddObject(GameObject* new_object);
	void Update(float dt);
	void DrawObjects(Shader& debugShader);
	bool CheckCollision(GameObject* obj1, GameObject* obj2);

private:
	vector<GameObject*> object_list;
	Vector global_gravity;
};