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
	//std::cout << "Updating GameObjects..." << std::endl;
	for (int i = 0; i < object_list.size(); i++)
	{
		for (int j = i + 1; j < object_list.size(); j++)
		{
			if (CheckCollision(object_list[i], object_list[j]))
			{
				cout << "Collision detected between object " << i << " and object " << j << endl;
			}
		}
	}
}

void GameObjectManager::DrawObjects(Shader& debugShader)
{
	for (auto object : object_list)
	{
		object->Draw();
	}
}

bool GameObjectManager::CheckCollision(GameObject* obj1, GameObject* obj2)
{
	if (obj1 == nullptr || obj2 == nullptr)
	{
		return false;
	}
	Collider* collider1 = obj1->GetCollider();
	Collider* collider2 = obj2->GetCollider();
	if (collider1 == nullptr || collider2 == nullptr)
	{
		return false;
	}
	return !(collider1->GetRight() < collider2->GetLeft() ||
		collider1->GetLeft() > collider2->GetRight() ||
		collider1->GetTop() < collider2->GetBottom() ||
		collider1->GetBottom() > collider2->GetTop());
}