#pragma once

#include <vector>
#include "GameObject.h"

class World
{
public:
	void AddObject(GameObject* obj);
	const std::vector<GameObject*> GetObjects();
	void Update();
	GameObject* GetObjectIn(int x, int y) const;
	~World();

private:
	std::vector<GameObject*> objects;
};

