#include <iostream>

#include "PhysicsObjectManager.h"

using namespace std;

void PhysicsObjectManager::AddObject(PhysicsObject* new_object)
{
	if (new_object == nullptr)
	{
		cout << "Added Physics Object is NULL";
	}
	object_list.push_back(new_object);
}
void PhysicsObjectManager::Update(float dt)
{
	for (const auto object : object_list)
	{
		object->Update(dt);
	}
}