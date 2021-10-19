#pragma once

#include <vector>
#include <string>

class CharMatrix
{
public:
	std::vector<std::vector<char>> matrix;
	size_t size_x;
	size_t size_y;
	CharMatrix(size_t x, size_t y);
	CharMatrix(const std::vector<std::string>& strings);
	std::vector<char>& operator[](int index);
};

