#include "World.h"


using namespace std;

void World::AddObject(GameObject* obj)
{
	obj->SetWorld(this);
	objects.push_back(obj);
}

const std::vector<GameObject*> World::GetObjects()
{
	return objects;
}

void World::Update()
{
	vector<GameObject*> objects_copy = objects;
	for (GameObject* obj : objects_copy) {
		obj->Update();
	}
}

GameObject* World::GetObjectIn(int x, int y) const
{
	for (GameObject* obj : objects) {
		if (obj->InThisPoint(x, y)) {
			return obj;
		}
	}
	return nullptr;
}

World::~World()
{
	for (GameObject* obj : objects) {
		delete obj;
	}
}
