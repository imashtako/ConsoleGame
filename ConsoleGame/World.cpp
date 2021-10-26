#include "World.h"

void World::AddObject(GameObject* obj)
{
	objects.push_back(obj);
}

const std::vector<GameObject*> World::GetObjects()
{
	return objects;
}
