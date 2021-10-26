#pragma once

#include <vector>

#include "GameObject.h"

class World
{
public:
	void AddObject(GameObject* obj);
	const std::vector<GameObject*> GetObjects();

private:
	std::vector<GameObject*> objects;
};

