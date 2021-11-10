#pragma once

class World;


class GameObject
{
public:
	bool virtual InThisPoint(int x, int y);
	void virtual Update();
	void SetWorld(World* _world) { world = _world; }
protected:
	int x_pos;
	int y_pos;
	const size_t x_size;
	const size_t y_size;
	World* world = nullptr;
	GameObject(int x, int y, size_t _x_size, size_t _y_size);
	bool DownIsEmpty();
	bool UpIsEmpty();
	bool RightIsEmpty();
	bool LeftIsEmpty();
};

