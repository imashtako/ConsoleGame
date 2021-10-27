#pragma once

class World;


class GameObject
{
public:
	bool virtual InThisPoint(int x, int y) = 0;
	void virtual Update() {};
	void SetWorld(World* _world) { world = _world; }
protected:
	int x_pos;
	int y_pos;
	World* world = nullptr;
	GameObject(size_t x, size_t y) : x_pos(x), y_pos(y) {};
};

