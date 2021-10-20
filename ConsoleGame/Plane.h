#pragma once

#include <vector>
#include <string>

#include "CharMatrix.h"


class Plane
{
public:
	Plane(size_t x, size_t y);
	void Clean();
	std::string ToString();
	void Render();
	void Insert(size_t x, size_t y, CharMatrix&& matrix);
	void HideCursor();

private:
	CharMatrix map;
	void MoveCursorTo(short x, short y);
};

