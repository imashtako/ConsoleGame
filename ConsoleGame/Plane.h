#pragma once

#include <vector>
#include <string>

class Plane
{
public:
	const int x_size;
	const int y_size;
	std::vector<std::vector<char>> map;
	Plane(int x, int y);
	void Clean();
	std::string ToString();
	void Render();

private:
	void MoveCursorTo(int x, int y);
};

