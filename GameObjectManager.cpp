#include <iostream>

#include "GameObjectManager.h"

using namespace std;

GameObjectManager::GameObjectManager()
{

}

GameObjectManager::~GameObjectManager()
{
	for (auto object : object_list)
	{
		delete object;
	}
}

void GameObjectManager::AddObject(GameObject* new_object)
{
	if (new_object == nullptr)
	{
		cout << "Added Game Object is NULL";
	}
	object_list.push_back(new_object);
}
void GameObjectManager::Update(float dt)
{
	for (auto object : object_list)
	{
		object->Update(dt);
	}
	std::cout << "Updating GameObjects..." << std::endl;
}

void GameObjectManager::DrawObjects()
{
	for (auto object : object_list)
	{
		object->Draw();
	}
}