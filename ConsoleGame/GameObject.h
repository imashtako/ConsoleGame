#pragma once
class GameObject
{
public:
	bool virtual InThisPoint(int x, int y) = 0;

protected:
	int x_pos;
	int y_pos;
	GameObject(size_t x, size_t y) : x_pos(x), y_pos(y) {};
};

