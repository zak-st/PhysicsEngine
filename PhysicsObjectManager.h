#pragma once

#include <vector>

#include "Matrix.h"
#include "Vector.h"
#include "PhysicsObject.h"

class PhysicsObjectManager
{
public:
	PhysicsObjectManager();
	~PhysicsObjectManager();

	void AddObject(PhysicsObject* new_object);
	void Update(float dt);

private:
	vector<PhysicsObject*> object_list;
	Vector global_gravity;
};